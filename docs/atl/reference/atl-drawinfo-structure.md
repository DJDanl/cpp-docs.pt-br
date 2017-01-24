---
title: "Estrutura de ATL_DRAWINFO | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "ATL::ATL_DRAWINFO"
  - "ATL_DRAWINFO"
  - "ATL.ATL_DRAWINFO"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura de ATL_DRAWINFO"
ms.assetid: dd2e2aa8-e8c5-403b-b4df-35c0f6f57fb7
caps.latest.revision: 16
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura de ATL_DRAWINFO
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Contém informações usadas para processar vários destinos, como uma impressora, meta\-arquivo, ou um controle ActiveX.  
  
## Sintaxe  
  
```  
  
      struct ATL_DRAWINFO{  
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
  
## Membros  
 `cbSize`  
 O tamanho de estrutura, em bytes.  
  
 **dwDrawAspect**  
 Especifica como o destino deve ser representado.  As representações podem incluir o conteúdo, um ícone, uma miniatura, ou um documento impresso.  Para obter uma lista de valores possíveis, consulte [DVASPECT](http://msdn.microsoft.com/library/windows/desktop/ms690318) e [DVASPECT2](http://msdn.microsoft.com/library/windows/desktop/ms688644).  
  
 **lindex**  
 Parte de destino que é de interesse para a operação de desenho.  A interpretação varia dependendo do valor do membro de **dwDrawAspect** .  
  
 **ptd**  
 Ponteiro a estrutura de [DVTARGETDEVICE](http://msdn.microsoft.com/library/windows/desktop/ms686613) que permite otimizações de desenho como o aspecto especificado.  Observe que objetos mais recentes e contêiner que as interfaces otimizadas suporte de desenho oferecem suporte para esse membro também.  Os objetos e um contêiner mais antigos que não suportem interfaces otimizadas de desenho sempre especificam **NULO** para esse membro.  
  
 **hicTargetDev**  
 O contexto de informações para o dispositivo de destino apontado por **ptd** de que o objeto pode extrair métricas de dispositivo e testar os recursos do dispositivo.  Se **ptd** é **NULO**, o objeto deve ignorar o valor no membro de **hicTargetDev** .  
  
 **hdcDraw**  
 O contexto de dispositivo em que a desenhar.  Para um objeto sem janelas, o membro de **hdcDraw** está em `MM_TEXT` que mapeia o modo com suas coordenadas lógicas correspondente as coordenadas do cliente de janela que a contém.  Além de isso, o contexto de dispositivo deve estar no mesmo estado que o passado normalmente por uma mensagem de `WM_PAINT` .  
  
 **prcBounds**  
 Ponteiro a estrutura de [RECTL](http://msdn.microsoft.com/library/windows/desktop/dd162907) que especifica o retângulo em **hdcDraw** e em que o objeto deve ser desenhado.  Esse membro controla o posicionamento e alongar\-se do objeto.  Esse membro deve ser **NULO** para desenhar um objeto ativo no local sem janelas.  Em cada outra situação, **NULO** não é um valor válido e deve resultar em um código de erro de `E_INVALIDARG` .  Se o recipiente não passa um valor de**NULO** a um objeto sem janelas, o objeto deve processar o aspecto aplicativo no contexto e especificados no retângulo de dispositivo.  Um contêiner pode solicitar esse de um objeto sem janelas para processar uma segunda exibição, não ativa do objeto ou para imprimir o objeto.  
  
 **prcWBounds**  
 Se **hdcDraw** é um contexto do dispositivo de metarquivo \(consulte [GetDeviceCaps](http://msdn.microsoft.com/library/windows/desktop/dd144877) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]\), este é um ponteiro a estrutura de **RECTL** que especifica o retângulo delimitador no metarquivo subjacente.  A estrutura do retângulo contém a extensão da janela e a origem da janela.  Esses valores são úteis para desenhar metarquivos.  O retângulo indicado por **prcBounds** é aninhado dentro de esse retângulo de **prcWBounds** ; estiverem no mesmo espaço de coordenadas.  
  
 **bOptimize**  
 Diferente de zero se o desenho do controle deve ser otimizada, se não 0.  Se o desenho é otimizado para, o estado do contexto de dispositivo é restaurado automaticamente quando você tiver terminado processamento.  
  
 **bZoomed**  
 Diferente de zero se o destino tem um fator de zoom, se não 0.  O fator de zoom é armazenado em **ZoomNum**.  
  
 **bRectInHimetric**  
 Diferente de zero se as dimensões de **prcBounds** estão em **HIMETRIC**, se não 0.  
  
 **ZoomNum**  
 A largura e altura do retângulo em que o objeto é processado.  O fator de zoom no eixo x \(a proporção de tamanho natural do objeto à sua extensão atual\) de destino é o valor de **ZoomNum.cx** dividido pelo valor de **ZoomDen.cx**.  O fator de zoom no eixo y é obtido de uma maneira semelhante.  
  
 **ZoomDen**  
 A largura e altura reais de destino.  
  
## Comentários  
 O uso típico de essa estrutura seria a recuperação de informações durante o processamento do objeto alvo.  Por exemplo, você pode recuperar valores de `ATL_DRAWINFO` dentro da sobrecarga de [CComControlBase::OnDrawAdvanced](../Topic/CComControlBase::OnDrawAdvanced.md).  
  
 Essa estrutura armazena informações pertinentes usada para processar a aparência de um objeto para o dispositivo de destino.  As informações fornecidas pode ser usada no desenho na tela, em uma impressora, ou até mesmo a meta\-arquivo.  
  
## Requisitos  
 **Cabeçalho:** atlctl.h  
  
## Consulte também  
 [Estruturas](../../atl/reference/atl-structures.md)   
 [IViewObject::Draw](http://msdn.microsoft.com/library/windows/desktop/ms688655)   
 [CComControlBase::OnDrawAdvanced](../Topic/CComControlBase::OnDrawAdvanced.md)