---
title: Estrutura ATL_DRAWINFO | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f7a10932fd43e89af6d98d3d931d43810c710000
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="atldrawinfo-structure"></a>Estrutura ATL_DRAWINFO
Contém informações usadas para renderização para vários destinos, como uma impressora, metarquivo ou controle ActiveX.  
  
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
 `cbSize`  
 O tamanho da estrutura, em bytes.  
  
 **dwDrawAspect**  
 Especifica como o destino deve ser representado. Representações podem incluir conteúdo, um ícone, uma miniatura ou um documento impresso. Para obter uma lista de valores possíveis, consulte [DVASPECT](http://msdn.microsoft.com/library/windows/desktop/ms690318) e [DVASPECT2](http://msdn.microsoft.com/library/windows/desktop/ms688644).  
  
 **lindex**  
 Parte do destino de interesse para a operação de desenho. Sua interpretação varia dependendo do valor no **dwDrawAspect** membro.  
  
 **ptd**  
 Ponteiro para um [DVTARGETDEVICE](http://msdn.microsoft.com/library/windows/desktop/ms686613) estrutura que habilita otimizações de desenho dependendo o aspecto especificado. Observe que mais novos objetos e contêineres que oferecem suporte a interfaces de desenho otimizados dá suporte a este membro também. Especificam mais antigos objetos e contêineres que dão suporte a interfaces de desenho otimizados sempre **nulo** para esse membro.  
  
 **hicTargetDev**  
 Informações de contexto para o dispositivo de destino apontada pelo **ptd** do qual o objeto pode extrair métricas de dispositivo e testar os recursos do dispositivo. Se **ptd** é **nulo**, o objeto deve ignorar o valor de **hicTargetDev** membro.  
  
 **hdcDraw**  
 O contexto de dispositivo no qual desenhar. Para um objeto sem janelas, o **hdcDraw** membro se encontra o `MM_TEXT` modo de mapeamento com suas coordenadas lógicos correspondente as coordenadas de cliente da janela. Além disso, o contexto do dispositivo deve estar no mesmo estado daquele normalmente passado por um `WM_PAINT` mensagem.  
  
 **prcBounds**  
 Ponteiro para um [RECTL](http://msdn.microsoft.com/library/windows/desktop/dd162907) estrutura especificando o retângulo em **hdcDraw** e no qual o objeto deve ser desenhado. Este membro controla o posicionamento e alongamento do objeto. Esse membro deve ser **nulo** para desenhar um objeto de ativo in-loco sem janelas. Em todas as outras situações, **nulo** não é um valor válido e deve resultar em um `E_INVALIDARG` código de erro. Se passar o contêiner não**nulo** valor a um objeto sem janelas, o objeto deve processar o aspecto solicitado para o contexto de dispositivo especificado e o retângulo. Um contêiner pode solicitá-la de um objeto sem janelas para renderizar uma exibição em segundo lugar, não ativo do objeto ou para imprimir o objeto.  
  
 **prcWBounds**  
 Se **hdcDraw** é um contexto de dispositivo de metarquivo (consulte [GetDeviceCaps](http://msdn.microsoft.com/library/windows/desktop/dd144877) no SDK do Windows), isso é um ponteiro para um **RECTL** estrutura especificando o retângulo delimitador no Metarquivo subjacente. A estrutura de retângulo contém a extensão da janela e a origem da janela. Esses valores são úteis para desenhar metarquivos. O retângulo indicado pelo **prcBounds** está aninhado em isso **prcWBounds** retângulo; estiverem no mesmo espaço de coordenada.  
  
 **bOptimize**  
 Diferente de zero se o desenho do controle é seja otimizado, caso contrário, 0. Se o desenho é otimizado, o estado do contexto do dispositivo é restaurado automaticamente quando tiver terminado de renderização.  
  
 **bZoomed**  
 Diferente de zero se o destino tem um fator de zoom, caso contrário, 0. O fator de zoom é armazenado em **ZoomNum**.  
  
 **bRectInHimetric**  
 Diferente de zero se as dimensões do **prcBounds** no **HIMETRIC**, caso contrário, 0.  
  
 **ZoomNum**  
 A largura e altura do retângulo no qual o objeto é processado. O fator de zoom no eixo (a proporção de tamanho natural do objeto para sua extensão atual) do destino é o valor de **ZoomNum.cx** dividido pelo valor de **ZoomDen.cx**. O fator de zoom no eixo y é obtido de forma semelhante.  
  
 **ZoomDen**  
 A largura e altura reais do destino.  
  
## <a name="remarks"></a>Comentários  
 Um uso típico dessa estrutura seria a recuperação de informações durante o processamento do objeto de destino. Por exemplo, você pode recuperar valores de `ATL_DRAWINFO` dentro de sua sobrecarga do [CComControlBase::OnDrawAdvanced](ccomcontrolbase-class.md#ondrawadvanced).  
  
 Essa estrutura armazena as informações usadas para renderizar a aparência de um objeto para o dispositivo de destino. As informações fornecidas podem ser usadas no desenho para a tela, uma impressora ou até mesmo um metarquivo.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas](../../atl/reference/atl-structures.md)   
 [IViewObject::Draw](http://msdn.microsoft.com/library/windows/desktop/ms688655)   
 [CComControlBase::OnDrawAdvanced](../../atl/reference/ccomcontrolbase-class.md#ondrawadvanced)





