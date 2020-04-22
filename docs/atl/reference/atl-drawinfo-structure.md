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
ms.openlocfilehash: fb50f49d387e8620f3d5bbb41263738adbd8b437
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81748796"
---
# <a name="atl_drawinfo-structure"></a>Estrutura ATL_DRAWINFO

Contém informações usadas para renderização para vários alvos, como uma impressora, metaarquivo ou controle ActiveX.

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
Especifica como o alvo deve ser representado. As representações podem incluir conteúdo, um ícone, uma miniatura ou um documento impresso. Para obter uma lista de valores possíveis, consulte [DVASPECT](/windows/win32/api/wtypes/ne-wtypes-dvaspect) e [DVASPECT2](/windows/win32/api/ocidl/ne-ocidl-dvaspect2).

`lindex`<br/>
Parte do alvo que é de interesse para a operação de saque. Sua interpretação varia de acordo `dwDrawAspect` com o valor do membro.

`ptd`<br/>
Pointer para uma estrutura [DVTARGETDEVICE](/windows/win32/api/objidl/ns-objidl-dvtargetdevice) que permite otimizações de desenho dependendo do aspecto especificado. Observe que objetos e recipientes mais novos que suportam interfaces de desenho otimizadas também suportam esse membro. Objetos e recipientes mais antigos que não suportam interfaces de desenho otimizadas sempre especificam NULL para este membro.

`hicTargetDev`<br/>
Contexto de informações para o `ptd` dispositivo de destino apontado para o qual o objeto pode extrair métricas do dispositivo e testar as capacidades do dispositivo. Se `ptd` for NULO, o objeto `hicTargetDev` deve ignorar o valor no membro.

`hdcDraw`<br/>
O contexto do dispositivo sobre o qual desenhar. Para um objeto sem janelas, o `hdcDraw` membro está no modo `MM_TEXT` de mapeamento com suas coordenadas lógicas correspondentes às coordenadas do cliente da janela de contenção. Além disso, o contexto do dispositivo deve estar no `WM_PAINT` mesmo estado do normalmente passado por uma mensagem.

`prcBounds`<br/>
Pointer para uma estrutura [RECTL](/windows/win32/api/windef/ns-windef-rectl) especificando `hdcDraw` o retângulo em e no qual o objeto deve ser desenhado. Este membro controla o posicionamento e o alongamento do objeto. Este membro deve ser NULO para desenhar um objeto ativo sem janelas no local. Em todas as outras situações, NULL não `E_INVALIDARG` é um valor legal e deve resultar em um código de erro. Se o contêiner passar um valor não NULA para um objeto sem janelas, o objeto deve renderizar o aspecto solicitado no contexto e retângulo do dispositivo especificado. Um contêiner pode solicitar isso a partir de um objeto sem janelas para renderizar uma segunda visão não ativa do objeto ou imprimir o objeto.

`prcWBounds`<br/>
Se `hdcDraw` é um contexto de dispositivo de metaarquivo (consulte [GetDeviceCaps](/windows/win32/api/wingdi/nf-wingdi-getdevicecaps) no `RECTL` Windows SDK), este é um ponteiro para uma estrutura especificando o retângulo delimitador no metaarquivo subjacente. A estrutura retângulo contém a extensão da janela e a origem da janela. Esses valores são úteis para desenhar metaarquivos. O retângulo indicado `prcBounds` por está `prcWBounds` aninhado dentro deste retângulo; eles estão no mesmo espaço de coordenadas.

`bOptimize`<br/>
Não zero se o desenho do controle for otimizado, caso contrário 0. Se o desenho for otimizado, o estado do contexto do dispositivo será automaticamente restaurado quando você estiver pronto para renderização.

`bZoomed`<br/>
Não zero se o alvo tiver um fator de zoom, caso contrário 0. O fator zoom `ZoomNum`é armazenado em .

`bRectInHimetric`<br/>
Não zero se as `prcBounds` dimensões de estão em HIMETRIC, caso contrário 0.

`ZoomNum`<br/>
A largura e a altura do retângulo no qual o objeto é renderizado. O fator de zoom ao longo do eixo x (a proporção do tamanho natural `ZoomNum.cx` do objeto até `ZoomDen.cx`a sua extensão atual) do alvo é o valor de dividido pelo valor de . O fator zoom ao longo do eixo y é alcançado de forma semelhante.

`ZoomDen`<br/>
A largura e altura real do alvo.

## <a name="remarks"></a>Comentários

O uso típico desta estrutura seria a recuperação de informações durante a renderização do objeto alvo. Por exemplo, você pode recuperar valores de ATL_DRAWINFO dentro da sobrecarga do [CComControlBase::OnDrawAdvanced](ccomcontrolbase-class.md#ondrawadvanced).

Esta estrutura armazena informações pertinentes usadas para renderizar a aparência de um objeto para o dispositivo de destino. As informações fornecidas podem ser usadas em desenho para a tela, uma impressora ou até mesmo um metaarquivo.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="see-also"></a>Confira também

[Aulas e estruturas](../../atl/reference/atl-classes.md)<br/>
[IViewObject::Draw](/windows/win32/api/oleidl/nf-oleidl-iviewobject-draw)<br/>
[CComControlBase::OnDrawAdvanced](../../atl/reference/ccomcontrolbase-class.md#ondrawadvanced)
