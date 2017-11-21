---
title: "&lt;permissão&gt; (Visual C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- permission
- <permission>
dev_langs: C++
helpviewer_keywords:
- <permission> C++ XML tag
- permission C++ XML tag
ms.assetid: 537ee2bc-95bd-48e4-9ce6-3420c3da87f4
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 02a379b9856d2e8c7a764b3c8be49652a3f3d678
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ltpermissiongt-visual-c"></a>&lt;permissão&gt; (Visual C++)
A marca \<permissão > permite documentar o acesso de um membro. <xref:System.Security.PermissionSet>permite especificar o acesso a um membro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
<permission cref="member">description</permission>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `member`  
 Uma referência a um membro ou campo disponível para ser chamado do ambiente de compilação atual. O compilador verifica se o elemento de código fornecido existe e converte `member` no nome de elemento canônico no XML de saída.  Coloque o nome entre aspas simples ou duplas.  
  
 O compilador emite um aviso se ele não encontrar `member`.  
  
 Para obter informações sobre como criar uma referência cref para um tipo genérico, consulte [ \<consulte>](../ide/see-visual-cpp.md).  
  
 `description`  
 Uma descrição do acesso ao membro.  
  
## <a name="remarks"></a>Comentários  
 Compile com [/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.  
  
 O compilador do Visual C++ tentará resolver referências cref em uma passagem pela comentários de documentação.  Portanto, se usar as regras de pesquisa do C++, um símbolo não é encontrado pelo compilador a referência será marcada como não resolvidos. Consulte [ \<seealso >](../ide/seealso-visual-cpp.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
  
```  
// xml_permission_tag.cpp  
// compile with: /clr /doc /LD  
// post-build command: xdcmake xml_permission_tag.dll  
using namespace System;  
/// Text for class TestClass.  
public ref class TestClass {  
   /// <permission cref="System::Security::PermissionSet">Everyone can access this method.</permission>  
   void Test() {}  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Documentação XML](../ide/xml-documentation-visual-cpp.md)