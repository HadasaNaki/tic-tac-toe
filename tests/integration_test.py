import subprocess
import pytest

def test_game_win():
    process = subprocess.Popen(['./tictactoe'],
                             stdin=subprocess.PIPE,
                             stdout=subprocess.PIPE,
                             stderr=subprocess.PIPE,
                             text=True)
    # Input sequence for a winning game
    inputs = "3\n0\n0\n1\n1\n2\n2\n"

    stdout, stderr = process.communicate(inputs)
    assert "Winner: Player 1" in stdout
    assert process.returncode == 0

def test_invalid_move():
    process = subprocess.Popen(['./tictactoe'],
                             stdin=subprocess.PIPE,
                             stdout=subprocess.PIPE,
                             stderr=subprocess.PIPE,
                             text=True)
    # Try invalid move then valid
    inputs = "3\n-1\n-1\n0\n0\n"
    stdout, stderr = process.communicate(inputs)
    assert "Invalid move" in stdout
    assert process.returncode == 0