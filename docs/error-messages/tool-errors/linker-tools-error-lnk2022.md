---
title: Ferramentas de vinculador LNK2022 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2022
dev_langs:
- C++
helpviewer_keywords:
- LNK2022
ms.assetid: d2128c73-dde3-4b8e-a9b2-0a153acefb3b
caps.latest.revision: 15
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 6f12c53d7dd1383ad8f994a713c7226ab038cb19
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="linker-tools-error-lnk2022"></a>Erro das Ferramentas de Vinculador LNK2022
Falha da operação de metadados (HRESULT): error_message  
  
 O vinculador detectou um erro durante a mesclagem de metadados. Os erros de metadados devem ser resolvidos para vincular com êxito.  
  
 Uma maneira para diagnosticar esse problema é executar **ildasm-tokens** nos arquivos de objeto para saber quais tipos de tokens listados em `error_message`e procure as diferenças.  Nos metadados, dois tipos diferentes com o mesmo nome não é válido, mesmo que o atributo LayoutType apenas seja diferente.  
  
 Um motivo para LNK2022 é quando existe um tipo (por exemplo, uma estrutura) em vários compilandos com o mesmo nome, mas com definições conflitantes e quando você compilar com [/clr](../../build/reference/clr-common-language-runtime-compilation.md).  Nesse caso, certifique-se de que o tipo tem uma definição de idêntica em todos os compilandos.  O nome de tipo é listado no `error_message`.  
  
 Outra causa possível para LNK2022 é quando o vinculador localiza um arquivo de metadados em um local diferente, que foi especificado para o compilador (com [#using](../../preprocessor/hash-using-directive-cpp.md) ). Certifique-se de que o arquivo de metadados (. dll ou. netmodule) está no mesmo local quando passados para o vinculador, como ele era quando ele foi passado para o compilador.  
  
 Ao criar um aplicativo ATL, o uso de [_ATL_MIXED](http://msdn.microsoft.com/Library/11b59a83-7098-43e2-9f7b-408299930966) é necessário em todos os compilandos, se ele é usado em pelo menos um.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir define um tipo vazio.  
  
```  
// LNK2022_a.cpp  
// compile with: /clr /c  
public ref class Test {};  
```  
  
## <a name="example"></a>Exemplo  
 Este exemplo mostra que não é possível vincular dois arquivos de código de origem que contêm tipos do mesmo nome, mas diferentes definições.  
  
 O exemplo a seguir gera LNK2022.  
  
```  
// LNK2022_b.cpp  
// compile with: LNK2022_a.cpp /clr /LD   
// LNK2022 expected  
public ref class Test {  
   void func() {}  
   int var;  
};  
```
