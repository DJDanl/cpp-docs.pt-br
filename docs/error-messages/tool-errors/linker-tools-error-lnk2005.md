---
title: Ferramentas de vinculador LNK2005 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2005
dev_langs:
- C++
helpviewer_keywords:
- LNK2005
ms.assetid: d9587adc-68be-425c-8a30-15dbc86717a4
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 4ac033535632e94a365aa8dafd849f2ab28a3af7
ms.openlocfilehash: bf93f364b3dc7156a62eb1c474177eb7b85c7827
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk2005"></a>Erro das Ferramentas de Vinculador LNK2005
símbolo já definido no objeto  
  
O `symbol` determinado, exibido na sua forma decorada, foi definido por multiplicação.  
  
Para obter mais informações, consulte os artigos da Base de Conhecimento:  
  
-   [Um erro LNK2005 ocorre quando as bibliotecas CRT e MFC estão vinculadas na ordem errada no Visual C++](https://support.microsoft.com/kb/148652)  
  
-   [CORREÇÃO: Exclusão sobrecarregado Global operador causa LNK2005](https://support.microsoft.com/kb/140440)  
  
-   [Você recebe LNK2005 erros quando você compila um projeto executável (.exe) do ATL no Visual C++](https://support.microsoft.com/kb/184235).  
  
Esse erro é seguido por um erro fatal [LNK1169](../../error-messages/tool-errors/linker-tools-error-lnk1169.md).  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Combinação de bibliotecas estáticas e dinâmicas ao usar também [/clr](../../build/reference/clr-common-language-runtime-compilation.md).  
  
2.  O símbolo é uma função empacotada (criada compilando com [/Gy](../../build/reference/gy-enable-function-level-linking.md)) e foi incluído em mais de um arquivo, mas foi alterado entre compilações. Recompile todos os arquivos que incluem `symbol`.  
  
3.  O símbolo é definido de maneira diferente em dois objetos do membro em bibliotecas diferentes e os dois objetos do membro foram usados.  
  
4.  Um absoluto é definido duas vezes, com um valor diferente em cada definição.  
  
5.  Um arquivo de cabeçalho declarado e uma variável definida. As possíveis soluções incluem:  
  
    -   Declarar a variável em .h: `extern BOOL MyBool;` e atribuí-la a um arquivo .c ou .cpp: `BOOL MyBool = FALSE;`.  
  
    -   Declarar a variável [estático](../../cpp/storage-classes-cpp.md#static).  
  
    -   Declarar a variável [selectany](../../cpp/selectany.md).  
  
6.  Se uuid.lib for usado em combinação com outros arquivos .lib que definam GUIDs (por exemplo, oledb.lib e adsiid.lib). Por exemplo:  
  
    ```  
    oledb.lib(oledb_i.obj) : error LNK2005: _IID_ITransactionObject  
    already defined in uuid.lib(go7.obj)  
    ```  
  
     Para corrigir, adicione [/FORCE:MULTIPLE](../../build/reference/force-force-file-output.md) às opções de linha de comando do vinculador e verifique se UUID é a primeira biblioteca mencionada.
