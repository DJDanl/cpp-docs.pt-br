---
title: "Classe de CImage | Microsoft Docs"
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
  - "CImage"
  - "ATL.CImage"
  - "ATL::CImage"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .gif, Suporte de ATL e de MFC"
  - "bitmaps [C++], Suporte de ATL e de MFC para"
  - "Classe de CImage"
  - "arquivos de GIF, Suporte de ATL e de MFC"
  - "imagens [C++], Suporte de ATL e de MFC para"
  - "arquivos JPEG"
  - "arquivos PNG, Suporte de ATL e de MFC"
  - "cor transparente"
ms.assetid: 52861e3d-bf7e-481f-a240-90e88f76c490
caps.latest.revision: 20
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CImage
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

`CImage` fornece suporte avançado de bitmap, incluindo a capacidade de salvar e carregar imagens em JPEG, GIF em, no BMP, e os formatos de \(PNG\) de formato PNG.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CImage  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CImage::CImage](../Topic/CImage::CImage.md)|o construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CImage::AlphaBlend](../Topic/CImage::AlphaBlend.md)|Exibe bitmaps que têm pixels transparentes ou semitransparent.|  
|[CImage::Attach](../Topic/CImage::Attach.md)|Anexa `HBITMAP` a um objeto de `CImage` .  Pode ser usado com bitmaps de bitmaps da seção de não DIB ou da seção de DIB.|  
|[CImage::BitBlt](../Topic/CImage::BitBlt.md)|Copia um bitmap do contexto do dispositivo de origem para este contexto atual do dispositivo.|  
|[CImage::Create](../Topic/CImage::Create.md)|Criar um bitmap da seção de DIB e anexá\-la ao objeto anteriormente construído de `CImage` .|  
|[CImage::CreateEx](../Topic/CImage::CreateEx.md)|Criar um bitmap da seção de DIB \(com parâmetros adicionais\) e anexa ele para o objeto anteriormente construído de `CImage` .|  
|[CImage::Destroy](../Topic/CImage::Destroy.md)|Dispara o bitmap do objeto de `CImage` e destrói o projeto.|  
|[CImage::Detach](../Topic/CImage::Detach.md)|Dispara o bitmap de um objeto de `CImage` .|  
|[CImage::Draw](../Topic/CImage::Draw.md)|Copia um bitmap de um retângulo fonte em um retângulo alvo.  **Desenhar** expande ou compacta o bitmap para caber se necessário as dimensões do retângulo alvo, e trata de combinação alfa e cores transparentes.|  
|[CImage::GetBits](../Topic/CImage::GetBits.md)|Recupera um ponteiro para os valores reais de pixel de bitmap.|  
|[CImage::GetBPP](../Topic/CImage::GetBPP.md)|Recupera os bits por pixel.|  
|[CImage::GetColorTable](../Topic/CImage::GetColorTable.md)|Recupera valores vermelho, verde de cor azul, \(RGB\) de um intervalo de entradas na tabela de cores.|  
|[CImage::GetDC](../Topic/CImage::GetDC.md)|Recupera o contexto de dispositivo em que o projeto atual é selecionado.|  
|[CImage::GetExporterFilterString](../Topic/CImage::GetExporterFilterString.md)|Localiza os formatos de imagem disponíveis e suas descrições.|  
|[CImage::GetHeight](../Topic/CImage::GetHeight.md)|Recupera a altura da imagem em pixels atual.|  
|[CImage::GetImporterFilterString](../Topic/CImage::GetImporterFilterString.md)|Localiza os formatos de imagem disponíveis e suas descrições.|  
|[CImage::GetMaxColorTableEntries](../Topic/CImage::GetMaxColorTableEntries.md)|Retorna o número máximo de entradas na tabela de cores.|  
|[CImage::GetPitch](../Topic/CImage::GetPitch.md)|Recupera densidade de imagem atual, em bytes.|  
|[CImage::GetPixel](../Topic/CImage::GetPixel.md)|Recupera a cor de pixel especificado *por x* e *Y. por.*|  
|[CImage::GetPixelAddress](../Topic/CImage::GetPixelAddress.md)|Recupera o endereço de um pixel dado.|  
|[CImage::GetTransparentColor](../Topic/CImage::GetTransparentColor.md)|Retorna a posição de cor transparente na tabela de cores.|  
|[CImage::GetWidth](../Topic/CImage::GetWidth.md)|Obtém a largura da imagem em pixels atual.|  
|[CImage::IsDIBSection](../Topic/CImage::IsDIBSection.md)|Determina se o bitmap anexado é uma seção de DIB.|  
|[CImage::IsIndexed](../Topic/CImage::IsIndexed.md)|Indica que as cores de um bitmap são mapeadas para uma paleta indexada.|  
|[CImage::IsNull](../Topic/CImage::IsNull.md)|Indica se um bitmap de origem é carregado no momento.|  
|[CImage::IsTransparencySupported](../Topic/CImage::IsTransparencySupported.md)|Indica se o aplicativo suporta bitmaps transparentes e foi criada para o Windows 2000 ou posterior.|  
|[CImage::Load](../Topic/CImage::Load.md)|Carregar uma imagem do arquivo especificado.|  
|[CImage::LoadFromResource](../Topic/CImage::LoadFromResource.md)|Carregar uma imagem de recursos especificado.|  
|[CImage::MaskBlt](../Topic/CImage::MaskBlt.md)|Combina os dados de cor para bitmaps de origem e de destino usando a operação especificada de máscara e de varredura.|  
|[CImage::PlgBlt](../Topic/CImage::PlgBlt.md)|Executa uma transferência de bits bloco de um retângulo em um contexto de dispositivo fonte em um paralelogramo em um contexto do dispositivo de destino.|  
|[CImage::ReleaseDC](../Topic/CImage::ReleaseDC.md)|Libera o contexto de dispositivo que foi recuperado com [CImage::GetDC](../Topic/CImage::GetDC.md).|  
|[CImage::ReleaseGDIPlus](../Topic/CImage::ReleaseGDIPlus.md)|Libera os recursos usados por GDI\+.  Deve ser chamado para liberar os recursos criados por um objeto global de `CImage` .|  
|[CImage::Save](../Topic/CImage::Save.md)|Salva uma imagem como o tipo especificado.  **Salvar** não pode especificar opções de imagem.|  
|[CImage::SetColorTable](../Topic/CImage::SetColorTable.md)|Define valores vermelho, verde azul, de cor RGB\) em um intervalo de entradas na tabela de cores da seção de DIB.|  
|[CImage::SetPixel](../Topic/CImage::SetPixel.md)|Define o pixel nas coordenadas específicas para a cor especificada.|  
|[CImage::SetPixelIndexed](../Topic/CImage::SetPixelIndexed.md)|Define o pixel nas coordenadas específicas para a cor no índice especificado de paleta.|  
|[CImage::SetPixelRGB](../Topic/CImage::SetPixelRGB.md)|Define o pixel nas coordenadas específicas para o valor vermelho, verde, azul especificado de \(RGB\).|  
|[CImage::SetTransparentColor](../Topic/CImage::SetTransparentColor.md)|Define o índice de cores ser tratada como transparente.  Somente uma cor em uma paleta pode ser transparente.|  
|[CImage::StretchBlt](../Topic/CImage::StretchBlt.md)|Copia um bitmap de um retângulo fonte em um retângulo alvo, alongando o bitmap ou compactando para ajustar as dimensões do retângulo alvo, se necessário.|  
|[CImage::TransparentBlt](../Topic/CImage::TransparentBlt.md)|Copia um bitmap com cor transparente do contexto do dispositivo de origem para este contexto atual do dispositivo.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CImage::operator HBITMAP](../Topic/CImage::operator%20HBITMAP.md)|Retorna o identificador do windows anexada ao objeto de `CImage` .|  
  
