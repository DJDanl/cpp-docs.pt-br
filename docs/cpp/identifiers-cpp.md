---
title: Identificadores (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- decorated names
- decorated names, about decorated names
- identifiers, C++
- white space, in C++ identifiers
- identifiers [C++]
ms.assetid: 03a0dfb1-4530-4cdf-8295-5ea4dca4c1b8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2d112e7ca192e56ede21d06e7ff17a775d661d01
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39405224"
---
# <a name="identifiers-c"></a>Identificadores (C++)
Um identificador é uma sequência de caracteres usados para denotar:  
  
-   Nome de objeto ou variável  
  
-   Nome de classe, estrutura ou união  
  
-   Nome do tipo enumerado  
  
-   Membro de uma classe, estrutura, união ou enumeração  
  
-   Função ou função de membro de classe  
  
-   Nome typedef  
  
-   Nome do rótulo  
  
-   Nome da macro  
  
-   Parâmetro da macro  
  
 Os seguintes caracteres são permitidos como qualquer caractere de um identificador:  
  
```  
_ a b c d e f g h i j k l m  
n o p q r s t u v w x y z  
A B C D E F G H I J K L M  
N O P Q R S T U V W X Y Z  
```  
  
 Determinados intervalos de nomes de caracteres universais também são permitidos em um identificador.  Um nome de caractere universal em um identificador não pode designar um caractere de controle ou um caractere no conjunto de caracteres de origem básicos. Para obter mais informações, consulte [conjuntos de caracteres](../cpp/character-sets.md). Esses intervalos de número de ponto de código Unicode são permitidos nomes de caracteres como universais para qualquer caractere em um identificador:  
  
-   00A8, 00AA, 00AD, 00AF, 00B2 00B5, 00B7 00BA, 00BC-00BE C 00 00 0 D 6, 8-00F6 D 00, 00F8 00FF, 0100-02FF, 0370 167F, 180 1681 D, 180F 1DBF, E 1E00-1FFF, 200B - 200D, 202A 202E, 203F-2040, 2054, 2060-206F, 2070-20CF, 218F DE 2100, 2460-24FF, 2776-2793 2C 00-2DFF, 2E80 2FFF, 3004 3007, 3021 302F, 3031 303F, 3040-D7FF F900 FD3D, FD40 FDCF, FDF0 FE1F, FE30 FE44, FE47 FFFD, 10000 1FFFD, 20000 2FFFD, 3FFFD 30000, 40000 4FFFD, 5FFFD 50000, 60000 6FFFD, 70000 7FFFD, 80000 8FFFD, 90000-9FFFD, A0000-AFFFD B0000-BFFFD, C0000-CFFFD D0000-DFFFD, E0000 EFFFD  
  
 Os seguintes caracteres são permitidos como qualquer caractere em um identificador, exceto o primeiro:  
  
```  
0 1 2 3 4 5 6 7 8 9  
```  
  
 Esses intervalos de número de ponto de código Unicode também são permitidos nomes de caracteres como universais para qualquer caractere em um identificador, exceto o primeiro:  
  
-   0300-036F 1DC0 1DFF, D 20 0-20FF, FE20 FE2F  
  
 **Seção específica da Microsoft**  
  
 Somente os 2048 primeiros caracteres de identificadores do Microsoft C++ são significativos. Os nomes de tipos definidos pelo usuário são "decorados" pelo compilador para preservar informações de tipo. O nome resultante, incluindo as informações de tipo, não pode ter mais de 2048 caracteres. (Consulte [nomes decorados](../build/reference/decorated-names.md) para obter mais informações.) Os fatores que podem influenciar o tamanho de um identificador decorado são:  
  
-   Se o identificador denota um objeto de tipo definido pelo usuário ou um tipo derivado de um tipo definido pelo usuário.  
  
-   Se o identificador denota uma função ou um tipo derivado de uma função.  
  
-   O número de argumentos para uma função.  
  
 O sinal de cifrão `$` é um identificador válido de caractere no Visual C++. Visual C++ também permite que você use os caracteres reais representados pelos intervalos permitidos de nomes de caracteres universais em identificadores. Para usar esses caracteres, você deve salvar o arquivo usando um arquivo de codificação de página de código que inclui-los.  Este exemplo mostra como ambos os caracteres estendidos e nomes de caracteres universais podem ser usados alternadamente em seu código.  
  
```cpp  
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
  
 O intervalo de caracteres permitido em um identificador é menos restritivo quando compilando c++ /CLI código CLI. Identificadores no código compilado usando /clr devem seguir [Standard ECMA-335: Common Language Infrastructure (CLI)](http://www.ecma-international.org/publications/standards/Ecma-335.htm).  
  
 **Fim da seção específica da Microsoft**  
  
 O primeiro caractere de um identificador deve ser um caractere alfabético, maiusculo ou minúsculo, ou um sublinhado ( **_** ). Como os identificadores C++ diferenciam maiúsculas de minúsculas, `fileName` é diferente de `FileName`.  
  
 Os identificadores não podem ter exatamente a mesma grafia e caixa (maiúscula ou minúscula) que as palavras-chave. Os identificadores que contêm palavras-chave são aceitos. Por exemplo, `Pint` é um identificador legal, mesmo que ele contenha **int**, que é uma palavra-chave.  
  
 Uso de dois caracteres sublinhados sequenciais ( **_** ) no início de um identificador ou um único sublinhado à esquerda seguido por uma letra maiuscula, é reservado para implementações de C++ em todos os escopos. Você deve evitar o uso de um sublinhado inicial seguido por uma letra minúscula para nomes com o escopo de arquivo por causa de possíveis conflitos com identificadores reservados atuais ou futuros.  
  
## <a name="see-also"></a>Consulte também  
 [Convenções lexicais](../cpp/lexical-conventions.md)