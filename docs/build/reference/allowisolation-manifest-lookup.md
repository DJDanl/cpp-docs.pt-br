---
title: "/ALLOWISOLATION (pesquisa de manifesto) | Microsoft Docs"
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
  - "/ALLOWISOLATION"
  - "VC.Project.VCLinkerTool.AllowIsolation"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /ALLOWISOLATION"
  - "opção de vinculador -ALLOWISOLATION"
ms.assetid: 6d41851e-b3c1-4bdf-beaa-031773089d6f
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /ALLOWISOLATION (pesquisa de manifesto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica o comportamento de pesquisa de manifesto.  
  
## Sintaxe  
  
```  
/ALLOWISOLATION[:NO]  
```  
  
## Comentários  
 **\/ALLOWISOLATION:NO** indica as dlls serão carregados como se não houvesse manifesto e faz com que o vinculador definir o bit de `IMAGE_DLLCHARACTERISTICS_NO_ISOLATION` no campo opcional de `DllCharacteristics` de cabeçalho.  
  
 **\/ALLOWISOLATION** faz com que o sistema operacional fazer pesquisas e carrega manifestas.  
  
 O padrão é **\/ALLOWISOLATION**.  
  
 Quando o isolamento é desabilitado para um executável, o carregador do windows não tentará encontrar um manifesto do aplicativo para o processo recém\-criado.  O novo processo não tiver um contexto padrão de ativação, mesmo se houver um manifesto no executável ou colocado no mesmo diretório que o executável com o nome *executable\-name***.exe.manifest**.  
  
 Para obter mais informações, consulte [Referência do arquivo de manifesto](http://msdn.microsoft.com/library/aa375632).  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o nó **Propriedades de Configuração**.  
  
3.  Expanda o nó **Vinculador**.  
  
4.  Selecione a página de propriedades de **Arquivo de Manifesto** .  
  
5.  Modifique a propriedade de **Permitir Isolamento** .  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)