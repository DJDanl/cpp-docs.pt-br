---
title: "/WINMDDELAYSIGN (Assina parcialmente um winmd) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.WINMDDelaySign"
dev_langs: 
  - "C++"
ms.assetid: 445cd602-62cb-400a-8e3a-4beb6572724d
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /WINMDDELAYSIGN (Assina parcialmente um winmd)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Habilita a assinatura parcial dos metadados de Tempo de Execução do Windows \(\) .winmd arquivo colocando a chave pública no arquivo.  
  
```  
  
/WINMDDELAYSIGN[:NO]  
  
```  
  
## Comentários  
 É semelhante à opção do vinculador de [\/DELAYSIGN](../../build/reference/delaysign-partially-sign-an-assembly.md) que é aplicada ao arquivo de .winmd.  Use **\/WINMDDELAYSIGN** se você quiser colocar apenas a chave pública no arquivo de .winmd.  Por padrão, o vinculador atua como se **\/WINMDDELAYSIGN:NO** tiver sido especificada; isto é, não assina o arquivo de winmd.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione a pasta do **Vinculador**.  
  
3.  Selecione a página de propriedades de **Metadados do Windows** .  
  
4.  Na caixa de listagem suspensa de **Sinal de atraso de metadados do Windows** , selecione a opção desejada.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)