## Comentários  
 `CImage` leva bitmaps que são seções independentes de \(DIB\) de bitmap ou não; no entanto, você pode usar [Criar](../Topic/CImage::Create.md) ou [CImage::Load](../Topic/CImage::Load.md) com apenas seções de DIB.  Você pode anexar um bitmap da seção de não DIB a um objeto de `CImage` usando [Anexar](../Topic/CImage::Attach.md), mas depois você não pode usar os seguintes métodos de `CImage` , que suportam apenas bitmaps da seção de DIB:  
  
-   [GetBits](../Topic/CImage::GetBits.md)  
  
-   [GetColorTable](../Topic/CImage::GetColorTable.md)  
  
-   [GetMaxColorTableEntries](../Topic/CImage::GetMaxColorTableEntries.md)  
  
-   [GetPitch](../Topic/CImage::GetPitch.md)  
  
-   [GetPixelAddress](../Topic/CImage::GetPixelAddress.md)  
  
-   [IsIndexed](../Topic/CImage::IsIndexed.md)  
  
-   [SetColorTable](../Topic/CImage::SetColorTable.md)  
  
 Para determinar se um bitmap anexado é uma seção de DIB, chame [IsDibSection](../Topic/CImage::IsDIBSection.md)**.**  
  
> [!NOTE]
>  **Observação** Em o Visual Studio .NET 2003, essa classe mantém uma contagem do número de objetos de `CImage` criada.  Sempre que o número 0, vá para a função é chamada [GdiplusShutdown](_gdiplus_func_gdiplusshutdown_) automaticamente para liberar os recursos usados por GDI\+.  Isso garante que todos os objetos de `CImage` criados por DLL direta ou indiretamente sempre serão destruídos corretamente e que **GdiplusShutdown** não é chamado de `DllMain`.  
  
