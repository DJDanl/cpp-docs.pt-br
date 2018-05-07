---
title: Estrutura de CCreateContext | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CCreateContext
dev_langs:
- C++
helpviewer_keywords:
- CCreateContext structure [MFC]
ms.assetid: 337a0e44-d910-49a8-afc0-c7207666a9dc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: af6e81b9215aa6e7bc9e5f294a1d95aee4b51321
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="ccreatecontext-structure"></a>Estrutura CCreateContext
A estrutura usa o `CCreateContext` estrutura quando ele cria as janelas de quadro e exibições que estão associadas um documento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct CCreateContext  
```  
  
## <a name="remarks"></a>Comentários  
 `CCreateContext` é uma estrutura e não tem uma classe base.  
  
 Quando você cria uma janela, os valores nessa estrutura fornecem as informações usadas para conectar os componentes de um documento para o modo de exibição de seus dados. Você só precisa usar `CCreateContext` se você está substituindo as partes do processo de criação.  
  
 Um `CCreateContext` estrutura contém ponteiros para o documento, a janela do quadro, o modo de exibição e o modelo de documento. Ele também contém um ponteiro para um `CRuntimeClass` que identifica o tipo de exibição para criar. As informações de classe de tempo de execução e o ponteiro do documento atual são usados para criar uma nova exibição dinamicamente. A tabela a seguir sugere como e quando cada `CCreateContext` membro pode ser usado:  
  
|Membro|Tipo|O que é para|  
|------------|----------|--------------------|  
|`m_pNewViewClass`|`CRuntimeClass*`|`CRuntimeClass` da nova exibição para criar.|  
|`m_pCurrentDoc`|`CDocument*`|O documento existente a ser associado com a nova exibição.|  
|`m_pNewDocTemplate`|`CDocTemplate*`|O modelo de documento associado à criação de uma nova janela de quadro MDI.|  
|`m_pLastView`|`CView*`|A exibição original no qual são modeladas exibições adicionais, como a criação de modos de exibição de janela separadora ou a criação de um segundo modo de exibição em um documento.|  
|`m_pCurrentFrame`|`CFrameWnd*`|A janela do quadro no qual são modeladas janelas com moldura adicionais, como a criação de uma segunda janela do quadro de um documento.|  
  
 Quando um modelo de documento cria um documento e seus componentes associados, ele valida as informações armazenadas no `CCreateContext` estrutura. Por exemplo, um modo de exibição não deve ser criado para um documento que não existe.  
  
> [!NOTE]
>  Todos os ponteiros em `CCreateContext` são opcionais e podem ser `NULL` se não especificado ou desconhecido.  
  
 `CCreateContext` é usado pelas funções de membro listadas em "Consulte também". Consulte as descrições dessas funções para obter informações específicas, se você planeja substituí-los.  
  
 Aqui estão algumas diretrizes gerais:  
  
-   Quando passado como um argumento para a criação de janela, como `CWnd::Create`, `CFrameWnd::Create`, e `CFrameWnd::LoadFrame`, o contexto de criar Especifica que a nova janela deve estar conectada. Para a maioria das janelas, toda a estrutura é opcional e um `NULL` ponteiro pode ser passado.  
  
-   Para funções de membro substituível, como `CFrameWnd::OnCreateClient`, o `CCreateContext` argumento é opcional.  
  
-   Para funções de membro envolvidas na exibição criação, você deve fornecer informações suficientes para criar o modo de exibição. Por exemplo, para a primeira exibição em uma janela separadora, você deve fornecer as informações de classe de exibição e o documento atual.  
  
 Em geral, se você usar os padrões do framework, você pode ignorar `CCreateContext`. Se você tentar modificações mais avançadas, o código-fonte biblioteca Microsoft Foundation Class ou programas de exemplo, como VIEWEX, vai guiá-lo. Se você esquecer um parâmetro obrigatório, uma declaração de estrutura informará o que você esqueceu.  
  
 Para obter mais informações sobre `CCreateContext`, consulte o exemplo MFC [VIEWEX](../../visual-cpp-samples.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [CFrameWnd::Create](../../mfc/reference/cframewnd-class.md#create)   
 [CFrameWnd::LoadFrame](../../mfc/reference/cframewnd-class.md#loadframe)   
 [CFrameWnd::OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient)   
 [CSplitterWnd::Create](../../mfc/reference/csplitterwnd-class.md#create)   
 [CSplitterWnd::CreateView](../../mfc/reference/csplitterwnd-class.md#createview)   
 [CWnd::Create](../../mfc/reference/cwnd-class.md#create)

