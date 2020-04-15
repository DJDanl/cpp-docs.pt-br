---
title: Estrutura ccreatecontext
ms.date: 11/04/2016
f1_keywords:
- CCreateContext
helpviewer_keywords:
- CCreateContext structure [MFC]
ms.assetid: 337a0e44-d910-49a8-afc0-c7207666a9dc
ms.openlocfilehash: 29fc6210b9888b6a5ba5aaf15b66242c29c15dc8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369378"
---
# <a name="ccreatecontext-structure"></a>Estrutura ccreatecontext

A estrutura `CCreateContext` usa a estrutura quando cria as janelas e visualizações do quadro que estão associadas a um documento.

## <a name="syntax"></a>Sintaxe

```
struct CCreateContext
```

## <a name="remarks"></a>Comentários

`CCreateContext`é uma estrutura e não tem uma classe base.

Quando você cria uma janela, os valores nesta estrutura fornecem as informações usadas para conectar os componentes de um documento à exibição de seus dados. Você só tem `CCreateContext` que usar se estiver substituindo partes do processo de criação.

Uma `CCreateContext` estrutura contém ponteiros para o documento, a janela do quadro, a exibição e o modelo do documento. Ele também contém um `CRuntimeClass` ponteiro para um que identifica o tipo de exibição a ser criado. As informações da classe de tempo de execução e o ponteiro de documento atual são usados para criar uma nova exibição dinamicamente. A tabela a seguir `CCreateContext` sugere como e quando cada membro pode ser usado:

|Membro|Type|Para que é|
|------------|----------|--------------------|
|`m_pNewViewClass`|`CRuntimeClass*`|`CRuntimeClass`da nova visão para criar.|
|`m_pCurrentDoc`|`CDocument*`|O documento existente a ser associado à nova visão.|
|`m_pNewDocTemplate`|`CDocTemplate*`|O modelo de documento associado à criação de uma nova janela de quadro MDI.|
|`m_pLastView`|`CView*`|A visão original sobre a qual as visualizações adicionais são modeladas, como na criação de visualizações de janelas de divisor ou na criação de uma segunda exibição em um documento.|
|`m_pCurrentFrame`|`CFrameWnd*`|A janela de quadro em que as janelas adicionais do quadro são modeladas, como na criação de uma segunda janela de quadro em um documento.|

Quando um modelo de documento cria um documento e seus componentes associados, ele valida as informações armazenadas na `CCreateContext` estrutura. Por exemplo, uma visão não deve ser criada para um documento inexistente.

> [!NOTE]
> Todos os ponteiros `CCreateContext` são opcionais `NULL` e podem ser não especificados ou desconhecidos.

`CCreateContext`é usado pelas funções de membro listadas em "Ver Também". Consulte as descrições dessas funções para obter informações específicas se você planeja substituí-las.

Aqui estão algumas diretrizes gerais:

- Quando passado como um argumento para `CWnd::Create` `CFrameWnd::Create`a `CFrameWnd::LoadFrame`criação de janelas, como em , e , o contexto de criação especifica ao que a nova janela deve ser conectada. Para a maioria das janelas, `NULL` toda a estrutura é opcional e um ponteiro pode ser passado.

- Para funções de membros superridíveis, como `CFrameWnd::OnCreateClient`, o `CCreateContext` argumento é opcional.

- Para as funções de membro envolvidas na criação de visualizações, você deve fornecer informações suficientes para criar a exibição. Por exemplo, para a primeira exibição em uma janela de divisor, você deve fornecer as informações da classe de exibição e o documento atual.

Em geral, se você usar os padrões de estrutura, você pode ignorar `CCreateContext`. Se você tentar modificações mais avançadas, o código-fonte da Biblioteca de Classe da Microsoft Foundation ou os programas de exemplo, como o VIEWEX, irão guiá-lo. Se você esquecer um parâmetro necessário, uma afirmação de estrutura lhe dirá o que você esqueceu.

Para obter `CCreateContext`mais informações, consulte a amostra de MFC [VIEWEX](../../overview/visual-cpp-samples.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[CFrameWnd::Criar](../../mfc/reference/cframewnd-class.md#create)<br/>
[CFrameWnd::''''''''''''''''''''](../../mfc/reference/cframewnd-class.md#loadframe)<br/>
[CFrameWnd::OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient)<br/>
[CSplitterWnd::Criar](../../mfc/reference/csplitterwnd-class.md#create)<br/>
[CSplitterWnd::CreateView](../../mfc/reference/csplitterwnd-class.md#createview)<br/>
[CWnd::Criar](../../mfc/reference/cwnd-class.md#create)
