pipeline {
    agent {
        docker {
            image 'ubuntu:latest'
            args '-u root'
        }
    }

    environment {
        GTEST_COLOR = 'yes'
    }

    stages {
        stage('Setup Environment') {
            steps {
                sh '''
                    apt-get update
                    apt-get install -y cmake g++ libgtest-dev python3 python3-pip git
                    cd /usr/src/gtest
                    cmake CMakeLists.txt
                    make
                    cp lib/*.a /usr/lib
                    pip3 install pytest
                '''
            }
        }

        stage('Build') {
            steps {
                sh '''
                    mkdir -p build
                    cd build
                    cmake -DCMAKE_BUILD_TYPE=Debug ..
                    cmake --build .
                '''
            }
        }

        stage('Unit Tests') {
            steps {
                sh '''
                    cd build/tests
                    ./tictactoe_board_test
                '''
            }
        }

        stage('Integration Tests') {
            steps {
                sh '''
                    cd tests
                    python3 -m pytest integration_test.py -v
                '''
            }
        }
    }

    post {
        always {
            cleanWs()
        }
        success {
            echo 'Pipeline completed successfully!'
        }
        failure {
            echo 'Pipeline failed!'
        }
    }
}