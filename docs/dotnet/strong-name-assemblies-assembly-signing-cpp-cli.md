---
title: Assemblies de nome forte (assinatura de Assembly) (C + + CLI) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- assemblies [C++]
- signing assemblies
- .NET Framework [C++], assembly signing
- assemblies [C++], signing
- linker [C++], assembly signing
- strong-named assemblies [C++]
ms.assetid: c337cd3f-e5dd-4c6f-a1ad-437e85dba1cc
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 2099389131145838a70b579053c65698dbc3a857
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="strong-name-assemblies-assembly-signing-ccli"></a>Assemblies de nome forte (assinatura de assembly) (C++/CLI)
Este tópico discute como você pode assinar o assembly, conhecida como fornecendo o seu assembly um nome forte.  
  
## <a name="remarks"></a>Comentários  
 Ao usar o Visual C++, use opções do vinculador para assinar seu assembly para evitar problemas relacionados aos atributos CLR para a assinatura de assembly:  
  
-   <xref:System.Reflection.AssemblyDelaySignAttribute>  
  
-   <xref:System.Reflection.AssemblyKeyFileAttribute>  
  
-   <xref:System.Reflection.AssemblyKeyNameAttribute>  
  
 Motivos para não usar os atributos incluem o fato de que o nome da chave está visível nos metadados do assembly, que podem ser um risco à segurança se o nome do arquivo contém informações confidenciais. Além disso, o processo de compilação usado pelo ambiente de desenvolvimento do Visual C++ invalida a chave com a qual o assembly é assinado se você usa atributos CLR para dar um nome forte de um assembly e, em seguida, executar uma ferramenta de pós-processamento como mt.exe no assembly.  
  
 Se você compilar na linha de comando, use as opções do vinculador para assinar seu assembly e, em seguida, executar uma ferramenta de pós-processamento (como mt.exe), você precisará assinar novamente o assembly com sn.exe. Como alternativa, você pode criar e atrasar a assinatura de assembly e depois de executar ferramentas de pós-processamento, concluir a assinatura.  
  
 Se você usar os atributos de assinatura ao compilar no ambiente de desenvolvimento, você pode assinar o assembly com êxito ao chamar explicitamente sn.exe ([Sn.exe (ferramenta de nome forte)](/dotnet/framework/tools/sn-exe-strong-name-tool)) em um evento de pós-compilação. Para obter mais informações, consulte [especificando eventos de Build](../ide/specifying-build-events.md). Tempos de compilação podem ser menor se você usar atributos e um evento de pós-compilação, comparado a usar as opções do vinculador.  
  
 As seguintes opções do vinculador dão suporte a assinatura de assembly:  
  
-   [/DELAYSIGN (assinar parcialmente um Assembly)](../build/reference/delaysign-partially-sign-an-assembly.md)  
  
-   [/KEYFILE (especificar chave ou par de chaves para assinar um Assembly)](../build/reference/keyfile-specify-key-or-key-pair-to-sign-an-assembly.md)  
  
-   [/KEYCONTAINER (especificar um contêiner de chave para assinar um Assembly)](../build/reference/keycontainer-specify-a-key-container-to-sign-an-assembly.md)  
  
 Para obter mais informações sobre conjuntos de alta segurança, consulte [Creating and Using Strong-Named Assemblies](/dotnet/framework/app-domains/create-and-use-strong-named-assemblies).  
  
## <a name="see-also"></a>Consulte também  
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)