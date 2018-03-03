---
title: "&lt;Consulte também&gt; (Visual C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- <seealso>
- seealso
dev_langs:
- C++
helpviewer_keywords:
- seealso C++ XML tag
- <seealso> C++ XML tag
ms.assetid: cb33d100-9c50-4485-8d0c-573429eff155
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2e1d50162989e5148cd0755afb48f4413ce51269
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ltseealsogt-visual-c"></a>&lt;Consulte também&gt; (Visual C++)
A marca \<seealso > permite especificar o texto que você quer que seja exibido na seção Ver também. Use [\<see>](../ide/see-visual-cpp.md) para especificar um link de dentro do texto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
<seealso cref="member"/>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `member`  
 Uma referência a um membro ou campo disponível para ser chamado do ambiente de compilação atual.  Coloque o nome entre aspas simples ou duplas.  
  
 O compilador verifica se o elemento de código fornecido existe e resolve `member` para o nome do elemento no XML de saída.  O compilador emite um aviso se ele não encontrar `member`.  
  
 Para obter informações sobre como criar uma referência cref para um tipo genérico, consulte [ \<consulte>](../ide/see-visual-cpp.md).  
  
## <a name="remarks"></a>Comentários  
 Compile com [/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.  
  
 Consulte [\<summary>](../ide/summary-visual-cpp.md) para obter um exemplo sobre o uso de \<seealso>.  
  
 O compilador do Visual C++ tentará resolver referências cref em uma passagem pela comentários de documentação.  Portanto, se usar as regras de pesquisa do C++, um símbolo não é encontrado pelo compilador a referência será marcada como não resolvidos.  
  
## <a name="example"></a>Exemplo  
 No exemplo a seguir, um símbolo não resolvido é referenciado em um cref. O comentário XML cref para B::Test será `<seealso cref="!:B::Test" />`, enquanto que a referência ao A::Test está bem formada `<seealso cref="M:A.Test" />`.  
  
```  
// xml_seealso_tag.cpp  
// compile with: /LD /clr /doc  
// post-build command: xdcmake xml_seealso_tag.dll  
  
/// Text for class A.  
public ref struct A {  
   /// <summary><seealso cref="A::Test"/>  
   /// <seealso cref="B::Test"/>  
   /// </summary>  
   void MyMethod(int Int1) {}  
  
   /// text  
   void Test() {}  
};  
  
/// Text for class B.  
public ref struct B {  
   void Test() {}  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Documentação XML](../ide/xml-documentation-visual-cpp.md)