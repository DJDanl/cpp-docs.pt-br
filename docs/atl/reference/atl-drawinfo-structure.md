---
title: Estrutura ATL_DRAWINFO | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- ATL::ATL_DRAWINFO
- ATL_DRAWINFO
- ATL.ATL_DRAWINFO
dev_langs:
- C++
helpviewer_keywords:
- ATL_DRAWINFO structure
ms.assetid: dd2e2aa8-e8c5-403b-b4df-35c0f6f57fb7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 87ae430dabf3a4aac54b77afb0b2ed5c143a8875
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46116029"
---
# <a name="atldrawinfo-structure"></a>Estrutura ATL_DRAWINFO

Contém informações usadas para renderizar a vários destinos, como uma impressora, metarquivo ou controle ActiveX.

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
Especifica como o destino deve ser representado. Representações podem incluir conteúdo, um ícone, uma miniatura ou um documento impresso. Para obter uma lista de valores possíveis, consulte [DVASPECT](/windows/desktop/api/wtypes/ne-wtypes-tagdvaspect) e [DVASPECT2](/windows/desktop/api/ocidl/ne-ocidl-tagdvaspect2).

`lindex`<br/>
Parte de destino que é de interesse para a operação de desenho. Sua interpretação varia dependendo do valor no `dwDrawAspect` membro.

`ptd`<br/>
Ponteiro para um [DVTARGETDEVICE](/windows/desktop/api/objidl/ns-objidl-tagdvtargetdevice) estrutura que habilita otimizações de desenho, dependendo do aspecto especificado. Observe que mais novos objetos e contêineres que dão suporte a interfaces de desenho otimizados dá suporte a esse membro também. Mais antigos objetos e contêineres que não dão suporte a interfaces de desenho otimizados sempre especificam NULL para esse membro.

`hicTargetDev`<br/>
Informações de contexto para o dispositivo de destino apontado pelo `ptd` do qual o objeto pode extrair métricas do dispositivo e as funcionalidades do dispositivo de teste. Se `ptd` for NULL, o objeto deve ignorar o valor de `hicTargetDev` membro.

`hdcDraw`<br/>
O contexto de dispositivo no qual desenhar. Para um objeto sem janelas, o `hdcDraw` membro se encontra o `MM_TEXT` modo de mapeamento com suas coordenadas lógicas correspondência as coordenadas do cliente da janela. Além disso, o contexto do dispositivo deve ser no mesmo estado que normalmente é passada por um `WM_PAINT` mensagem.

`prcBounds`<br/>
Ponteiro para um [RECTL](https://msdn.microsoft.com/library/windows/desktop/dd162907) estrutura especificando o retângulo em `hdcDraw` e no qual o objeto deve ser desenhado. Esse membro controla o posicionamento e alongamento do objeto. Esse membro deve ser NULL para desenhar um objeto de ativo in-loco sem janelas. Em todas as outras situações, NULL não é um valor válido e deve resultar em um `E_INVALIDARG` código de erro. Se o contêiner passa um valor não nulo para um objeto sem janelas, o objeto deve renderizar o aspecto solicitado para o contexto de dispositivo especificado e o retângulo. Um contêiner pode solicitá-la de um objeto sem janelas para renderizar uma exibição em segundo lugar, não ativo do objeto ou para imprimir o objeto.

`prcWBounds`<br/>
Se `hdcDraw` é um contexto de dispositivo de metarquivo (consulte [GetDeviceCaps](/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) no SDK do Windows), isso é um ponteiro para um `RECTL` estrutura especificando o retângulo delimitador no metarquivo subjacente. A estrutura de retângulo contém a extensão da janela e a origem de janela. Esses valores são úteis para desenhar metarquivos. O retângulo indicado por `prcBounds` está aninhado em isso `prcWBounds` retângulo; eles estão no mesmo espaço de coordenadas.

`bOptimize`<br/>
Diferente de zero se o desenho do controle é ser otimizado, caso contrário, 0. Se o desenho é otimizado, o estado do contexto do dispositivo é restaurado automaticamente quando tiver terminado de renderização.

`bZoomed`<br/>
Diferente de zero se o destino tem um fator de zoom, caso contrário, 0. O fator de zoom é armazenado em `ZoomNum`.

`bRectInHimetric`<br/>
Diferente de zero se as dimensões da `prcBounds` estão em HIMETRIC, caso contrário, 0.

`ZoomNum`<br/>
A largura e altura do retângulo no qual o objeto é renderizado. O fator de zoom ao longo do eixo x (a proporção de tamanho natural do objeto para sua extensão atual) do destino é o valor da `ZoomNum.cx` dividido pelo valor de `ZoomDen.cx`. O fator de zoom no eixo y é obtido de forma semelhante.

`ZoomDen`<br/>
A largura e altura reais do destino.

## <a name="remarks"></a>Comentários

Um uso típico dessa estrutura seria a recuperação de informações durante a renderização do objeto de destino. Por exemplo, você pode recuperar valores de ATL_DRAWINFO dentro de sua sobrecarga [CComControlBase::OnDrawAdvanced](ccomcontrolbase-class.md#ondrawadvanced).

Essa estrutura armazena as informações usadas para renderizar a aparência de um objeto para o dispositivo de destino. As informações fornecidas podem ser usadas no desenho para a tela, uma impressora ou até mesmo um metarquivo.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="see-also"></a>Consulte também

[Classes e structs](../../atl/reference/atl-classes.md)<br/>
[IViewObject::Draw](/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw)<br/>
[CComControlBase::OnDrawAdvanced](../../atl/reference/ccomcontrolbase-class.md#ondrawadvanced)
