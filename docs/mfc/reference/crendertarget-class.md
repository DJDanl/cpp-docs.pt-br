---
title: "Classe de CRenderTarget | Microsoft Docs"
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
  - "CRenderTarget"
  - "afxrendertarget/CRenderTarget"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CRenderTarget"
ms.assetid: 30d1607d-68d3-4d14-ac36-fdbd0ef903a1
caps.latest.revision: 17
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CRenderTarget
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um wrapper para ID2D1RenderTarget.  
  
## Sintaxe  
  
```  
class CRenderTarget : public CObject;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRenderTarget::CRenderTarget](../Topic/CRenderTarget::CRenderTarget.md)|Constrói um objeto de CRenderTarget.|  
|[CRenderTarget::~CRenderTarget](../Topic/CRenderTarget::~CRenderTarget.md)|O destrutor.  Chamado quando um objeto alvo processar for destruído.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRenderTarget::Attach](../Topic/CRenderTarget::Attach.md)|A existência dos anexa processa a interface de destino para o objeto|  
|[CRenderTarget::BeginDraw](../Topic/CRenderTarget::BeginDraw.md)|Os novatos que desenha em este processam o destino.|  
|[CRenderTarget::Clear](../Topic/CRenderTarget::Clear.md)|Limpa a área de desenho à cor especificada.|  
|[CRenderTarget::COLORREF\_TO\_D2DCOLOR](../Topic/CRenderTarget::COLORREF_TO_D2DCOLOR.md)|Os valores de cor e de alfa converte GDI ao D2D1\_COLOR\_F objeto.|  
|[CRenderTarget::CreateCompatibleRenderTarget](../Topic/CRenderTarget::CreateCompatibleRenderTarget.md)|Cria um novo bitmap processam o destino para uso durante o intermediário que desenha offscreen que é compatível com a atual processa o destino.|  
|[CRenderTarget::Destroy](../Topic/CRenderTarget::Destroy.md)|Exclui um ou mais recursos|  
|[CRenderTarget::Detach](../Topic/CRenderTarget::Detach.md)|Detaches processa a interface de destino do objeto|  
|[CRenderTarget::DrawBitmap](../Topic/CRenderTarget::DrawBitmap.md)|Desenha texto formatado descrito pelo objeto especificado de IDWriteTextLayout.|  
|[CRenderTarget::DrawEllipse](../Topic/CRenderTarget::DrawEllipse.md)|Desenha o contorno da elipse especificada usando o estilo especificado de traço.|  
|[CRenderTarget::DrawGeometry](../Topic/CRenderTarget::DrawGeometry.md)|Desenha o contorno da geometria especificada usando o estilo especificado de traço.|  
|[CRenderTarget::DrawGlyphRun](../Topic/CRenderTarget::DrawGlyphRun.md)|Desenha glifos especificados.|  
|[CRenderTarget::DrawLine](../Topic/CRenderTarget::DrawLine.md)|Desenha uma linha entre os pontos especificados usando o estilo especificado de traço.|  
|[CRenderTarget::DrawRectangle](../Topic/CRenderTarget::DrawRectangle.md)|Desenha o contorno de um retângulo que tenha as dimensões e o estilo especificados de traço.|  
|[CRenderTarget::DrawRoundedRectangle](../Topic/CRenderTarget::DrawRoundedRectangle.md)|Desenha o contorno do retângulo arredondado especificado usando o estilo especificado de traço.|  
|[CRenderTarget::DrawText](../Topic/CRenderTarget::DrawText.md)|Desenha texto especificado usando informações de formato fornecida por um objeto de IDWriteTextFormat.|  
|[CRenderTarget::DrawTextLayout](../Topic/CRenderTarget::DrawTextLayout.md)|Desenha texto formatado descrito pelo objeto especificado de IDWriteTextLayout.|  
|[CRenderTarget::EndDraw](../Topic/CRenderTarget::EndDraw.md)|Termina que desenha operações no destino e processar indicam o estado atual do erro e as marcas associados.|  
|[CRenderTarget::FillEllipse](../Topic/CRenderTarget::FillEllipse.md)|Pinta o interior da elipse especificada.|  
|[CRenderTarget::FillGeometry](../Topic/CRenderTarget::FillGeometry.md)|Pinta o interior da geometria especificada.|  
|[CRenderTarget::FillMesh](../Topic/CRenderTarget::FillMesh.md)|Pinta o interior de malha especificada.|  
|[CRenderTarget::FillOpacityMask](../Topic/CRenderTarget::FillOpacityMask.md)|Aplica a máscara de opacidade descrita pelo bitmap especificado a um pincel e usa para que escovem para pintar uma região de destino renderização.|  
|[CRenderTarget::FillRectangle](../Topic/CRenderTarget::FillRectangle.md)|Pinta o interior do retângulo especificado.|  
|[CRenderTarget::FillRoundedRectangle](../Topic/CRenderTarget::FillRoundedRectangle.md)|Pinta o interior do retângulo arredondado especificado.|  
|[CRenderTarget::Flush](../Topic/CRenderTarget::Flush.md)|Executa todos os comandos de desenho pendentes.|  
|[CRenderTarget::GetAntialiasMode](../Topic/CRenderTarget::GetAntialiasMode.md)|Recupera o modo atual de anti\-aliasing para operações de desenho de nontext.|  
|[CRenderTarget::GetDpi](../Topic/CRenderTarget::GetDpi.md)|Retorna os pontos de destino processar por polegada \(DPI\)|  
|[CRenderTarget::GetMaximumBitmapSize](../Topic/CRenderTarget::GetMaximumBitmapSize.md)|Obtém o tamanho máximo, em unidades de dependente de dispositivo \(pixels\), de qualquer uma dimensão de bitmap suportada pelo destino processar|  
|[CRenderTarget::GetPixelFormat](../Topic/CRenderTarget::GetPixelFormat.md)|Recupera o formato de pixel e o modo de processamento de destino|  
|[CRenderTarget::GetPixelSize](../Topic/CRenderTarget::GetPixelSize.md)|Retorna o tamanho de destino processar em pixels de dispositivo|  
|[CRenderTarget::GetRenderTarget](../Topic/CRenderTarget::GetRenderTarget.md)|Interface de retorna ID2D1RenderTarget|  
|[CRenderTarget::GetSize](../Topic/CRenderTarget::GetSize.md)|Retorna o tamanho de destino processar em pixels independentes|  
|[CRenderTarget::GetTags](../Topic/CRenderTarget::GetTags.md)|Obtém o rótulo para operações subsequentes de desenho.|  
|[CRenderTarget::GetTextAntialiasMode](../Topic/CRenderTarget::GetTextAntialiasMode.md)|Obtém o modo atual de anti\-aliasing para operações de desenho de texto e de glifos.|  
|[CRenderTarget::GetTextRenderingParams](../Topic/CRenderTarget::GetTextRenderingParams.md)|Recupera as opções atuais de renderização de texto de destino renderização.|  
|[CRenderTarget::GetTransform](../Topic/CRenderTarget::GetTransform.md)|Aplica especificado torna\-se ao processar destino, substituindo a transformação existente.  Todas as operações subsequentes de desenho ocorrem no espaço transformado.|  
|[CRenderTarget::IsSupported](../Topic/CRenderTarget::IsSupported.md)|Indica se o destino processar suporta propriedades especificadas|  
|[CRenderTarget::IsValid](../Topic/CRenderTarget::IsValid.md)|Verifica a validade de recurso|  
|[CRenderTarget::PopAxisAlignedClip](../Topic/CRenderTarget::PopAxisAlignedClip.md)|Remove o corte eixo\- alinhado pela última vez de processar destino.  Após esse método é chamado, o corte é aplicado ainda não às operações subsequentes de desenho.|  
|[CRenderTarget::PopLayer](../Topic/CRenderTarget::PopLayer.md)|Para redirecionar de operações de desenho a camada que é especificado pela última chamada de PushLayer.|  
|[CRenderTarget::PushAxisAlignedClip](../Topic/CRenderTarget::PushAxisAlignedClip.md)|Remove o corte eixo\- alinhado pela última vez de processar destino.  Após esse método é chamado, o corte é aplicado ainda não às operações subsequentes de desenho.|  
|[CRenderTarget::PushLayer](../Topic/CRenderTarget::PushLayer.md)|Adiciona a camada especificada para processar destino para que ele recebe todas as operações subsequentes de desenho até que PopLayer seja chamado.|  
|[CRenderTarget::RestoreDrawingState](../Topic/CRenderTarget::RestoreDrawingState.md)|Define o estado de desenho de destino com renderização de ID2D1DrawingStateBlock especificado.|  
|[CRenderTarget::SaveDrawingState](../Topic/CRenderTarget::SaveDrawingState.md)|Salvar o estado atual do desenho ao ID2D1DrawingStateBlock especificado.|  
|[CRenderTarget::SetAntialiasMode](../Topic/CRenderTarget::SetAntialiasMode.md)|Defina o modo de anti\-aliasing de destino renderização.  O modo de anti\-aliasing se aplica a todas as operações subsequentes de desenho, excluindo o texto e as operações de desenho de glifos.|  
|[CRenderTarget::SetDpi](../Topic/CRenderTarget::SetDpi.md)|Defina os pontos por polegada \(DPI\) de destino renderização.|  
|[CRenderTarget::SetTags](../Topic/CRenderTarget::SetTags.md)|Especifica um rótulo para operações subsequentes de desenho.|  
|[CRenderTarget::SetTextAntialiasMode](../Topic/CRenderTarget::SetTextAntialiasMode.md)|Especifica o modo de anti\-aliasing para usar operações subsequentes de desenho de texto e de glifos.|  
|[CRenderTarget::SetTextRenderingParams](../Topic/CRenderTarget::SetTextRenderingParams.md)|Especificar opções de renderização de texto ser aplicado para todas as operações subsequentes de desenho de texto e de glifos.|  
|[CRenderTarget::SetTransform](../Topic/CRenderTarget::SetTransform.md)|Sobrecarregado.  Aplica especificado torna\-se ao processar destino, substituindo a transformação existente.  Todas as operações subsequentes de desenho ocorrem no espaço transformado.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRenderTarget::VerifyResource](../Topic/CRenderTarget::VerifyResource.md)|Verifica a validade de objeto de CD2DResource; cria o objeto se já não existir.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRenderTarget::operator ID2D1RenderTarget\*](../Topic/CRenderTarget::operator%20ID2D1RenderTarget*.md)|Interface de retorna ID2D1RenderTarget|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRenderTarget::m\_lstResources](../Topic/CRenderTarget::m_lstResources.md)|Uma lista de ponteiros para objetos de CD2DResource.|  
|[CRenderTarget::m\_pRenderTarget](../Topic/CRenderTarget::m_pRenderTarget.md)|Um ponteiro para um objeto de ID2D1RenderTarget.|  
|[CRenderTarget::m\_pTextFormatDefault](../Topic/CRenderTarget::m_pTextFormatDefault.md)|Um ponteiro para o objeto de CD2DTextFormat que contém um formato de texto padrão.|  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CRenderTarget](../../mfc/reference/crendertarget-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)