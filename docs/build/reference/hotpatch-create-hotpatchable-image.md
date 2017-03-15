---
title: "/hotpatch (Criar imagem hotpatchable) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/hotpatch"
  - "VC.Project.VCCLCompilerTool.CreateHotpatchableImage"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "aplicação de patch sob demanda"
  - "Opção de compilador -hotpatch [C++]"
  - "Opção de compilador /hotpatch (C++)"
  - "aplicação de patch sob demanda"
ms.assetid: aad539b6-c053-4c78-8682-853d98327798
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /hotpatch (Criar imagem hotpatchable)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Prepara uma imagem para patch instantâneo.  
  
## Sintaxe  
  
```  
/hotpatch  
```  
  
## Comentários  
 Quando **\/hotpatch** é usado em uma compilação, o compilador garante que a primeira instrução de cada função tenha pelo menos dois bytes, que é necessária para o patch instantâneo.  
  
 Para concluir a preparação e criar uma imagem capaz de aplicar patches, depois de usar **\/hotpatch** para compilar, você deve usar [\/FUNCTIONPADMIN \(Criar imagem hotpatchable\)](../../build/reference/functionpadmin-create-hotpatchable-image.md) para vincular.  Quando você compila e vincula uma imagem usando uma invocação de cl.exe, **\/hotpatch** implica **\/functionpadmin**.  
  
 Como as instruções são sempre de dois bytes ou maiores na arquitetura de BRAÇO, e porque a compilação de x64 sempre será tratada como se **\/hotpatch** foi especificado, você não precisa especificar **\/hotpatch** quando você cria para os destinos; no entanto, você ainda deverá vincular usando **\/functionpadmin** para criar imagens hotpatchable para eles.  A opção de compilador **\/hotpatch** afeta somente a compilação do x86.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Selecione a pasta **C\/C\+\+**.  
  
3.  Selecione a página de propriedades **Linha de Comando** .  
  
4.  Adicione a opção de compilador à caixa **Opções Adicionais**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Orientação  
 Para obter mais informações sobre o gerenciamento de atualização, consulte "Guia segurança para o gerenciamento de atualização" em [http:\/\/www.microsoft.com\/technet\/security\/guidance\/PatchManagement.mspx](http://www.microsoft.com/technet/security/guidance/PatchManagement.mspx).  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)