---
title: "/DELAY (configura&#231;&#245;es da importa&#231;&#227;o de carga com atraso) | Microsoft Docs"
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
  - "/delay"
  - "VC.Project.VCLinkerTool.DelayNoBind"
  - "VC.Project.VCLinkerTool.SupportUnloadOfDelayLoadedDLL"
  - "VC.Project.VCLinkerTool.DelayUnload"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /DELAY"
  - "opção de vinculador DELAY"
  - "opção de vinculador -DELAY"
  - "carregamento atrasado de DLLs, Opção /DELAY"
ms.assetid: 9334b332-cc58-4dae-b10f-a4c75972d50c
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /DELAY (configura&#231;&#245;es da importa&#231;&#227;o de carga com atraso)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/DELAY:UNLOAD  
/DELAY:NOBIND  
```  
  
## Comentários  
 A opção \/DELAY controla o [carregamento atrasado](../../build/reference/linker-support-for-delay-loaded-dlls.md) de DLLs:  
  
-   O qualificador UNLOAD pede para a função de ajuda de carregamento atrasado dar suporte ao descarregamento explícito da DLL.  A IAT \(tabela de endereço de importação\) é redefinida como forma original, invalidando ponteiros IAT e fazendo\-os serem substituídos.  
  
     Se você não selecionar UNLOAD, qualquer chamada para [FUnloadDelayLoadedDLL](../../build/reference/explicitly-unloading-a-delay-loaded-dll.md) falhará.  
  
-   O qualificador NOBIND pede para o vinculador não incluir uma IAT associável na imagem final.  O padrão é criar a IAT associável para DLLs carregadas com atraso.  A imagem resultante não pode ser associada estaticamente.  \(As imagens com IATs associáveis podem ser associadas estaticamente antes da execução.\) Consulte [\/BIND](../../build/reference/bind.md).  
  
     Se a DLL estiver associada, a função auxiliar tentará usar as informações associadas em vez de chamar [GetProcAddress](http://msdn.microsoft.com/library/windows/desktop/ms683212.aspx) em todas as importações mencionadas.  Se o carimbo de data\/hora ou o endereço preferido não corresponder aos da DLL carregada, a função auxiliar considerará que a IAT associada está desatualizada e continuará como se a IAT associada não existisse.  
  
     NOBIND aumenta a imagem do programa, mas pode agilizar o tempo de carregamento da DLL.  Se você jamais teve a intenção associar a DLL, NOBIND evitará a geração da IAT associada.  
  
 Para especificar DLLs para carregamento com atraso, use a opção [\/DELAYLOAD](../../build/reference/delayload-delay-load-import.md).  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter informações, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda **Propriedades de Configuração**, **Vinculador** e selecione **Avançado**.  
  
3.  Modifique a propriedade **DLL Carregada com Atraso**.  
  
### Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.DelayLoadDLLs%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)