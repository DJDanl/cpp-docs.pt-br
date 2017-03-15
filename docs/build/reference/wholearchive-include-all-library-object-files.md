---
title: "-WHOLEARCHIVE (incluir todos os arquivos de objeto de biblioteca) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "Assembly"
  - "C"
  - "C++"
ms.assetid: ee92d12f-18af-4602-9683-d6223be62ac9
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# / WHOLEARCHIVE (incluir todos os arquivos de objeto de biblioteca)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Força o vinculador a incluir todos os arquivos de objeto na biblioteca estática no executável vinculado.  
  
## Sintaxe  
  
```  
/WHOLEARCHIVE[:library]  
```  
  
## Comentários  
 A opção \/WHOLEARCHIVE força o vinculador a incluir todos os arquivos de objeto por meio de uma biblioteca estática especificada, ou se nenhuma biblioteca for especificada, de todas as bibliotecas estáticas especificadas para o LINK de comando. Para especificar a opção \/WHOLEARCHIVE para várias bibliotecas, você pode usar mais de uma opção \/WHOLEARCHIVE na linha de comando do vinculador. Por padrão, o vinculador inclui arquivos de objeto na saída vinculada somente se eles exportam símbolos referenciados por outros arquivos de objeto no executável. A opção \/WHOLEARCHIVE faz com que o vinculador tratar todos os arquivos de objeto arquivados em uma biblioteca estática, como se eles foram especificados individualmente na linha de comando do vinculador.  
  
 A opção \/WHOLEARCHIVE pode ser usada para exportar novamente todos os símbolos de uma biblioteca estática. Isso permite que você certifique\-se de que todos o código da biblioteca, recursos e metadados são incluídos quando você cria um componente de mais de uma biblioteca estática. Se você vir aviso LNK4264 quando você cria uma biblioteca estática que contém componentes de tempo de execução do Windows para exportação, use a opção de \/WHOLEARCHIVE durante a vinculação dessa biblioteca em outro aplicativo ou componente.  
  
### Para definir essa opção de vinculador no Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o **Propriedades de configuração** nó.  
  
3.  Expanda o **vinculador** nó.  
  
4.  Selecione o **linha de comando** página de propriedades.  
  
5.  Adicione a opção \/WHOLEARCHIVE para o **Opções adicionais** caixa de texto.  
  
 A opção \/WHOLEARCHIVE foi introduzida na atualização 2 do Visual Studio 2015.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)