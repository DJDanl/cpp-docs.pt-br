---
title: Estrutura ATL_DRAWINFO
ms.date: 11/04/2016
f1_keywords:
- ATL::ATL_DRAWINFO
- ATL_DRAWINFO
- ATL.ATL_DRAWINFO
helpviewer_keywords:
- ATL_DRAWINFO structure
ms.assetid: dd2e2aa8-e8c5-403b-b4df-35c0f6f57fb7
ms.openlocfilehash: 728a7eed418a6600c9247b91ff7b777dd458e621
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69498004"
---
# <a name="atl_drawinfo-structure"></a>Estrutura ATL_DRAWINFO

Contém informações usadas para renderização em vários destinos, como uma impressora, um metarquivo ou um controle ActiveX.

## <a name="syntax"></a>Sintaxe

```
struct ATL_DRAWINFO {
    UINT cbSize;
    DWORD dwDrawAspect;
    LONG lindex;
    DVTARGETDEVICE* ptd;
    HDC hicTargetDev;
    HDC hdcDraw;
    LPCRECTL prcBounds;
    LPCRECTL prcWBounds;
    BOOL bOptimize;
    BOOL bZoomed;
    BOOL bRectInHimetric;
    SIZEL ZoomNum;
    SIZEL ZoomDen;
};
```

## <a name="members"></a>Membros

`cbSize`<br/>
O tamanho da estrutura, em bytes.

`dwDrawAspect`<br/>
Especifica como o destino deve ser representado. As representações podem incluir conteúdo, um ícone, uma miniatura ou um documento impresso. Para obter uma lista de valores possíveis, consulte [DVASPECT](/windows/win32/api/wtypes/ne-wtypes-dvaspect) e [DVASPECT2](/windows/win32/api/ocidl/ne-ocidl-dvaspect2).

`lindex`<br/>
Parte do destino que é de interesse para a operação de desenho. Sua interpretação varia dependendo do valor no `dwDrawAspect` membro.

`ptd`<br/>
Ponteiro para uma estrutura [DVTARGETDEVICE](/windows/win32/api/objidl/ns-objidl-dvtargetdevice) que habilita otimizações de desenho dependendo do aspecto especificado. Observe que os objetos e contêineres mais recentes que dão suporte a interfaces de desenho otimizadas também oferecem suporte a esse membro. Os objetos e contêineres mais antigos que não dão suporte a interfaces de desenho otimizadas sempre especificam NULL para esse membro.

`hicTargetDev`<br/>
Contexto de informações para o dispositivo de destino apontado pelo `ptd` qual o objeto pode extrair as métricas do dispositivo e testar os recursos do dispositivo. Se `ptd` for NULL, o objeto deverá ignorar o valor `hicTargetDev` no membro.

`hdcDraw`<br/>
O contexto do dispositivo no qual desenhar. Para um objeto sem janela, o `hdcDraw` membro está `MM_TEXT` no modo de mapeamento com suas coordenadas lógicas que correspondem às coordenadas do cliente da janela que a contém. Além disso, o contexto do dispositivo deve estar no mesmo estado que aquele normalmente passado por uma `WM_PAINT` mensagem.

`prcBounds`<br/>
Ponteiro para uma estrutura de [Rect](/previous-versions//dd162907\(v=vs.85\)) que especifica o retângulo `hdcDraw` em e em que o objeto deve ser desenhado. Esse membro controla o posicionamento e o alongamento do objeto. Esse membro deve ser nulo para desenhar um objeto ativo no local sem janelas. Em todas as outras situações, NULL não é um valor válido e deve resultar em `E_INVALIDARG` um código de erro. Se o contêiner passar um valor não nulo para um objeto sem janela, o objeto deverá renderizar o aspecto solicitado no contexto e no retângulo do dispositivo especificado. Um contêiner pode solicitar isso de um objeto sem janela para renderizar uma segunda exibição não ativa do objeto ou imprimir o objeto.

`prcWBounds`<br/>
Se `hdcDraw` for um contexto de dispositivo de metarquivo (consulte [GetDeviceCaps](/windows/win32/api/wingdi/nf-wingdi-getdevicecaps) no SDK do Windows), esse é um ponteiro para `RECTL` uma estrutura que especifica o retângulo delimitador no metarquivo subjacente. A estrutura de retângulo contém a extensão da janela e a origem da janela. Esses valores são úteis para o desenho de metaarquivos. O retângulo indicado por `prcBounds` está aninhado dentro `prcWBounds` deste retângulo; ele está no mesmo espaço de coordenadas.

`bOptimize`<br/>
Diferente de zero se o desenho do controle for otimizado, caso contrário 0. Se o desenho for otimizado, o estado do contexto do dispositivo será restaurado automaticamente quando você terminar de renderizar.

`bZoomed`<br/>
Diferente de zero se o destino tiver um fator de zoom, caso contrário, 0. O fator de zoom é armazenado `ZoomNum`em.

`bRectInHimetric`<br/>
Diferente de zero se as `prcBounds` dimensões de estiverem em HIMETRIC, caso contrário 0.

`ZoomNum`<br/>
A largura e a altura do retângulo no qual o objeto é renderizado. O fator de zoom ao longo do eixo x (a proporção do tamanho natural do objeto até sua extensão atual) do destino é o valor de `ZoomNum.cx` dividido pelo valor de. `ZoomDen.cx` O fator de zoom ao longo do eixo y é obtido de maneira semelhante.

`ZoomDen`<br/>
A largura e a altura reais do destino.

## <a name="remarks"></a>Comentários

O uso típico dessa estrutura seria a recuperação de informações durante a renderização do objeto de destino. Por exemplo, você pode recuperar valores de ATL_DRAWINFO dentro de sua sobrecarga de [CComControlBase:: OnDrawAdvanced](ccomcontrolbase-class.md#ondrawadvanced).

Essa estrutura armazena informações pertinentes usadas para renderizar a aparência de um objeto para o dispositivo de destino. As informações fornecidas podem ser usadas no desenho na tela, em uma impressora ou até mesmo em um metarquivo.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl. h

## <a name="see-also"></a>Consulte também

[Classes e structs](../../atl/reference/atl-classes.md)<br/>
[IViewObject::D bruto](/windows/win32/api/oleidl/nf-oleidl-iviewobject-draw)<br/>
[CComControlBase::OnDrawAdvanced](../../atl/reference/ccomcontrolbase-class.md#ondrawadvanced)
