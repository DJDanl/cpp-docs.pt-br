---
title: "&lt;exceção&gt; (Visual C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- exception
- <exception>
dev_langs: C++
helpviewer_keywords:
- <exception> C++ XML tag
- exception C++ XML tag
ms.assetid: 24451e79-9b89-4b77-98fb-702c6516b818
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c07dde806938b38dd55a3258b3724b0937d5601d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ltexceptiongt-visual-c"></a>&lt;exceção&gt; (Visual C++)
A marca \<exception> permite que você especifique quais exceções podem ser lançadas. Essa marca é aplicada a uma definição de método.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
<exception cref="member">description</exception>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `member`  
 Uma referência a uma exceção que está disponível no ambiente de compilação atual. Usando as regras de pesquisa de nome, o compilador verifica se a exceção especificada existe e converte `member` para o nome canônico de elemento no XML de saída.  O compilador emite um aviso se ele não encontrar `member`.  
  
 Coloque o nome entre aspas simples ou duplas.  
  
 Para obter informações sobre como criar uma referência cref para um tipo genérico, consulte [ \<consulte>](../ide/see-visual-cpp.md).  
  
 `description`  
 Uma descrição.  
  
## <a name="remarks"></a>Comentários  
 Compile com [/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.  
  
 O compilador do Visual C++ tentará resolver referências cref em uma passagem pela comentários de documentação.  Portanto, se usar as regras de pesquisa do C++, um símbolo não é encontrado pelo compilador a referência será marcada como não resolvidos. Consulte [ \<seealso >](../ide/seealso-visual-cpp.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
  
```  
// xml_exception_tag.cpp  
// compile with: /clr /doc /LD  
// post-build command: xdcmake xml_exception_tag.dll  
using namespace System;  
  
/// Text for class EClass.  
public ref class EClass : public Exception {  
   // class definition ...  
};  
  
/// <exception cref="System.Exception">Thrown when... .</exception>  
public ref class TestClass {  
   void Test() {  
      try {  
      }  
      catch(EClass^) {  
      }  
   }  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Documentação XML](../ide/xml-documentation-visual-cpp.md)