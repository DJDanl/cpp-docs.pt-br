---
title: "Classe de CMFCToolBarImages | Microsoft Docs"
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
  - "CMFCToolBarImages"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCToolBarImages"
ms.assetid: d4e50518-9ffc-406f-9996-f79e5cd38155
caps.latest.revision: 31
caps.handback.revision: 19
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCToolBarImages
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As imagens em uma barra de ferramentas.  A classe de `CMFCToolBarImages` gerencia as imagens da barra de ferramentas carregadas os recursos do aplicativo ou arquivos.  
  
## Sintaxe  
  
```  
class CMFCToolBarImages : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarImages::CMFCToolBarImages](../Topic/CMFCToolBarImages::CMFCToolBarImages.md)|Constrói um objeto de `CMFCToolBarImages` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarImages::AdaptColors](../Topic/CMFCToolBarImages::AdaptColors.md)||  
|[CMFCToolBarImages::AddIcon](../Topic/CMFCToolBarImages::AddIcon.md)|Adiciona um ícone para imagens da barra de ferramentas.|  
|[CMFCToolBarImages::AddImage](../Topic/CMFCToolBarImages::AddImage.md)|Adiciona um para imagens bitmap da barra de ferramentas.|  
|[CMFCToolBarImages::CleanUp](../Topic/CMFCToolBarImages::CleanUp.md)||  
|[CMFCToolBarImages::Clear](../Topic/CMFCToolBarImages::Clear.md)|Libera os recursos do sistema atribuídas a esse objeto.|  
|[CMFCToolBarImages::ConvertTo32Bits](../Topic/CMFCToolBarImages::ConvertTo32Bits.md)|Bitmaps sublinhados converte a 32 imagens de bpp.|  
|[CMFCToolBarImages::CopyImageToClipboard](../Topic/CMFCToolBarImages::CopyImageToClipboard.md)||  
|[CMFCToolBarImages::CopyTo](../Topic/CMFCToolBarImages::CopyTo.md)||  
|[CMFCToolBarImages::CreateFromImageList](../Topic/CMFCToolBarImages::CreateFromImageList.md)|Inicializa as imagens da barra de ferramentas de uma lista de imagem \([Classe de CImageList](../Topic/CImageList%20Class.md)\).|  
|[CMFCToolBarImages::CreateRegionFromImage](../Topic/CMFCToolBarImages::CreateRegionFromImage.md)||  
|[CMFCToolBarImages::DeleteImage](../Topic/CMFCToolBarImages::DeleteImage.md)|Exclui a imagem que possui um índice especificado de imagens de barra de ferramentas se este conjunto de imagens da barra de ferramentas contém imagens definidas pelo usuário.|  
|[CMFCToolBarImages::Draw](../Topic/CMFCToolBarImages::Draw.md)|Desenha uma única imagem da barra de ferramentas \(botão\).|  
|[CMFCToolBarImages::DrawEx](../Topic/CMFCToolBarImages::DrawEx.md)||  
|[CMFCToolBarImages::EnableRTL](../Topic/CMFCToolBarImages::EnableRTL.md)||  
|[CMFCToolBarImages::EndDrawImage](../Topic/CMFCToolBarImages::EndDrawImage.md)|Libera recursos do sistema após uma imagem da barra de ferramentas é desenhada.|  
|[CMFCToolBarImages::ExtractIcon](../Topic/CMFCToolBarImages::ExtractIcon.md)|Retorna o ícone que possui um índice especificado de imagem de imagens da barra de ferramentas.|  
|[CMFCToolBarImages::FillDitheredRect](../Topic/CMFCToolBarImages::FillDitheredRect.md)|Preenche um retângulo usando um pincel que tenha as cores de plano de fundo da barra de ferramentas.|  
|[CMFCToolBarImages::GetAlwaysLight](../Topic/CMFCToolBarImages::GetAlwaysLight.md)||  
|[CMFCToolBarImages::GetBitsPerPixel](../Topic/CMFCToolBarImages::GetBitsPerPixel.md)|Retorna a resolução atual de imagens sublinhada.|  
|[CMFCToolBarImages::GetCount](../Topic/CMFCToolBarImages::GetCount.md)|Retorna o número de imagens na barra de ferramentas.|  
|[CMFCToolBarImages::GetDisabledImageAlpha](../Topic/CMFCToolBarImages::GetDisabledImageAlpha.md)|Retorna o valor do canal alfa que é usado para imagens desativados.|  
|[CMFCToolBarImages::GetFadedImageAlpha](../Topic/CMFCToolBarImages::GetFadedImageAlpha.md)||  
|[CMFCToolBarImages::GetImageSize](../Topic/CMFCToolBarImages::GetImageSize.md)|Recupera tanto o tamanho de imagens de barra de ferramentas que são armazenadas na memória \(tamanho da fonte\), ou o tamanho das imagens da barra de ferramentas que são desenhados na tela \(tamanho de destino\).|  
|[CMFCToolBarImages::GetImageWell](../Topic/CMFCToolBarImages::GetImageWell.md)|Retorna o identificador para o bitmap que contém todas as imagens da barra de ferramentas.|  
|[CMFCToolBarImages::GetImageWellLight](../Topic/CMFCToolBarImages::GetImageWellLight.md)||  
|[CMFCToolBarImages::GetLastImageRect](../Topic/CMFCToolBarImages::GetLastImageRect.md)||  
|[CMFCToolBarImages::GetLightPercentage](../Topic/CMFCToolBarImages::GetLightPercentage.md)||  
|[CMFCToolBarImages::GetMapTo3DColors](../Topic/CMFCToolBarImages::GetMapTo3DColors.md)||  
|[CMFCToolBarImages::GetMask](../Topic/CMFCToolBarImages::GetMask.md)||  
|[CMFCToolBarImages::GetResourceOffset](../Topic/CMFCToolBarImages::GetResourceOffset.md)|Retorna o índice da imagem para um certo ID de recurso|  
|[CMFCToolBarImages::GetScale](../Topic/CMFCToolBarImages::GetScale.md)|Taxa atual de escala de retornos de imagens sublinhada.|  
|[CMFCToolBarImages::GetTransparentColor](../Topic/CMFCToolBarImages::GetTransparentColor.md)||  
|[CMFCToolBarImages::GrayImages](../Topic/CMFCToolBarImages::GrayImages.md)|Os cinzas imagens da barra de ferramentas para fazer\-lhes o aspecto desabilitaram.|  
|[CMFCToolBarImages::Is32BitTransparencySupported](../Topic/CMFCToolBarImages::Is32BitTransparencySupported.md)|Determina se o sistema operacional suporta combinação alfa de 32 bits.|  
|[CMFCToolBarImages::IsPreMultiplyAutoCheck](../Topic/CMFCToolBarImages::IsPreMultiplyAutoCheck.md)||  
|[CMFCToolBarImages::IsRTL](../Topic/CMFCToolBarImages::IsRTL.md)|Determina se o suporte da direita para a esquerda de \(RTL\) estiver ativado.|  
|[CMFCToolBarImages::IsReadOnly](../Topic/CMFCToolBarImages::IsReadOnly.md)|Determina se as imagens da barra de ferramentas são somente leitura.|  
|[CMFCToolBarImages::IsScaled](../Topic/CMFCToolBarImages::IsScaled.md)|Informa se as imagens sublinhada são dimensionadas ou não.|  
|[CMFCToolBarImages::IsUserImagesList](../Topic/CMFCToolBarImages::IsUserImagesList.md)|Determina se este conjunto de imagens da barra de ferramentas contém imagens definidas pelo usuário.|  
|[CMFCToolBarImages::IsValid](../Topic/CMFCToolBarImages::IsValid.md)|Determina se este conjunto de imagens da barra de ferramentas contém uma imagem válido da barra de ferramentas.|  
|[CMFCToolBarImages::Load](../Topic/CMFCToolBarImages::Load.md)|A barra de ferramentas carrega imagens dos recursos do sistema ou de um arquivo.|  
|[CMFCToolBarImages::LoadStr](../Topic/CMFCToolBarImages::LoadStr.md)||  
|[CMFCToolBarImages::MapFromSysColor](../Topic/CMFCToolBarImages::MapFromSysColor.md)||  
|[CMFCToolBarImages::MapTo3dColors](../Topic/CMFCToolBarImages::MapTo3dColors.md)||  
|[CMFCToolBarImages::MapToSysColor](../Topic/CMFCToolBarImages::MapToSysColor.md)||  
|[CMFCToolBarImages::MapToSysColorAlpha](../Topic/CMFCToolBarImages::MapToSysColorAlpha.md)||  
|[CMFCToolBarImages::Mirror](../Topic/CMFCToolBarImages::Mirror.md)|Espelha horizontalmente todas as imagens da barra de ferramentas.|  
|[CMFCToolBarImages::MirrorBitmap](../Topic/CMFCToolBarImages::MirrorBitmap.md)|Espelha horizontalmente um bitmap.|  
|[CMFCToolBarImages::MirrorBitmapVert](../Topic/CMFCToolBarImages::MirrorBitmapVert.md)||  
|[CMFCToolBarImages::MirrorVert](../Topic/CMFCToolBarImages::MirrorVert.md)||  
|[CMFCToolBarImages::OnSysColorChange](../Topic/CMFCToolBarImages::OnSysColorChange.md)||  
|[CMFCToolBarImages::PrepareDrawImage](../Topic/CMFCToolBarImages::PrepareDrawImage.md)|Atribua os recursos que são necessários para desenhar uma imagem da barra de ferramentas para um tamanho especificado.|  
|[CMFCToolBarImages::Save](../Topic/CMFCToolBarImages::Save.md)|Armazena as imagens da barra de ferramentas em um arquivo se este conjunto de imagens da barra de ferramentas contém imagens definidas pelo usuário.|  
|[CMFCToolBarImages::SetAlwaysLight](../Topic/CMFCToolBarImages::SetAlwaysLight.md)||  
|[CMFCToolBarImages::SetDisabledImageAlpha](../Topic/CMFCToolBarImages::SetDisabledImageAlpha.md)|Defina o valor do canal alfa que é usado para imagens desativados.|  
|[CMFCToolBarImages::SetFadedImageAlpha](../Topic/CMFCToolBarImages::SetFadedImageAlpha.md)||  
|[CMFCToolBarImages::SetImageSize](../Topic/CMFCToolBarImages::SetImageSize.md)|Defina o tamanho de uma imagem da barra de ferramentas \(tamanho da fonte\).|  
|[CMFCToolBarImages::SetLightPercentage](../Topic/CMFCToolBarImages::SetLightPercentage.md)||  
|[CMFCToolBarImages::SetMapTo3DColors](../Topic/CMFCToolBarImages::SetMapTo3DColors.md)||  
|[CMFCToolBarImages::SetPreMultiplyAutoCheck](../Topic/CMFCToolBarImages::SetPreMultiplyAutoCheck.md)||  
|[CMFCToolBarImages::SetSingleImage](../Topic/CMFCToolBarImages::SetSingleImage.md)||  
|[CMFCToolBarImages::SetTransparentColor](../Topic/CMFCToolBarImages::SetTransparentColor.md)|Define a cor transparente imagens da barra de ferramentas.|  
|[CMFCToolBarImages::SmoothResize](../Topic/CMFCToolBarImages::SmoothResize.md)|Redimensiona suavemente imagens sublinhada.|  
|[CMFCToolBarImages::UpdateImage](../Topic/CMFCToolBarImages::UpdateImage.md)|Atualiza uma imagem definido pelo usuário da barra de ferramentas de um bitmap.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarImages::PreMultiplyAlpha](../Topic/CMFCToolBarImages::PreMultiplyAlpha.md)||  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarImages::m\_bDisableTrueColorAlpha](../Topic/CMFCToolBarImages::m_bDisableTrueColorAlpha.md)|Se o`TRUE` alfa de truecolor que se mistura de cor \(32 bits\) é desativado.|  
  
## Comentários  
 O bitmap completo de imagens de barra de ferramentas gerenciadas por `CMFCToolbarImages` consiste em um ou mais imagens pequenas da barra de ferramentas \(botões\) de um tamanho fixo.  
  
## Exemplo  
 O exemplo a seguir demonstra como configurar um objeto de `CMFCToolBarImages` usando vários métodos na classe de `CMFCToolBarImages` .  O exemplo a seguir mostra como definir o tamanho da imagem da barra de ferramentas, carregar uma imagem, e define a cor transparente de imagem.  Este trecho de código é parte de [Exemplo de demonstração do Visual Studio](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo#32](../../mfc/reference/codesnippet/CPP/cmfctoolbarimages-class_1.h)]  
[!code-cpp[NVC_MFC_VisualStudioDemo#33](../../mfc/reference/codesnippet/CPP/cmfctoolbarimages-class_2.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCToolBarImages](../../mfc/reference/cmfctoolbarimages-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxtoolbarimages.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [Classe de CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)