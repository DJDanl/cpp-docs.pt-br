---
title: "/RELEASE (definir a soma de verifica&#231;&#227;o) | Microsoft Docs"
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
  - "/release"
  - "VC.Project.VCLinkerTool.SetChecksum"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /RELEASE"
  - "configuração de soma de verificação"
  - "opção de vinculador RELEASE"
  - "opção de vinculador -RELEASE"
ms.assetid: 93bcadf4-29ac-4824-914b-6997e3751d22
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /RELEASE (definir a soma de verifica&#231;&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/RELEASE  
```  
  
## Comentários  
 As opções definidas \/RELEASE da soma de verificação no cabeçalho de um arquivo .exe.  
  
 O sistema operacional requer a soma de verificação para drivers de dispositivo.  Definir a soma de verificação para versões de início dos drivers de dispositivo para garantir a compatibilidade com sistemas operacionais futuros.  
  
 A opção \/RELEASE é definida por padrão quando a opção de [\/SUBSYSTEM: NATIVO](../../build/reference/subsystem-specify-subsystem.md) é especificada.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Avançado** .  
  
4.  Modifique a propriedade de **Definir Soma de Verificação** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.SetChecksum%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)