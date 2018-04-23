#pragma once

/*
� VS2017 ���������� ��������� ������������ ������ ���������� � ������������ ��� std::experimental::
�� ��������� C++17 ��� ������ ���������� � ������������ ��� std::
��������, ���������� <filesystem> ��������� � std::experimental::filesystem, � �� � std::filesystem::
*/

namespace std { 
    // �� ������ ������ (���� � ������� ��� ������) ������ ������������ std::experimental::
    namespace experimental {};
    // ������������� ���������� std::experimental � std::
    using namespace experimental; 
}

// ������, ��������, ���������� <filesystem> ����� ���������� � std::filesystem::