---
title: "Classe de CSettingsStoreSP | Microsoft Docs"
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
  - "CSettingsStoreSP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSettingsStoreSP"
ms.assetid: bcd37f40-cfd4-4d17-a5ce-3bfabe995dcc
caps.latest.revision: 18
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSettingsStoreSP
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CSettingsStoreSP` é uma classe auxiliar que você pode usar para criar instâncias de [Classe de CSettingsStore](../../mfc/reference/csettingsstore-class.md).  
  
## Sintaxe  
  
```  
class CSettingsStoreSP  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSettingsStoreSP::CSettingsStoreSP](../Topic/CSettingsStoreSP::CSettingsStoreSP.md)|Constrói um objeto de `CSettingsStoreSP` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSettingsStoreSP::Create](../Topic/CSettingsStoreSP::Create.md)|Cria uma instância de uma classe que é derivada de `CSettingsStore`.|  
|[CSettingsStoreSP::SetRuntimeClass](../Topic/CSettingsStoreSP::SetRuntimeClass.md)|Define a classe de tempo de execução.  O método de `Create` usa a classe em tempo de execução para determinar qual classe de objetos para criar.|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|`m_dwUserData`|Dados de usuário personalizados que são armazenados no objeto de `CSettingsStoreSP` .  Você fornece esses dados no construtor do objeto de `CSettingsStoreSP` .|  
|`m_pRegistry`|`CSettingsStore`objeto derivado que o método de `Create` cria.|  
  
## Comentários  
 Você pode usar a classe de `CSettingsStoreSP` para redirecionar todas as operações de Registro MFC a outros locais, como um arquivo XML ou um banco de dados.  Para fazer isso, siga estas etapas:  
  
1.  Crie uma classe \(como `CMyStore`\) e derive\-a de `CSettingsStore`.  
  
2.  Use macros de [DECLARE\_DYNCREATE](../Topic/DECLARE_DYNCREATE.md) e de [IMPLEMENT\_DYNCREATE](../Topic/IMPLEMENT_DYNCREATE.md) com sua classe personalizada de `CSettingsStore` para permitir a criação dinâmica.  
  
3.  Substituir as funções virtuais e implementar as funções de `Read` e de `Write` em sua classe personalizada.  Implementar qualquer outra funcionalidade para ler e gravar dados para o local desejado.  
  
4.  Em seu aplicativo, chame `CSettingsStoreSP::SetRuntimeClass` e passar em um ponteiro para [Estrutura de CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) obtido de sua classe.  
  
 Sempre que a estrutura acessaria normalmente o Registro, agora criará uma instância dinamicamente sua classe personalizada e usá\-la\-á para ler ou gravar dados.  
  
 `CSettingsStoreSP::SetRuntimeClass` usa uma variável estática global.  Portanto, somente um armazenamento personalizado está disponível em vez.  
  
## Requisitos  
 **Cabeçalho:** afxsettingsstore.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CSettingsStore](../../mfc/reference/csettingsstore-class.md)