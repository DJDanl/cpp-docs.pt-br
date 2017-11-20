---
title: Nomes decorados | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- decorated names, definition
- name decoration [C++]
- names [C++], decorated
ms.assetid: a4e9ae8e-b239-4454-b401-4102793cb344
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 1db1d851e72bcce893f5e49b83b95ebf3366f15a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="decorated-names"></a>Nomes decorados
Funções, dados e objetos em programas C e C++ são representados internamente por seus nomes decorados. Um *decorado nome* é uma cadeia de caracteres codificada criada pelo compilador durante a compilação de uma definição de função, de dados ou de objeto. Registra as convenções de chamada, tipos, parâmetros de função e outras informações junto com o nome. Este decoração do nome, também conhecida como *desconfiguração do nome*, ajuda o vinculador a encontrar as funções corretas e os objetos ao vincular um executável.  
  
 As convenções de nomenclatura decoradas foram alterados em várias versões do Visual C++ e também podem ser diferentes em arquiteturas de destino diferente. Para vincular corretamente com arquivos de origem criados usando o Visual C++, C e C++ DLLs e bibliotecas deve ser compilada usando o mesmo conjunto de ferramentas do compilador, sinalizadores e arquitetura de destino.  
  
 **Conteúdo**  
  
-   [Usando nomes decorados](#Using)  
  
-   [Formato de C++ de decorado nome](#Format)  
  
-   [Formato de um C decorado nome](#FormatC)  
  
-   [Nomes de exibição decorado](#Viewing)  
  
-   [Nomes de exibição não decorado](#Undecorated)  
  
##  <a name="Using"></a>Usando nomes decorados  
 Normalmente, você não precisa saber o nome decorado escrever código que compila e links com êxito. Nomes decorados são um detalhe de implementação interno para o compilador e vinculador. As ferramentas geralmente podem lidar com o nome em sua forma não decorado. No entanto, um nome decorado, às vezes, é necessário quando você especificar um nome de função para o vinculador e outras ferramentas. Por exemplo, de acordo com funções sobrecarregadas do C++, membros de namespaces, construtores de classe, destruidores e funções de membro especial, você deve especificar o nome decorado. Para obter detalhes sobre os sinalizadores de opção e outras situações que exijam nomes decorados, consulte a documentação para as ferramentas e opções que você está usando.  
  
 Se você alterar o nome da função, classe, convenção de chamada, tipo de retorno ou qualquer parâmetro, o nome decorado também será alterado. Nesse caso, você deverá obter o novo nome decorado e usá-lo em qualquer lugar que do nome decorado for especificado.  
  
 Decoração do nome também é importante ao vincular ao código escrito em outras linguagens de programação ou usando outros compiladores. Compiladores diferentes usam convenções de decoração de nome diferente. Quando o executável vincula ao código escrito em outra linguagem, deve ter especial cuidado para corresponder aos nomes exportados e importados e convenções de chamada. Código de linguagem assembly deve usar os nomes de Visual C++ decorado e convenções de chamada para vincular ao código-fonte gravado com Visual C++.  
  
##  <a name="Format"></a>Formato de C++ de decorado nome  
 Um nome decorado para uma função C++ contém as seguintes informações:  
  
-   O nome da função.  
  
-   A classe que a função é um membro, se é uma função de membro. Isso pode incluir a classe que inclui a classe que contém a função e assim por diante.  
  
-   O namespace a função pertence, se ele fizer parte de um namespace.  
  
-   Os tipos de parâmetros de função.  
  
-   A convenção de chamada.  
  
-   O tipo de retorno da função.  
  
 Os nomes de função e de classe são codificados no nome decorado. O restante do nome decorado é um código que tem um significado interno somente para o compilador e vinculador. A seguir estão exemplos de nomes de C++ não decorados e realçados.  
  
|Nome não decorado|Nome decorado|  
|----------------------|--------------------|  
|`int a(char){int i=3;return i;};`|`?a@@YAHD@Z`|  
|`void __stdcall b::c(float){};`|`?c@b@@AAGXM@Z`|  
  
##  <a name="FormatC"></a>Formato de um C decorado nome  
 O formulário de decoração para uma função C depende a convenção de chamada usada na sua declaração, conforme mostrado na tabela a seguir. Isso também é o formato de decoração que é usado quando o código C++ é declarado para ter `extern "C"` vinculação. A convenção de chamada padrão é `__cdecl`. Observe que em um ambiente de 64 bits, funções não são decoradas.  
  
|Convenção de chamada|Decoração|  
|------------------------|----------------|  
|`__cdecl`|À esquerda de sublinhado (**_**)|  
|`__stdcall`|À esquerda de sublinhado (**_**) e à direita arroba (@) seguido pelo número de bytes na lista de parâmetros em decimal|  
|`__fastcall`|À esquerda e à direita sinais de arroba (@) seguido por um número decimal que representa o número de bytes na lista de parâmetros|  
|`__vectorcall`|Direita dois sinais de @ (@) seguido por um número decimal de bytes na lista de parâmetros|  
  
##  <a name="Viewing"></a>Nomes de exibição decorado  
 Você pode obter o formulário decorado de um nome de símbolo depois que você compilar o arquivo de origem que contém os dados, o objeto, ou a definição de função ou o protótipo. Para examinar nomes decorados em seu programa, você pode usar um dos seguintes métodos:  
  
-   #### <a name="to-use-a-listing-to-view-decorated-names"></a>Para usar uma lista para exibir nomes decorados  
  
    1.  Gerar uma lista ao compilar o arquivo de origem que contém os dados, o objeto, ou a definição de função ou o protótipo com o [listando tipo de arquivo](../../build/reference/fa-fa-listing-file.md) opção de compilador definida para o Assembly com o código-fonte (**/FAs**).  
  
         Por exemplo, digite `cl /c /FAs example.cpp` em um prompt de comando do desenvolvedor para gerar um arquivo de listagem, example.asm.  
  
    2.  No arquivo de listagem resultante, localize a linha que começa com o público e termina um ponto e vírgula seguido do nome de dados ou função não decorado. O símbolo entre o ponto e vírgula e o público é o nome decorado.  
  
-   #### <a name="to-use-dumpbin-to-view-decorated-names"></a>Para usar DUMPBIN para exibir nomes decorados  
  
    1.  Para ver os símbolos exportados em um arquivo. obj ou. lib, digite `dumpbin /symbols` `objfile` em um prompt de comando do desenvolvedor.  
  
    2.  Para localizar o formulário decorado do símbolo, procure o nome não decorado entre parênteses. O nome decorado está na mesma linha, depois de um pipe (&#124;) de caractere e antes do nome não decorado.  
  
##  <a name="Undecorated"></a>Nomes de exibição não decorado  
 Você pode usar undname.exe para converter um nome decorado em sua forma não decorada. Este exemplo mostra como isso funciona:  
  
```  
C:\>undname ?func1@a@@AAEXH@Z  
Microsoft (R) C++ Name Undecorator  
Copyright (C) Microsoft Corporation. All rights reserved.  
  
Undecoration of :- "?func1@a@@AAEXH@Z"  
is :- "private: void __thiscall a::func1(int)"  
```  
  
## <a name="see-also"></a>Consulte também  
 [Ferramentas de compilação do C/C++](../../build/reference/c-cpp-build-tools.md)   
 [Usando extern para especificar a ligação](../../cpp/using-extern-to-specify-linkage.md)