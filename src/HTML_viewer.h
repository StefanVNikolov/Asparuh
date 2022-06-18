#include <fstream>
#include <stdio.h>
#include<vector>
#include<string>
#include "ChessBoard.h"
#include "structs.cpp"

using namespace std;

#pragma once
class HTML_viewer
{
  PieceSpecifications specs;
public:
	string generateHTML_file(ChessBoard board, vector <int> indeces_h)
	{
		int current_index_h = 0;
		int vector_size = indeces_h.size();

		string html_table, even_color, odd_color, highlighted_color;
		//Crate the table
		//Add table dimensions
		html_table += "<table style = <table style s= \"width: 100px; height: 50px; \">\n<tbody>\n";
		//Add color types
		even_color = "background-color: rgb(205, 123, 50);\">";
		odd_color = "background-color: rgb(167, 90, 88);\">";
		highlighted_color = "background-color: rgb(255, 255, 0);\">";
		bool color_type = true;

		//Taking the size of the chess board
		int board_size = board.returnGridSize();

		for (int current_y = 1; current_y <= board_size; current_y++)
		{
			//Creates a new row of cells
			html_table += "<tr>\n";

			for (int current_x = 1; current_x <= board_size; current_x++)
			{
				int current_index = (current_y - 1) * 8 + ((current_x-1) + 1);

				//Creating the cell
				string cell_html;
				cell_html += "<td style=\"width: 100px; height: 100px;";
				//Checking if the cell is even or odd -> color
				if (current_index == indeces_h[current_index_h])
				{
					cell_html += highlighted_color;
					if (current_index_h != vector_size - 1)
					{
						current_index_h += 1;
					}
				}
				else
				{
					cell_html += (color_type) ? even_color : odd_color;
					color_type = !color_type;
				}
				if (board.board[current_y - 1][current_x - 1].exists == true)
				{
					int type = board.board[current_y - 1][current_x - 1].type;
					int color = board.board[current_y - 1][current_x - 1].color;
					string piece_png_file;
					if (color == 0)
					{
						piece_png_file = specs.unicodeBlackChessPieces[type];
					}
					else
					{
						piece_png_file = specs.unicodeWhiteChessPieces[type];
					}
					
					cell_html += "<img src = \"ChessPieces/";
					cell_html += piece_png_file+ "\">";
				}
				cell_html += "<br></td>\n";

				//Adds the cell html
				html_table += cell_html;
			}
			//Ends the row of cells
			color_type = !color_type;
			html_table += "</tr>\n";
		}
		//Ends the table
		html_table += "</tbody>\n</table>\n";

		return html_table;
	}
	void createHTML_file(string content)
	{
		ofstream myfile;
		remove("ChessBoard.html");
		myfile.open("ChessBoard.html");
		myfile << "<!DOCTYPE html><html><head>" + content + "</head><body>"; //starting html
		myfile.close();
	}
};

