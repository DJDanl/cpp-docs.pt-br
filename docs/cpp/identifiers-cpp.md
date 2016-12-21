---
title: "Identificadores (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "nomes decorados"
  - "nomes, sobre nomes decorados decorados"
  - "identificadores de C++"
  - "espaço em branco, em identificadores C++"
  - "identificadores"
ms.assetid: 03a0dfb1-4530-4cdf-8295-5ea4dca4c1b8
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Identificadores (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um identificador é uma seqüência de caracteres usada para indicar um dos seguintes:  
  
-   Nome de objeto ou variável  
  
-   Classe, estrutura ou união nome  
  
-   Nome do tipo enumerado  
  
-   Membro de uma classe, estrutura, união ou enumeração  
  
-   Função ou função de membro de classe  
  
-   nome de TypeDef  
  
-   Nome de rótulo  
  
-   Nome da macro  
  
-   Parâmetro de macro  
  
 Os seguintes caracteres são permitidos como qualquer caractere de um identificador:  
  
```  
_ a b c d e f g h i j k l m  
n o p q r s t u v w x y z  
A B C D E F G H I J K L M  
N O P Q R S T U V W X Y Z  
```  
  
 Determinados intervalos de nomes de caracteres universais também são permitidos em um identificador.  Um nome de caracteres universais em um identificador não pode designar um caractere de controle ou um caractere no conjunto de caracteres de origem básico. Para obter mais informações, consulte [Conjuntos de caracteres](../cpp/character-sets2.md). Esses intervalos de número de ponto de código Unicode são permitidos nomes de caractere como universais para qualquer caractere em um identificador:  
  
-   00A8, 00AA, 00AD, 00AF, 00B2 00B5, 00B7 00BA, 00BC\-00BE C 00 00 0 D 6, 8\-00F6 00D, 00F8 00FF, 0100\-02FF, 0370 167F, 1681\-180D, 180F 1DBF, E 1E00\-1FFF, 200B \- 200D, 202A 202E, 203F\-2040, 2054, 2060\-206F, 2070\-20CF, 218F DE 2100, 2460\-24FF, 2776\-2793 2C 00\-2DFF, 2E80 2FFF, 3007 3004, 3021 302F, 3031 303F, 3040 D7FF, F900 FD3D, FD40 FDCF, FDF0 FE1F, FE30 FE44, FE47 FFFD, 10000 1FFFD, 20000 2FFFD, 30000 3FFFD, 4FFFD 40000, 5FFFD 50000, 60000 6FFFD, 70000 7FFFD, 80000 8FFFD, 90000 9FFFD, A0000 AFFFD, BFFFD B0000, C0000 CFFFD, D0000 DFFFD, E0000 EFFFD  
  
 Os seguintes caracteres são permitidos como qualquer caractere em um identificador, exceto o primeiro:  
  
```  
0 1 2 3 4 5 6 7 8 9  
```  
  
 Esses intervalos de número de ponto de código Unicode também são permitidos nomes de caractere como universais para qualquer caractere em um identificador, exceto o primeiro:  
  
-   0300\-036F 1DC0 1DFF, 20D 0\-20FF, FE20 FE2F  
  
 **Específico da Microsoft**  
  
 Somente os primeiros 2048 caracteres de identificadores do Microsoft C\+\+ são significativos. Nomes de tipos definidos pelo usuário são "decorados" pelo compilador para preservar informações de tipo. O nome resultante, incluindo as informações de tipo não pode ter mais de 2048 caracteres. \(Consulte [nomes decorados](../Topic/Decorated%20Names.md) para obter mais informações.\) Fatores que podem influenciar o tamanho de um identificador decorado são:  
  
-   Se o identificador denota um objeto do tipo definido pelo usuário ou um tipo derivado de um tipo definido pelo usuário.  
  
-   Se o identificador denota uma função ou um tipo derivado de uma função.  
  
-   O número de argumentos para uma função.  
  
 O símbolo de dólar `$` é um caractere identificador válido do Visual C\+\+. Visual C\+\+ também permite que você use os caracteres reais representados pelos intervalos permitidos de nomes de caracteres universais em identificadores. Para usar esses caracteres, você deve salvá\-lo usando um arquivo de codificação de página de código que inclui\-los.  Este exemplo mostra como dois caracteres estendidos e nomes de caracteres universais podem ser usados alternadamente em seu código.  
  
```  
// extended_identifier.cpp  
// In Visual Studio, use File, Advanced Save Options to set  
// the file encoding to Unicode codepage 1200  
struct テスト         // Japanese 'test'  
{  
    void トスト() {}  // Japanese 'toast'  
};  
  
int main() {  
    テスト \u30D1\u30F3;  // Japanese パン 'bread' in UCN form  
    パン.トスト();        // compiler recognizes UCN or literal form  
}  
```  
  
 O intervalo de caracteres permitidos em um identificador é menos restritivo quando compilar C \+ \+ \/ código CLI. Identificadores no código compilado usando \/clr devem seguir  [padrão ECMA\-335: Common Language Infrastructure \(CLI\)](http://www.ecma-international.org/publications/standards/Ecma-335.htm).  
  
 **FIM de específico da Microsoft**  
  
 O primeiro caractere de um identificador deve ser um caractere alfabético, maiúsculo ou minúsculo, ou um sublinhado \( **\_** \). Como identificadores C\+\+ diferenciam maiúsculas de minúsculas, `fileName` é diferente do `FileName`.  
  
 Identificadores não podem estar exatamente a mesma ortografia e caso como palavras\-chave. Identificadores que contêm palavras\-chave são aceitos. Por exemplo, `Pint` é um identificador legal, mesmo que ele contém `int`, que é uma palavra\-chave.  
  
 Uso de dois caracteres sublinhados sequenciais \( **\_** \) no início de um identificador ou um sublinhado à esquerda único seguido por uma letra maiúscula, é reservado para implementações de C\+\+ em todos os escopos. Você deve evitar usar um sublinhado à esquerda seguido por uma letra minúscula para nomes com escopo de arquivo devido a possíveis conflitos com identificadores reservados atuais ou futuros.  
  
## Consulte também  
 [Convenções lexicais](../cpp/lexical-conventions.md)