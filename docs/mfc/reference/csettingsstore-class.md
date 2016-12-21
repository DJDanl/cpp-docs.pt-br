---
title: "Classe de CSettingsStore | Microsoft Docs"
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
  - "CSettingsStore"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSettingsStore"
ms.assetid: 0ea181de-a13e-4b29-b560-7c43838223ff
caps.latest.revision: 29
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSettingsStore
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Envolve as funções da API do windows, fornecendo uma interface orientado a objetos que você usa para acessar o Registro.  
  
## Sintaxe  
  
```  
class CSettingsStore : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSettingsStore::CSettingsStore](../Topic/CSettingsStore::CSettingsStore.md)|Constrói um objeto de `CSettingsStore` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSettingsStore::Close](../Topic/CSettingsStore::Close.md)|Fecha a chave do Registro aberta.|  
|[CSettingsStore::CreateKey](../Topic/CSettingsStore::CreateKey.md)|Abre a chave especificada ou criar se ele não existir.|  
|[CSettingsStore::DeleteKey](../Topic/CSettingsStore::DeleteKey.md)|Exclui a chave especificada e todos os seus filhos.|  
|[CSettingsStore::DeleteValue](../Topic/CSettingsStore::DeleteValue.md)|Exclui o valor especificado de chave aberta.|  
|[CSettingsStore::Open](../Topic/CSettingsStore::Open.md)|Abre a chave especificada.|  
|[CSettingsStore::Read](../Topic/CSettingsStore::Read.md)|Recupera os dados para um valor de chave especificado.|  
|[CSettingsStore::Write](../Topic/CSettingsStore::Write.md)|Grava um valor no Registro sob a chave aberta.|  
  
## Comentários  
 As funções de membro `CreateKey` e `Open` são muito semelhantes.  Se a chave do Registro já existir, `CreateKey` e função de `Open` da mesma forma.  Em o entanto, se a chave do Registro não existir, `CreateKey` criá\-la\-á enquanto `Open` retornará um valor de erro.  
  
## Exemplo  
 O exemplo seguinte demonstra como usar Abrir e ler os métodos de `CSettingsStore` classe.  Este trecho de código é parte de [Exemplo de demonstração de dica de ferramenta](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_ToolTipDemo#1](../../mfc/reference/codesnippet/CPP/csettingsstore-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CSettingsStore](../../mfc/reference/csettingsstore-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxsettingsstore.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CWinAppEx](../../mfc/reference/cwinappex-class.md)