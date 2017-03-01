---
title: Estrutura ATL_DRAWINFO | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL::ATL_DRAWINFO
- ATL_DRAWINFO
- ATL.ATL_DRAWINFO
dev_langs:
- C++
helpviewer_keywords:
- ATL_DRAWINFO structure
ms.assetid: dd2e2aa8-e8c5-403b-b4df-35c0f6f57fb7
caps.latest.revision: 16
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 050e7483670bd32f633660ba44491c8bb3fc462d
ms.openlocfilehash: bc124de97acf85d6e706605afb55b0747a327ade
ms.lasthandoff: 02/25/2017

---
# <a name="atldrawinfo-structure"></a>Estrutura ATL_DRAWINFO
Contém informações usadas para processamento a vários destinos, como uma impressora, um metarquivo ou um controle ActiveX.  
  
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
 Especifica como o destino deve ser representado. Representações podem incluir conteúdo, um ícone, uma miniatura ou um documento impresso. Para obter uma lista dos valores possíveis, consulte [DVASPECT](http://msdn.microsoft.com/library/windows/desktop/ms690318) e [DVASPECT2](http://msdn.microsoft.com/library/windows/desktop/ms688644).  
  
 **lindex**  
 Parte de destino que é de interesse para a operação de desenho. Sua interpretação varia de acordo com o valor de **dwDrawAspect** membro.  
  
 **ptd**  
 Ponteiro para uma [DVTARGETDEVICE](http://msdn.microsoft.com/library/windows/desktop/ms686613) estrutura que habilita otimizações de desenho dependendo o aspecto especificado. Observe que os mais novos objetos e contêineres que oferecem suporte a interfaces de desenho otimizados suportam esse membro também. Especificam mais antigos objetos e contêineres que dão suporte a interfaces de desenho otimizadas sempre **nulo** para este membro.  
  
 **hicTargetDev**  
 Informações de contexto para o dispositivo de destino apontada por **ptd** da qual o objeto pode extrair métricas de dispositivo e testar os recursos do dispositivo. Se **ptd** é **nulo**, o objeto deve ignorar o valor de **hicTargetDev** membro.  
  
 **hdcDraw**  
 O contexto de dispositivo no qual desenhar. Para um objeto sem janelas, o **hdcDraw** membro se encontra o `MM_TEXT` modo de mapeamento com suas coordenadas lógicos correspondente as coordenadas do cliente da janela. Além disso, o contexto do dispositivo deve ser no mesmo estado que normalmente é passado por um `WM_PAINT` mensagem.  
  
 **prcBounds**  
 Ponteiro para uma [RECTL](http://msdn.microsoft.com/library/windows/desktop/dd162907) estrutura especificando o retângulo em **hdcDraw** e no qual o objeto deve ser desenhado. Esse membro controla o posicionamento e alongamento do objeto. Esse membro deve ser **nulo** para desenhar um objeto de ativo in-loco sem janelas. Em todas as outras situações, **nulo** não é um valor válido e deve resultar em um `E_INVALIDARG` código de erro. Se o contêiner passa um não -**nulo** valor a um objeto sem janelas, o objeto deve processar o aspecto solicitado para o contexto de dispositivo especificado e o retângulo. Um contêiner pode solicitar isso de um objeto sem janelas para renderizar uma exibição segundo inativo do objeto ou para imprimir o objeto.  
  
 **prcWBounds**  
 Se **hdcDraw** é um contexto de dispositivo de metarquivo (consulte [GetDeviceCaps](http://msdn.microsoft.com/library/windows/desktop/dd144877) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]), isso é um ponteiro para um **RECTL** estrutura especificando o retângulo delimitador de metarquivo subjacente. A estrutura de retângulo contém a extensão da janela e a origem da janela. Esses valores são úteis para desenhar metarquivos. O retângulo indicado por **prcBounds** está aninhado em isso **prcWBounds** retângulo; estiverem no mesmo espaço de coordenadas.  
  
 **bOptimize**  
 Diferente de zero se o desenho do controle é ser otimizado, caso contrário, 0. Se o desenho é otimizado, o estado do contexto do dispositivo é restaurado automaticamente quando você terminar de renderização.  
  
 **bZoomed**  
 Diferente de zero se o destino tem um fator de zoom, caso contrário, 0. O fator de zoom é armazenado em **ZoomNum**.  
  
 **bRectInHimetric**  
 Diferente de zero se as dimensões do **prcBounds** estão em **HIMETRIC**, caso contrário, 0.  
  
 **ZoomNum**  
 A largura e altura do retângulo no qual o objeto é processado. O fator de zoom ao longo do eixo x (a proporção de tamanho natural do objeto para sua extensão atual) do destino é o valor do **ZoomNum.cx** dividido pelo valor do **ZoomDen.cx**. O fator de zoom no eixo y é obtido de maneira semelhante.  
  
 **ZoomDen**  
 A largura e altura reais do destino.  
  
## <a name="remarks"></a>Comentários  
 Um uso típico dessa estrutura seria a recuperação de informações durante o processamento do objeto de destino. Por exemplo, você pode recuperar valores de `ATL_DRAWINFO` dentro de sua sobrecarga de [CComControlBase::OnDrawAdvanced](ccomcontrolbase-class.md#ondrawadvanced).  
  
 Essa estrutura armazena as informações usadas para processar a aparência de um objeto para o dispositivo de destino. As informações fornecidas podem ser usadas no desenho para a tela, uma impressora ou até mesmo um metarquivo.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas](../../atl/reference/atl-structures.md)   
 [IViewObject::Draw](http://msdn.microsoft.com/library/windows/desktop/ms688655)   
 [CComControlBase::OnDrawAdvanced](../../atl/reference/ccomcontrolbase-class.md#ondrawadvanced)






