---
title: "Classe de CPictureHolder | Microsoft Docs"
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
  - "Picture"
  - "CPictureHolder"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "controles [MFC], O OLE"
  - "Classe de CPictureHolder"
  - "controles OLE, imagem"
  - "Propriedade de imagem"
ms.assetid: a4f59775-704a-41dd-b5bd-2e531c95127a
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CPictureHolder
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa uma propriedade de imagem, que permite ao usuário exibir uma imagem em seu controle.  
  
## Sintaxe  
  
```  
class CPictureHolder  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPictureHolder::CPictureHolder](../Topic/CPictureHolder::CPictureHolder.md)|Constrói um objeto de `CPictureHolder` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPictureHolder::CreateEmpty](../Topic/CPictureHolder::CreateEmpty.md)|Cria um objeto vazio de `CPictureHolder` .|  
|[CPictureHolder::CreateFromBitmap](../Topic/CPictureHolder::CreateFromBitmap.md)|Cria um objeto de `CPictureHolder` de um bitmap.|  
|[CPictureHolder::CreateFromIcon](../Topic/CPictureHolder::CreateFromIcon.md)|Cria um objeto de `CPictureHolder` de um ícone.|  
|[CPictureHolder::CreateFromMetafile](../Topic/CPictureHolder::CreateFromMetafile.md)|Cria um objeto de `CPictureHolder` de meta\-arquivo.|  
|[CPictureHolder::GetDisplayString](../Topic/CPictureHolder::GetDisplayString.md)|Retorna a cadeia de caracteres exibida no navegador de propriedade do contêiner do controle.|  
|[CPictureHolder::GetPictureDispatch](../Topic/CPictureHolder::GetPictureDispatch.md)|Retorna a interface de `IDispatch` do objeto de `CPictureHolder` .|  
|[CPictureHolder::GetType](../Topic/CPictureHolder::GetType.md)|Informa se o objeto de `CPictureHolder` é um bitmap, meta\-arquivo, ou um ícone.|  
|[CPictureHolder::Render](../Topic/CPictureHolder::Render.md)|Processa a imagem.|  
|[CPictureHolder::SetPictureDispatch](../Topic/CPictureHolder::SetPictureDispatch.md)|Define a interface de `IDispatch` do objeto de `CPictureHolder` .|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPictureHolder::m\_pPict](../Topic/CPictureHolder::m_pPict.md)|Um ponteiro para um objeto de imagem.|  
  
## Comentários  
 `CPictureHolder` não tem uma classe base.  
  
 Com a propriedade conservada em estoque de imagem, o desenvolvedor pode especificar um bitmap, um ícone, ou meta\-arquivo para exibição.  
  
 Para obter informações sobre como criar propriedades personalizadas de imagem, consulte o artigo [Controles ActiveX MFC: usando imagens em um controle ActiveX](../../mfc/mfc-activex-controls-using-pictures-in-an-activex-control.md).  
  
## Hierarquia de herança  
 `CPictureHolder`  
  
## Requisitos  
 **Cabeçalho:** afxctl.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CFontHolder](../../mfc/reference/cfontholder-class.md)