> [!NOTE]
>  Usar objetos globais de `CImage` em uma DLL não é recomendada.  Se você precisar usar um objeto global de `CImage` em uma DLL chamada, [CImage::ReleaseGDIPlus](../Topic/CImage::ReleaseGDIPlus.md) para definir explicitamente os recursos usados por GDI\+.  
  
 `CImage` não pode ser selecionado no novo [CDC](../Topic/CDC%20Class.md).  `CImage` criar seu próprio **HDC** para a imagem.  Porque `HBITMAP` só pode ser selecionado em um **HDC** de cada vez, `HBITMAP` associado com `CImage` não pode ser selecionado em outro **HDC**.  Se você precisar `CDC`, recuperar **HDC** de `CImage` e dê\-o a [CDC::FromHandle](../Topic/CDC::FromHandle.md).  
  
## Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#70](../../atl-mfc-shared/codesnippet/CPP/cimage-class_1.cpp)]  
  
 Quando você usar `CImage` em um projeto MFC, note que as funções de membro em seu projeto aguardam um ponteiro para um objeto de [CBitmap](../../mfc/reference/cbitmap-class.md) .  Se você desejar usar `CImage` com uma função, como [CMenu::AppendMenu](../Topic/CMenu::AppendMenu.md), use [CBitmap::FromHandle](../Topic/CBitmap::FromHandle.md), passe seu `CImage``HBITMAP`, e use `CBitmap*`retornado.  
  
## Exemplo  
 [!code-cpp[NVC_ATLMFC_Utilities#71](../../atl-mfc-shared/codesnippet/CPP/cimage-class_2.cpp)]  
  
 Com `CImage`, você tem acesso a bit reais de uma seção de DIB.  Você pode usar um objeto de `CImage` em qualquer lugar que você usou anteriormente Win32 HBITMAP ou a seção de DIB.  
  
> [!NOTE]
>  Os seguintes métodos de `CImage` têm restrições em seu uso:  
  
|Método|Limitação|  
|------------|---------------|  
|[PlgBlt](../Topic/CImage::PlgBlt.md)|Works somente com Windows NT 4.0 ou posterior.  Não funcionará em aplicativos que executam Windows 95 no \/98 ou posterior.|  
|[MaskBlt](../Topic/CImage::MaskBlt.md)|Works somente com Windows NT 4.0 ou posterior.  Não funcionará em aplicativos que executam Windows 95 no \/98 ou posterior.|  
|[AlphaBlend](../Topic/CImage::AlphaBlend.md)|Works somente com Windows 2000, Windows 98, e sistemas operacionais posteriores.|  
|[TransparentBlt](../Topic/CImage::TransparentBlt.md)|Works somente com Windows 2000, Windows 98, e sistemas operacionais posteriores.|  
|[Desenho](../Topic/CImage::Draw.md)|Oferece suporte à transparência com apenas Windows 2000, Windows 98, e sistemas operacionais posteriores.|  
  
 Consulte [Limitações de CImage com sistemas operacionais anteriores](../../mfc/cimage-limitations-with-earlier-operating-systems.md) para informações mais detalhadas sobre as restrições em esses métodos.  
  
 Você pode usar `CImage` MFC ou de ATL.  
  
> [!NOTE]
>  Quando você cria um projeto usando `CImage`, você deve definir `CString` antes que você inclua `atlimage.h`.  Se seu projeto usar ATL sem MFC, inclua `atlstr.h` antes que você inclua `atlimage.h`.  Se seu projeto usar o MFC \(ou se é um projeto de ATL com suporte MFC\), inclua `afxstr.h` antes que você inclua `atlimage.h`.  
>   
>  Também, você deve incluir `atlimage.h` antes que você inclua `atlimpl.cpp`.  Para fazer isso, inclua facilmente `atlimage.h` em seu `stdafx.h`.  
  
## Requisitos  
 **Cabeçalho:** atlimage.h  
  
## Consulte também  
 [exemplo de MMXSwarm](../../top/visual-cpp-samples.md)   
 [exemplo de SimpleImage](../../top/visual-cpp-samples.md)   
 [Device\-Independent Bitmaps](http://msdn.microsoft.com/library/windows/desktop/dd183562)   
 [CreateDIBSection](http://msdn.microsoft.com/library/windows/desktop/dd183494)   
 [Componentes da área de trabalho COM ATL](../../atl/atl-com-desktop-components.md)