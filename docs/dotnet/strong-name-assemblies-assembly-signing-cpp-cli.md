---
title: "Assemblies de nome forte (assinatura de assembly) (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - ".NET Framework [C++], assinatura de assembly"
  - "assemblies [C++]"
  - "assemblies [C++], assinatura"
  - "vinculador [C++], assinatura de assembly"
  - "assinando assemblies"
  - "assemblies de nomes fortes [C++]"
ms.assetid: c337cd3f-e5dd-4c6f-a1ad-437e85dba1cc
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assemblies de nome forte (assinatura de assembly) (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico discute como você pode assinar o assembly, geralmente chamado para que o assembly de um nome forte.  
  
## Comentários  
 Ao usar o Visual C\+\+, as opções do vinculador de uso assinar o assembly para evitar problemas relacionados a atributos de CLR para assinar o assembly:  
  
-   <xref:System.Reflection.AssemblyDelaySignAttribute>  
  
-   <xref:System.Reflection.AssemblyKeyFileAttribute>  
  
-   <xref:System.Reflection.AssemblyKeyNameAttribute>  
  
 As razões para usar os atributos incluem o fato de que o nome da chave é visível nos metadados do assembly, que podem representar um risco à segurança se o nome de arquivo inclui informações confidenciais.  Além disso, o processo de compilação usado pelo ambiente de desenvolvimento do Visual C\+\+ invalidará a chave com que o assembly foi assinado se você usar atributos de CLR para dar a um assembly um nome forte, e para executar em uma ferramenta de pós\-processamento como mt.exe no assembly.  
  
 Se você construir na linha de comando, opções do vinculador de uso assinar o assembly, e execute uma ferramenta de pós\-processamento \(como mt.exe\), você precisará o sinal novamente o assembly com sn.exe.  Como alternativa, você pode criar e para atrasar o sinal o assembly e depois ferramentas em execução após o processamento, concluir a assinatura.  
  
 Se você usa os atributos assinando ao criar o ambiente de desenvolvimento, você poderá com êxito para assinar o assembly chamar explicitamente sn.exe \([Sn.exe \(Ferramenta de Nome Forte\)](../Topic/Sn.exe%20\(Strong%20Name%20Tool\).md)\) em um evento de pós\-compilação.  Para obter mais informações, consulte [Especificando eventos de compilação](../ide/specifying-build-events.md).  O tempo de compilação pode ser menor se você usar atributos e um evento de pós\-compilação, comparado a usar opções do vinculador um.  
  
 Seguinte assinar o assembly de suporte de opções do vinculador:  
  
-   [\/DELAYSIGN \(assinar parcialmente um assembly\)](../build/reference/delaysign-partially-sign-an-assembly.md)  
  
-   [\/KEYFILE \(especificar chave ou par de chaves para assinar um assembly\)](../build/reference/keyfile-specify-key-or-key-pair-to-sign-an-assembly.md)  
  
-   [\/KEYCONTAINER \(especificar um contêiner de chave para assinar um assembly\)](../build/reference/keycontainer-specify-a-key-container-to-sign-an-assembly.md)  
  
 Para obter mais informações sobre assemblies fortes, consulte [Criando e usando assemblies de nomes fortes](../Topic/Creating%20and%20Using%20Strong-Named%20Assemblies.md).  
  
## Consulte também  
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)