---
title: '&lt;Consulte também&gt; (Visual C++) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- <seealso>
- seealso
dev_langs:
- C++
helpviewer_keywords:
- seealso C++ XML tag
- <seealso> C++ XML tag
ms.assetid: cb33d100-9c50-4485-8d0c-573429eff155
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6a726a2fa1694fd346a6632fdc5e40bd53547fc8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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