---
title: '&lt;consulte&gt; (Visual C++) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- <see>
- see
dev_langs:
- C++
helpviewer_keywords:
- <see> C++ XML tag
- see C++ XML tag
ms.assetid: 20ef66f4-b278-45cf-8613-63919edf5720
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a03dd56320b948d47c765f253bf3e6b706ed2b56
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="ltseegt-visual-c"></a>&lt;consulte&gt; (Visual C++)
Use a marca \<see> para especificar um link de dentro do texto. Use [ \<seealso >](../ide/seealso-visual-cpp.md) para indicar o texto que você pode aparecer em uma seção Consulte também.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
<see cref="member"/>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `member`  
 Uma referência a um membro ou campo disponível para ser chamado do ambiente de compilação atual.  Coloque o nome entre aspas simples ou duplas.  
  
 O compilador verifica se o elemento de código fornecido existe e resolve `member` para o nome do elemento no XML de saída.  O compilador emite um aviso se ele não encontrar `member`.  
  
## <a name="remarks"></a>Comentários  
 Compile com [/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.  
  
 Consulte [ \<resumo >](../ide/summary-visual-cpp.md) para obter um exemplo de como usar \<consulte >.  
  
 O compilador do Visual C++ tentará resolver referências cref em uma passagem pela comentários de documentação.  Portanto, se usar as regras de pesquisa do C++, um símbolo não é encontrado pelo compilador a referência será marcada como não resolvidos. Consulte [ \<seealso >](../ide/seealso-visual-cpp.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como você pode fazer referência cref para um tipo genérico, de modo que o compilador resolverá a referência.  
  
```  
// xml_see_cref_example.cpp  
// compile with: /LD /clr /doc  
// the following cref shows how to specify the reference, such that,  
// the compiler will resolve the reference  
/// <see cref="C{T}">  
/// </see>  
ref class A {};  
  
// the following cref shows another way to specify the reference,   
// such that, the compiler will resolve the reference  
/// <see cref="C < T >"/>  
  
// the following cref shows how to hard-code the reference  
/// <see cref="T:C`1">  
/// </see>  
ref class B {};  
  
/// <see cref="A">  
/// </see>  
/// <typeparam name="T"></typeparam>  
generic<class T>  
ref class C {};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Documentação XML](../ide/xml-documentation-visual-cpp.md)