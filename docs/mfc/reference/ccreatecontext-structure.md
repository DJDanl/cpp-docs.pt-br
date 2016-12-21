---
title: "Estrutura de CCreateContext | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CCreateContext"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura de CCreateContext"
ms.assetid: 337a0e44-d910-49a8-afc0-c7207666a9dc
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura de CCreateContext
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura usa a estrutura de `CCreateContext` quando cria as janelas e as exibições de quadro chave que estão associados com um documento.  
  
## Sintaxe  
  
```  
struct CCreateContext  
```  
  
## Comentários  
 `CCreateContext` é uma estrutura e não tem uma classe base.  
  
 Quando você cria uma janela, os valores em esta estrutura fornecem informações usadas para conectar os componentes de um documento para a exibição dos dados.  Você só precisa usar `CCreateContext` se você está substituindo partes do processo de criação.  
  
 Uma estrutura de `CCreateContext` contém ponteiros para o documento, a janela de quadro chave, a exibição, e o modelo do documento.  Também contém um ponteiro para `CRuntimeClass` que identifica o tipo de exibição para criar.  Informações de classe em tempo de execução e o ponteiro do documento atual é usado para criar dinamicamente um novo modo de exibição.  A tabela a seguir sugere como e quando cada membro de `CCreateContext` pode ser usado:  
  
|Membro|Tipo|o que é para|  
|------------|----------|------------------|  
|`m_pNewViewClass`|`CRuntimeClass*`|`CRuntimeClass` de exibição para criar.|  
|`m_pCurrentDoc`|`CDocument*`|O documento existente a ser associado com a nova exibição.|  
|`m_pNewDocTemplate`|`CDocTemplate*`|O modelo do documento associado com a criação de uma nova janela do quadro MDI.|  
|`m_pLastView`|`CView*`|A exibição original em que as visualizações adicionais são modeladas, como na criação de exibição da janela do separador ou na criação de uma segunda exibição em um documento.|  
|`m_pCurrentFrame`|`CFrameWnd*`|A janela do quadro em que as janelas adicionais de quadro são modeladas, como na criação de uma segunda janela do quadro em um documento.|  
  
 Quando um modelo de documento cria um documento e seus componentes associados, valida informações armazenadas na estrutura de `CCreateContext` .  Por exemplo, uma exibição não deve ser criada para um documento inexistente.  
  
> [!NOTE]
>  Todos os ponteiros em `CCreateContext` são opcionais e podem ser `NULL` se não especificado ou não.  
  
 `CCreateContext` é usado pelas funções de membro listadas em “consulta também.” Consulte as descrições de essas funções para informações específicas se você pretende substituir as.  
  
 Aqui estão algumas diretrizes gerais:  
  
-   Quando passado como um argumento para a criação da janela, como em `CWnd::Create`, `CFrameWnd::Create`, e `CFrameWnd::LoadFrame`, o contexto de design especifica o que a nova janela deve ser conectados.  Para a maioria do windows, a estrutura inteira é opcional e um ponteiro de `NULL` pode ser passado.  
  
-   Para funções de membro substituível, como `CFrameWnd::OnCreateClient`, o argumento de `CCreateContext` é opcional.  
  
-   Para as funções de membro envolvidas na criação de exibição, você deve fornecer informações suficientes para modo design.  Por exemplo, para a primeira exibição em uma janela do separador, você deve fornecer informações de classe de exibição e o documento atual.  
  
 Geralmente, se você usar as opções de estrutura, você pode ignorar `CCreateContext`.  Se você tentar alterações mais avançados, o código\-fonte da biblioteca de classe de base dos programas do Microsoft ou exemplo, tais como VIEWEX, guiá\-lo\-á.  Se você esquece um parâmetro obrigatório, uma declaração de estrutura dir\-lhe\-á o que você tiver esquecido.  
  
 Para obter mais informações sobre `CCreateContext`, consulte o exemplo [VIEWEX](../../top/visual-cpp-samples.md)MFC.  
  
## Requisitos  
 **Cabeçalho:** afxext.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [CFrameWnd::Create](../Topic/CFrameWnd::Create.md)   
 [CFrameWnd::LoadFrame](../Topic/CFrameWnd::LoadFrame.md)   
 [CFrameWnd::OnCreateClient](../Topic/CFrameWnd::OnCreateClient.md)   
 [CSplitterWnd::Create](../Topic/CSplitterWnd::Create.md)   
 [CSplitterWnd::CreateView](../Topic/CSplitterWnd::CreateView.md)   
 [CWnd::Create](../Topic/CWnd::Create.md)