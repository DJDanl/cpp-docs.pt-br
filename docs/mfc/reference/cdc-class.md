---
title: Classe CDC | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDC
dev_langs:
- C++
helpviewer_keywords:
- Windows [C++], device contexts
- Windows 95 [C++], screen coordinates
- device contexts [C++], CDC class
- screen coordinates in device contexts
- coordinates in Windows 95/98 [C++]
- Windows 98 [C++], screen coordinates
- CDC class
ms.assetid: 715b3334-cb2b-4c9c-8067-02eb7c66c8b2
caps.latest.revision: 21
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 80ccd3f8bed6bd74e22d4db5e176ee50528d3187
ms.lasthandoff: 02/25/2017

---
# <a name="cdc-class"></a>Classe CDC
Define uma classe de objetos de contexto de dispositivo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDC : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDC::CDC](#cdc)|Constrói um objeto `CDC`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDC::AbortDoc](#abortdoc)|Encerra o trabalho de impressão atual, Apagar tudo o que o aplicativo foi escrito para o dispositivo desde a última chamada do `StartDoc` função de membro.|  
|[CDC::AbortPath](#abortpath)|Fecha e descarta todos os caminhos no contexto do dispositivo.|  
|[CDC::AddMetaFileComment](#addmetafilecomment)|Copia o comentário de um buffer em um metarquivo aprimorado de formato especificado.|  
|[CDC::AlphaBlend](#alphablend)|Exibe a bitmaps que possuem transparentes ou semitransparentes pixels.|  
|[CDC::AngleArc](#anglearc)|Desenha um segmento de linha e um arco e move a posição atual para o ponto final do arco.|  
|[CDC::ARC](#arc)|Desenha um arco elíptico.|  
|[CDC::ArcTo](#arcto)|Desenha um arco elíptico. Essa função é semelhante ao `Arc`, exceto que a posição atual é atualizada.|  
|[CDC::Attach](#attach)|Anexa um contexto de dispositivo do Windows para este `CDC` objeto.|  
|[CDC:: beginpath](#beginpath)|Abre um colchete de caminho no contexto do dispositivo.|  
|[CDC::BitBlt](#bitblt)|Copia um bitmap em um contexto de dispositivo especificado.|  
|[CDC::chord](#chord)|Desenha um acorde (uma figura fechada limitada pela interseção de uma elipse e um segmento de linha).|  
|[CDC::CloseFigure](#closefigure)|Fecha uma figura aberta em um caminho.|  
|[CDC::CreateCompatibleDC](#createcompatibledc)|Cria um contexto de dispositivo de memória que é compatível com o outro contexto de dispositivo. Você pode usá-lo para preparar imagens na memória.|  
|[CDC::CreateDC](#createdc)|Cria um contexto de dispositivo para um dispositivo específico.|  
|[CDC::CreateIC](#createic)|Cria um contexto de informações para um dispositivo específico. Isso fornece uma maneira rápida de obter informações sobre o dispositivo sem criar um contexto de dispositivo.|  
|[CDC::DeleteDC](#deletedc)|Exclui o contexto de dispositivo do Windows associado a esse `CDC` objeto.|  
|[CDC::DeleteTempMap](#deletetempmap)|Chamando o `CWinApp` manipulador de tempo ocioso para excluir qualquer temporário `CDC` objeto criado pelo `FromHandle`. Também desconecta o contexto do dispositivo.|  
|[CDC::Detach](#detach)|Desanexa o contexto de dispositivo do Windows neste `CDC` objeto.|  
|[CDC::DPtoHIMETRIC](#dptohimetric)|Converte unidades de dispositivo em **HIMETRIC** unidades.|  
|[CDC::DPtoLP](#dptolp)|Converte unidades de dispositivo em unidades lógicas.|  
|[CDC::Draw3dRect](#draw3drect)|Desenha um retângulo tridimensional.|  
|[CDC::DrawDragRect](#drawdragrect)|Apaga e redesenhar um retângulo que é arrastada.|  
|[CDC::DrawEdge](#drawedge)|Desenha as bordas de um retângulo.|  
|[CDC::DrawEscape](#drawescape)|Acessa os recursos de um monitor de vídeo que não estão diretamente disponíveis por meio da interface gráfica de dispositivo (GDI) de desenho.|  
|[CDC::DrawFocusRect](#drawfocusrect)|Desenha um retângulo no estilo usado para indicar o foco.|  
|[CDC::DrawFrameControl](#drawframecontrol)|Desenhe um controle de quadro.|  
|[CDC::DrawIcon](#drawicon)|Desenha um ícone.|  
|[CDC::DrawState](#drawstate)|Exibe uma imagem e aplica um efeito visual para indicar um estado.|  
|[CDC::DrawText](#drawtext)|Desenha formatado o texto no retângulo especificado.|  
|[CDC::DrawTextEx](#drawtextex)|Desenha formatado o texto no retângulo especificado usando formatos adicionais.|  
|[CDC::Ellipse](#ellipse)|Desenha uma elipse.|  
|[CDC::EndDoc](#enddoc)|Termina um trabalho de impressão iniciado pela `StartDoc` função de membro.|  
|[CDC::EndPage](#endpage)|Informa o driver de dispositivo uma página está terminando.|  
|[CDC::EndPath](#endpath)|Fecha um colchete de caminho e seleciona o caminho definido pelo suporte para o contexto de dispositivo.|  
|[CDC:: enumobjects](#enumobjects)|Enumera as canetas e pincéis disponíveis em um contexto de dispositivo.|  
|[CDC::escape](#escape)|Permite que aplicativos acessem os recursos que não estão diretamente disponíveis de um determinado dispositivo através de GDI. Também permite acesso a funções de escape do Windows. Escape de chamadas feitas por um aplicativo são convertidas e enviadas para o driver de dispositivo.|  
|[CDC::ExcludeClipRect](#excludecliprect)|Cria uma nova região de recorte consiste da região de recorte existente, menos o retângulo especificado.|  
|[CDC::ExcludeUpdateRgn](#excludeupdatergn)|Impede o desenho nas áreas inválidos de uma janela com a exclusão de uma região atualizada na janela de uma região de recorte.|  
|[CDC::ExtFloodFill](#extfloodfill)|Preenche uma área com o pincel atual. Fornece mais flexibilidade do que o [CDC::FloodFill](#floodfill) função de membro.|  
|[CDC::ExtTextOut](#exttextout)|Grava uma cadeia de caracteres dentro de uma região retangular usando a fonte atualmente selecionada.|  
|[CDC::FillPath](#fillpath)|Fecha qualquer figuras abertas no caminho atual e preenche o interior do caminho usando o pincel atual e o modo de preenchimento de polígono.|  
|[CDC::FillRect](#fillrect)|Preenche um determinado retângulo usando um pincel específico.|  
|[CDC::FillRgn](#fillrgn)|Preenche uma região específica com o pincel especificado.|  
|[CDC::FillSolidRect](#fillsolidrect)|Preenche um retângulo com uma cor sólida.|  
|[CDC::FlattenPath](#flattenpath)|Transforma qualquer curvas no caminho selecionado no contexto de dispositivo atual e transforma cada curva em uma sequência de linhas.|  
|[CDC::FloodFill](#floodfill)|Preenche uma área com o pincel atual.|  
|[CDC::FrameRect](#framerect)|Desenha uma borda ao redor de um retângulo.|  
|[CDC::FrameRgn](#framergn)|Desenha uma borda ao redor de uma região específica usando um pincel.|  
|[CDC::FromHandle](#fromhandle)|Retorna um ponteiro para um `CDC` objeto quando recebe um identificador para um contexto de dispositivo. Se um `CDC` objeto não está anexado ao identificador, um temporário `CDC` objeto é criado e anexado.|  
|[CDC::GetArcDirection](#getarcdirection)|Retorna a direção do arco atual para o contexto do dispositivo.|  
|[CDC::GetAspectRatioFilter](#getaspectratiofilter)|Recupera a configuração para o filtro de taxa de proporção atual.|  
|[CDC::GetBkColor](#getbkcolor)|Recupera a cor de plano de fundo atual.|  
|[CDC::GetBkMode](#getbkmode)|Recupera o modo de plano de fundo.|  
|[CDC::GetBoundsRect](#getboundsrect)|Retorna o retângulo delimitador acumulado atual para o contexto de dispositivo especificado.|  
|[CDC::GetBrushOrg](#getbrushorg)|Recupera a origem do pincel atual.|  
|[CDC::GetCharABCWidths](#getcharabcwidths)|Recupera as larguras, em unidades lógicas, de caracteres consecutivos em um determinado intervalo da fonte atual.|  
|[CDC::GetCharABCWidthsI](#getcharabcwidthsi)|Recupera as larguras, em unidades lógicas, de índices de glifo consecutivas em um intervalo especificado de fonte TrueType atual.|  
|[CDC::GetCharacterPlacement](#getcharacterplacement)|Recupera vários tipos de informações em uma cadeia de caracteres.|  
|[CDC::GetCharWidth](#getcharwidth)|Recupera as frações larguras de caracteres consecutivos em um determinado intervalo de fonte atual.|  
|[CDC::GetCharWidthI](#getcharwidthi)|Recupera as larguras, em coordenadas lógicas, de índices de glifo consecutivas em um intervalo especificado da fonte atual.|  
|[CDC::GetClipBox](#getclipbox)|Recupera as dimensões do retângulo delimitador tightest em torno do limite do recorte atual.|  
|[CDC::GetColorAdjustment](#getcoloradjustment)|Recupera os valores de ajuste de cor para o contexto de dispositivo.|  
|[CDC::GetCurrentBitmap](#getcurrentbitmap)|Retorna um ponteiro para selecionado no momento `CBitmap` objeto.|  
|[CDC::GetCurrentBrush](#getcurrentbrush)|Retorna um ponteiro para selecionado no momento `CBrush` objeto.|  
|[CDC::GetCurrentFont](#getcurrentfont)|Retorna um ponteiro para selecionado no momento `CFont` objeto.|  
|[CDC::GetCurrentPalette](#getcurrentpalette)|Retorna um ponteiro para selecionado no momento `CPalette` objeto.|  
|[CDC::GetCurrentPen](#getcurrentpen)|Retorna um ponteiro para selecionado no momento `CPen` objeto.|  
|[CDC::GetCurrentPosition](#getcurrentposition)|Recupera a posição atual da caneta (em coordenadas lógicas).|  
|[CDC::GetDCBrushColor](#getdcbrushcolor)|Recupera a cor atual do pincel.|  
|[CDC::GetDCPenColor](#getdcpencolor)|Recupera a cor atual da caneta.|  
|[CDC::GetDeviceCaps](#getdevicecaps)|Recupera um tipo especificado de informações específicas de dispositivo sobre recursos de um dispositivo de exibição em questão.|  
|[CDC::GetFontData](#getfontdata)|Recupera informações de métricas de fonte de um arquivo de fonte escalonável. As informações para recuperar são identificadas, especificando um deslocamento para o arquivo de fonte e o tamanho das informações a retornar.|  
|[CDC::GetFontLanguageInfo](#getfontlanguageinfo)|Retorna informações sobre a fonte atualmente selecionada para o contexto de exibição especificado.|  
|[CDC::GetGlyphOutline](#getglyphoutline)|Recupera a curva de estrutura de tópicos ou um bitmap de um caractere de estrutura de tópicos na fonte atual.|  
|[CDC::GetGraphicsMode](#getgraphicsmode)|Recupera o modo gráfico atual para o contexto de dispositivo especificado.|  
|[CDC::GetHalftoneBrush](#gethalftonebrush)|Recupera um pincel de meio-tom.|  
|[CDC::GetKerningPairs](#getkerningpairs)|Recupera o caractere kerning de pares para a fonte atualmente selecionada no contexto do dispositivo especificado.|  
|[CDC::GetLayout](#getlayout)|Recupera o layout de um contexto de dispositivo (DC). O layout pode ser deixado ou para a direita (padrão) ou da direita para esquerda (espelhado).|  
|[CDC::GetMapMode](#getmapmode)|Recupera o modo de mapeamento atual.|  
|[CDC::GetMiterLimit](#getmiterlimit)|Retorna o limite de Malhete para o contexto do dispositivo.|  
|[CDC::GetNearestColor](#getnearestcolor)|Recupera a cor de lógica mais próxima para uma cor especificada lógica que pode representar um determinado dispositivo.|  
|[CDC::GetOutlineTextMetrics](#getoutlinetextmetrics)|Recupera informações de métricas de fonte para fontes TrueType.|  
|[CDC::GetOutputCharWidth](#getoutputcharwidth)|Recupera as larguras de caracteres individuais em um grupo de caracteres consecutivos da fonte atual usando o contexto de dispositivo de saída.|  
|[CDC::GetOutputTabbedTextExtent](#getoutputtabbedtextextent)|Calcula a largura e altura de uma cadeia de caracteres no contexto de dispositivo de saída.|  
|[CDC::GetOutputTextExtent](#getoutputtextextent)|Calcula a largura e altura de uma linha de texto no contexto de dispositivo de saída usando a fonte atual para determinar as dimensões.|  
|[CDC::GetOutputTextMetrics](#getoutputtextmetrics)|Recupera as métricas para a fonte atual do contexto do dispositivo de saída.|  
|[CDC::GetPath](#getpath)|Recupera as coordenadas definindo os pontos de extremidade de linhas e pontos de controle de curvas encontrados no caminho selecionado no contexto de dispositivo.|  
|[CDC::GetPixel](#getpixel)|Recupera o valor de cor RGB do pixel no ponto especificado.|  
|[CDC::GetPolyFillMode](#getpolyfillmode)|Recupera o modo de preenchimento de polígono atual.|  
|[CDC::GetROP2](#getrop2)|Recupera o modo de desenho atual.|  
|[CDC::GetSafeHdc](#getsafehdc)|Retorna [CDC::m_hDC](#m_hdc), o contexto de dispositivo de saída.|  
|[CDC::GetStretchBltMode](#getstretchbltmode)|Recupera o modo atual alongando bitmap.|  
|[CDC::GetTabbedTextExtent](#gettabbedtextextent)|Calcula a largura e altura de uma cadeia de caracteres no contexto de dispositivo do atributo.|  
|[CDC::GetTextAlign](#gettextalign)|Recupera os sinalizadores de alinhamento de texto.|  
|[CDC::GetTextCharacterExtra](#gettextcharacterextra)|Recupera a configuração atual para a quantidade de espaçamento intercharacter.|  
|[CDC::GetTextColor](#gettextcolor)|Recupera a cor do texto.|  
|[CDC::getTextExtent](#gettextextent)|Calcula a largura e altura de uma linha de texto no contexto de dispositivo de atributo usando a fonte atual para determinar as dimensões.|  
|[CDC::GetTextExtentExPointI](#gettextextentexpointi)|Recupera o número de caracteres em uma cadeia de caracteres especificada que caiba dentro de um espaço especificado e preenche uma matriz com a extensão do texto para cada um desses caracteres.|  
|[CDC::GetTextExtentPointI](#gettextextentpointi)|Recupera a largura e altura da matriz especificada de índices de glifo.|  
|[CDC::GetTextFace](#gettextface)|Copia o nome de face da fonte atual em um buffer como uma cadeia de caracteres terminada em nulo.|  
|[CDC::GetTextMetrics](#gettextmetrics)|Recupera as métricas para a fonte atual do contexto de dispositivo de atributo.|  
|[CDC::GetViewportExt](#getviewportext)|Recupera as extensões x e y do visor.|  
|[CDC::GetViewportOrg](#getviewportorg)|Recupera as coordenadas x e y da origem do visor.|  
|[CDC::GetWindow](#getwindow)|Retorna a janela associada com o contexto de dispositivo de exibição.|  
|[CDC::GetWindowExt](#getwindowext)|Recupera as extensões x e y da janela associada.|  
|[CDC::GetWindowOrg](#getwindoworg)|Recupera as coordenadas x e y da origem da janela associada.|  
|[CDC::GetWorldTransform](#getworldtransform)|Recupera o espaço do mundo atual para transformação de espaço da página.|  
|[CDC::GradientFill](#gradientfill)|Preenche as estruturas de triângulo retângulo com uma cor gradating.|  
|[CDC:: graystring](#graystring)|Desenha esmaecida texto (esmaecido) no local determinado.|  
|[CDC::HIMETRICtoDP](#himetrictodp)|Converte **HIMETRIC** unidades em unidades de dispositivo.|  
|[CDC::HIMETRICtoLP](#himetrictolp)|Converte **HIMETRIC** unidades em unidades lógicas.|  
|[CDC::IntersectClipRect](#intersectcliprect)|Cria uma nova região de recorte formando a interseção de região atual e um retângulo.|  
|[CDC::InvertRect](#invertrect)|Inverte o conteúdo de um retângulo.|  
|[CDC::InvertRgn](#invertrgn)|Inverte as cores em uma região.|  
|[CDC::IsPrinting](#isprinting)|Determina se o contexto do dispositivo está sendo usado para impressão.|  
|[CDC::lineTo](#lineto)|Desenha uma linha da posição atual até, mas não incluindo, um ponto.|  
|[CDC::LPtoDP](#lptodp)|Converte unidades lógicas em unidades de dispositivo.|  
|[CDC::LPtoHIMETRIC](#lptohimetric)|Converte unidades lógicas em **HIMETRIC** unidades.|  
|[CDC::MaskBlt](#maskblt)|Combina os dados de cor para bitmaps de origem e de destino usando a máscara de determinado e a operação de varredura.|  
|[CDC::ModifyWorldTransform](#modifyworldtransform)|Altera a transformação do mundo para um contexto de dispositivo usando o modo especificado.|  
|[CDC::MoveTo](#moveto)|Move a posição atual.|  
|[CDC::OffsetClipRgn](#offsetcliprgn)|Move a região de recorte de determinado dispositivo.|  
|[CDC::OffsetViewportOrg](#offsetviewportorg)|Modifica a origem do visor em relação as coordenadas da origem visor atual.|  
|[CDC::OffsetWindowOrg](#offsetwindoworg)|Modifica a origem da janela em relação as coordenadas da origem da janela atual.|  
|[CDC::PaintRgn](#paintrgn)|Preenche uma região com o pincel selecionado.|  
|[CDC::PatBlt](#patblt)|Cria um padrão de bit.|  
|[CDC::Pie](#pie)|Desenha uma fatia em forma de pizza.|  
|[CDC::PlayMetaFile](#playmetafile)|Reproduz o conteúdo do metarquivo especificado em determinado dispositivo. A versão avançada do `PlayMetaFile` exibe a imagem armazenada em determinado metarquivo aprimorado de formato. O metarquivo pode ser executado várias vezes.|  
|[CDC::PlgBlt](#plgblt)|Executa uma transferência de bloco de bits dos bits de dados de cor do retângulo especificado no contexto do dispositivo de origem para paralelogramo especificado no contexto de determinado dispositivo.|  
|[CDC::PolyBezier](#polybezier)|Desenha um ou mais splines Bzier. A posição atual não é usada nem atualizada.|  
|[CDC::PolyBezierTo](#polybezierto)|Desenha um ou mais splines Bzier e move a posição atual para o ponto final da última Bzier spline.|  
|[CDC::PolyDraw](#polydraw)|Desenha um conjunto de segmentos de linha e Bzier splines. Essa função atualiza a posição atual.|  
|[CDC::Polygon](#polygon)|Desenha um polígono consiste em dois ou mais pontos (vértices) conectados por linhas.|  
|[CDC::Polyline](#polyline)|Desenha um conjunto de segmentos de linha Conectar pontos especificados.|  
|[CDC::PolylineTo](#polylineto)|Desenha uma ou mais linhas retas e move a posição atual para o ponto final da última linha.|  
|[CDC::PolyPolygon](#polypolygon)|Cria dois ou mais polígonos que são preenchidos usando o modo de preenchimento de polígono atual. Os polígonos podem ser separados ou eles podem se sobrepor.|  
|[CDC::PolyPolyline](#polypolyline)|Desenha várias séries de segmentos de linha conectados. A posição atual não é usada nem atualizada por essa função.|  
|[CDC::PtVisible](#ptvisible)|Especifica se o determinado ponto está dentro da região de recorte.|  
|[CDC::RealizePalette](#realizepalette)|Entradas de paleta na paleta lógica atual é mapeado para a paleta do sistema.|  
|[CDC::Rectangle](#rectangle)|Desenha um retângulo usando a caneta atual e a preenche usando o pincel atual.|  
|[CDC::RectVisible](#rectvisible)|Determina se qualquer parte do retângulo especificado está dentro da região de recorte.|  
|[CDC::ReleaseAttribDC](#releaseattribdc)|Versões `m_hAttribDC`, o contexto de dispositivo do atributo.|  
|[CDC::ReleaseOutputDC](#releaseoutputdc)|Versões `m_hDC`, o contexto de dispositivo de saída.|  
|[CDC::ResetDC](#resetdc)|Atualizações de `m_hAttribDC` contexto de dispositivo.|  
|[CDC::RestoreDC](#restoredc)|Restaura o contexto de dispositivo para um estado anterior salvo com `SaveDC`.|  
|[CDC::RoundRect](#roundrect)|Desenha um retângulo com cantos arredondados usando a caneta atual e preenchido usando o pincel atual.|  
|[CDC::SaveDC](#savedc)|Salva o estado atual do contexto do dispositivo.|  
|[CDC::ScaleViewportExt](#scaleviewportext)|Modifica a extensão do visor em relação os valores atuais.|  
|[CDC::ScaleWindowExt](#scalewindowext)|Modifica as extensões de janela em relação os valores atuais.|  
|[CDC::ScrollDC](#scrolldc)|Rola um retângulo de bits horizontalmente e verticalmente.|  
|[CDC::SelectClipPath](#selectclippath)|Seleciona o caminho atual como uma região de recorte para o contexto de dispositivo, combinando a nova região com qualquer região de recorte existente usando o modo especificado.|  
|[CDC::SelectClipRgn](#selectcliprgn)|Combina a região determinada com a região de recorte atual usando o modo especificado.|  
|[CDC::SelectObject](#selectobject)|Seleciona um objeto de desenho GDI, como uma caneta.|  
|[CDC::SelectPalette](#selectpalette)|Seleciona a paleta lógica.|  
|[CDC::SelectStockObject](#selectstockobject)|Seleciona uma do pincéis, canetas ações predefinidas ou fontes fornecidas pelo Windows.|  
|[CDC:: SetAbortProc](#setabortproc)|Define uma função de retorno de chamada fornecido pelo programador Windows chama se um trabalho de impressão deve ser anulado.|  
|[CDC::SetArcDirection](#setarcdirection)|Define a direção de desenho para ser usado por funções arco e retângulo.|  
|[CDC::SetAttribDC](#setattribdc)|Conjuntos de `m_hAttribDC`, o contexto de dispositivo do atributo.|  
|[CDC::SetBkColor](#setbkcolor)|Define a cor de plano de fundo atual.|  
|[CDC::SetBkMode](#setbkmode)|Define o modo de plano de fundo.|  
|[CDC::SetBoundsRect](#setboundsrect)|Controla o acúmulo de informações de retângulo delimitador para o contexto de dispositivo especificado.|  
|[CDC::SetBrushOrg](#setbrushorg)|Especifica a origem para o próximo pincel selecionado em um contexto de dispositivo.|  
|[CDC::SetColorAdjustment](#setcoloradjustment)|Define os valores de ajuste de cor para o contexto de dispositivo usando os valores especificados.|  
|[CDC::SetDCBrushColor](#setdcbrushcolor)|Define a cor do pincel atual.|  
|[CDC::SetDCPenColor](#setdcpencolor)|Define a cor da caneta atual.|  
|[CDC::SetGraphicsMode](#setgraphicsmode)|Define o modo de gráfico atual para o contexto de dispositivo especificado.|  
|[CDC::SetLayout](#setlayout)|Altera o layout de um contexto de dispositivo (DC).|  
|[CDC::SetMapMode](#setmapmode)|Define o modo atual do mapeamento.|  
|[CDC::SetMapperFlags](#setmapperflags)|Altera o algoritmo usado pelo mapeador de fonte quando ele mapeia fontes lógicas fontes físicas.|  
|[CDC::SetMiterLimit](#setmiterlimit)|Define o limite para o comprimento do mitre associações para o contexto de dispositivo.|  
|[CDC::SetOutputDC](#setoutputdc)|Conjuntos de `m_hDC`, o contexto de dispositivo de saída.|  
|[CDC::SetPixel](#setpixel)|Define o pixel no ponto especificado para a aproximação mais próxima da cor especificada.|  
|[CDC::SetPixelV](#setpixelv)|Define o pixel nas coordenadas especificadas para a aproximação mais próxima da cor especificada. `SetPixelV`é mais rápido que `SetPixel` porque ele não precisa retornar o valor de cor do ponto realmente pintado.|  
|[CDC::SetPolyFillMode](#setpolyfillmode)|Define o modo de preenchimento de polígono.|  
|[CDC::SetROP2](#setrop2)|Define o modo de desenho atual.|  
|[CDC::SetStretchBltMode](#setstretchbltmode)|Define o modo de alongamento de bitmap.|  
|[CDC::SetTextAlign](#settextalign)|Define os sinalizadores de alinhamento de texto.|  
|[CDC::SetTextCharacterExtra](#settextcharacterextra)|Define a quantidade de espaçamento intercharacter.|  
|[CDC::SetTextColor](#settextcolor)|Define a cor do texto.|  
|[CDC::SetTextJustification](#settextjustification)|Adiciona espaço para os caracteres de quebra em uma cadeia de caracteres.|  
|[CDC::SetViewportExt](#setviewportext)|Define as extensões x e y do visor.|  
|[CDC::SetViewportOrg](#setviewportorg)|Define a origem do visor.|  
|[CDC::SetWindowExt](#setwindowext)|Define as extensões x e y da janela associada.|  
|[CDC::SetWindowOrg](#setwindoworg)|Define a origem da janela do contexto do dispositivo.|  
|[CDC::SetWorldTransform](#setworldtransform)|Define o espaço do mundo atual para transformação de espaço da página.|  
|[CDC::StartDoc](#startdoc)|Informa o driver de dispositivo que está iniciando um novo trabalho de impressão.|  
|[CDC::StartPage](#startpage)|Informa o driver de dispositivo que está iniciando uma nova página.|  
|[CDC::StretchBlt](#stretchblt)|Move um bitmap de um retângulo de origem e o dispositivo em um retângulo de destino, alongando-o ou compactando-o se necessário, para se ajustar às dimensões do retângulo de destino.|  
|[CDC::StrokeAndFillPath](#strokeandfillpath)|Fecha qualquer figuras abertas em um caminho, bater o contorno do caminho usando a caneta atual e preenche o interior usando o pincel atual.|  
|[CDC::StrokePath](#strokepath)|Renderiza o caminho especificado usando a caneta atual.|  
|[CDC::TabbedTextOut](#tabbedtextout)|Grava uma cadeia de caracteres em um local especificado, expandindo o guias para os valores especificados em uma matriz de posições de parada de tabulação.|  
|[CDC::TextOut](#textout)|Grava uma cadeia de caracteres em um local especificado usando a fonte atualmente selecionada.|  
|[CDC::TransparentBlt](#transparentblt)|Transfere um bloco de bits de dados de cor do contexto do dispositivo de origem especificada em um contexto de dispositivo de destino, transparente na transferência de processamento de uma cor especificada.|  
|[CDC::UpdateColors](#updatecolors)|Atualizações de cores a área do cliente do contexto do dispositivo combinando atual na área do cliente na paleta do sistema em uma base por pixels.|  
|[CDC::WidenPath](#widenpath)|Redefine o caminho atual como a área que deve ser pintada se o caminho foram traçado usando a caneta atualmente selecionada no contexto de dispositivo.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDC::Operator HDC](#operator_hdc)|Recupera o identificador de contexto do dispositivo.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDC::m_hAttribDC](#m_hattribdc)|O contexto de dispositivo de atributo usado por este `CDC` objeto.|  
|[CDC::m_hDC](#m_hdc)|O contexto de dispositivo de saída usado por este `CDC` objeto.|  
  
## <a name="remarks"></a>Comentários  
 O `CDC` objeto fornece funções de membro para trabalhar com um contexto de dispositivo, como um monitor ou impressora, bem como os membros para trabalhar com um contexto de exibição associado a área cliente de uma janela.  
  
 Fazer todo o desenho por meio do membro funções de uma `CDC` objeto. A classe fornece funções de membro para operações de contexto de dispositivo, trabalhando com ferramentas, seleção de objetos GDI (interface) do dispositivo gráfico de tipo seguro, de desenho e trabalhar com cores e paletas. Ele também fornece funções de membro para obter e definir atributos de desenho de mapeamento, trabalhando com o visor, trabalhando com a extensão da janela, convertendo de coordenadas, trabalhando com regiões de recorte, desenhando linhas e desenhando formas simples, elipses e polígonos. Funções de membro também são fornecidas para desenho de texto, trabalhar com fontes, usando escapes de impressora, rolagem e reproduzindo metarquivos.  
  
 Para usar um `CDC` objeto construí-la e, em seguida, chamar seu membro funções que funções do Windows que usar contextos de dispositivo.  
  
> [!NOTE]
>  No Windows 95/98, todas as coordenadas de tela são limitadas a 16 bits. Portanto, uma `int` passado para um `CDC` função de membro deve estar no intervalo de – 32768 a 32767.  
  
 Para usos específicos, a biblioteca Microsoft Foundation Class fornece várias classes derivadas de `CDC` . `CPaintDC`encapsula as chamadas para `BeginPaint` e `EndPaint`. `CClientDC`gerencia um contexto de exibição associado a área cliente da janela. `CWindowDC`gerencia um contexto de exibição associado a uma janela inteira, incluindo seu quadro e controles. `CMetaFileDC`associa um contexto de dispositivo com um metarquivo.  
  
 `CDC`fornece duas funções de membro, [GetLayout](#getlayout) e [SetLayout](#setlayout), para inverter o layout de um contexto de dispositivo que não herda seu layout de uma janela. Essa orientação da direita para a esquerda é necessária para aplicativos escritos para culturas, como árabe ou hebraico, onde o layout de caractere não é o padrão europeu.  
  
 `CDC`contém dois contextos de dispositivo, [m_hDC](#m_hdc) e [m_hAttribDC](#m_hattribdc), que, na criação de um `CDC` de objeto, consulte o mesmo dispositivo. `CDC`direciona todas as chamadas de saída GDI para `m_hDC` e a maioria dos atributos GDI chama `m_hAttribDC`. (Um exemplo de uma chamada de atributo é `GetTextColor`, enquanto `SetTextColor` é uma chamada de saída.)  
  
 Por exemplo, a estrutura usa esses contextos de dois dispositivo para implementar um `CMetaFileDC` objeto que envia saída para um metarquivo ao ler os atributos de um dispositivo físico. Visualização de impressão é implementada no framework de maneira semelhante. Você também pode usar os contextos de dois dispositivo de forma semelhante em seu código específico do aplicativo.  
  
 Há vezes quando você pode precisar de informações de métrica de texto tanto o `m_hDC` e `m_hAttribDC` contextos de dispositivo. Os seguintes pares de funções fornecem esse recurso:  
  
|Usa m_hAttribDC|Usa m_hDC|  
|-----------------------|-----------------|  
|[GetTextExtent](#gettextextent)|[GetOutputTextExtent](#getoutputtextextent)|  
|[GetTabbedTextExtent](#gettabbedtextextent)|[GetOutputTabbedTextExtent](#getoutputtabbedtextextent)|  
|[GetTextMetrics](#gettextmetrics)|[GetOutputTextMetrics](#getoutputtextmetrics)|  
|[GetCharWidth](#getcharwidth)|[GetOutputCharWidth](#getoutputcharwidth)|  
  
 Para obter mais informações sobre `CDC`, consulte [contextos de dispositivo](../../mfc/device-contexts.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CDC`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="a-nameabortdoca--cdcabortdoc"></a><a name="abortdoc"></a>CDC::AbortDoc  
 Encerra o trabalho de impressão atual e Apaga tudo o que o aplicativo foi escrito para o dispositivo desde a última chamada para o [StartDoc](#startdoc) função de membro.  
  
```  
int AbortDoc();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor maior que ou igual a 0 se for bem-sucedido, ou um valor negativo se tiver ocorrido um erro. A lista a seguir mostra os valores de erro comuns e seus significados:  
  
- **SP_ERROR** erro geral.  
  
- **SP_OUTOFDISK** não há espaço em disco está disponível atualmente para o spool e não há mais espaço se tornará disponível.  
  
- **SP_OUTOFMEMORY** não há memória suficiente está disponível para o spool.  
  
- **SP_USERABORT** o usuário concluiu o trabalho por meio do Gerenciador de impressão.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro substitui o `ABORTDOC` escape de impressora.  
  
 **AbortDoc** deve ser usada para encerrar o seguinte:  
  
-   Operações de impressão que não especificam uma função abort usando [SetAbortProc](#setabortproc).  
  
-   Operações de impressão que ainda não atingiu seu primeiro **NEWFRAME** ou **NEXTBAND** chamada de escape.  
  
 Se um aplicativo encontra um erro de impressão ou uma operação de impressa cancelada, ele não deve tentar encerrar a operação usando o [EndDoc](#enddoc) ou **AbortDoc** funções de membro da classe `CDC`. GDI interrompe a operação antes de retornar o valor de erro.  
  
 Se o aplicativo exibe uma caixa de diálogo para permitir que o usuário cancelar a operação de impressa, ele deve chamar **AbortDoc** antes de destruir a caixa de diálogo.  
  
 Se o Gerenciador de impressão foi usado para iniciar o trabalho de impressão, chamando **AbortDoc** apaga o trabalho de spool inteiro — a impressora recebe nada. Se o Gerenciador de impressão não foi usado para iniciar o trabalho de impressão, os dados podem foram enviados para a impressora antes de **AbortDoc** foi chamado. Nesse caso, o driver de impressora redefiniria a impressora (quando for possível) e fechado o trabalho de impressão.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CDC::StartDoc](#startdoc).  
  
##  <a name="a-nameabortpatha--cdcabortpath"></a><a name="abortpath"></a>CDC::AbortPath  
 Fecha e descarta todos os caminhos no contexto do dispositivo.  
  
```  
BOOL AbortPath();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se houver um colchete de caminho aberto no contexto do dispositivo, o suporte do caminho é fechado e o caminho será descartado. Se houver um caminho fechado no contexto do dispositivo, o caminho será descartado.  
  
##  <a name="a-nameaddmetafilecommenta--cdcaddmetafilecomment"></a><a name="addmetafilecomment"></a>CDC::AddMetaFileComment  
 Copia o comentário de um buffer em um metarquivo aprimorado de formato especificado.  
  
```  
BOOL AddMetaFileComment(
    UINT nDataSize,  
    const BYTE* pCommentData);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nDataSize*  
 Especifica o comprimento do buffer de comentário, em bytes.  
  
 *pCommentData*  
 Aponta para o buffer que contém o comentário.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um comentário pode incluir qualquer informação particular — por exemplo, a origem da imagem e a data ele foi criado. Um comentário deve começar com uma assinatura do aplicativo, seguida dos dados. Comentários não devem conter dados específicos de posição. Dados específicos de posição especificam o local de um registro, e não deve ser incluído como um metarquivo pode ser inserido em outro metarquivo. Essa função só pode ser usada com metarquivos.  
  
##  <a name="a-namealphablenda--cdcalphablend"></a><a name="alphablend"></a>CDC::AlphaBlend  
 Chame essa função de membro para exibir bitmaps que possuem transparentes ou semitransparentes pixels.  
  
```  
BOOL AlphaBlend(
    int xDest,  
    int yDest,  
    int nDestWidth,  
    int nDestHeight,  
    CDC* pSrcDC,  
    int xSrc,  
    int ySrc,  
    int nSrcWidth,  
    int nSrcHeight,  
    BLENDFUNCTION blend);
```  
  
### <a name="parameters"></a>Parâmetros  
 `xDest`  
 Especifica a coordenada x em unidades lógicas, do canto superior esquerdo do retângulo de destino.  
  
 `yDest`  
 Especifica a coordenada y em unidades lógicas, do canto superior esquerdo do retângulo de destino.  
  
 `nDestWidth`  
 Especifica a largura, em unidades lógicas, do retângulo de destino.  
  
 `nDestHeight`  
 Especifica a altura, em unidades lógicas, do retângulo de destino.  
  
 `pSrcDC`  
 Um ponteiro para o contexto de dispositivo de origem.  
  
 `xSrc`  
 Especifica a coordenada x em unidades lógicas, do canto superior esquerdo do retângulo de origem.  
  
 `ySrc`  
 Especifica a coordenada y em unidades lógicas, do canto superior esquerdo do retângulo de origem.  
  
 `nSrcWidth`  
 Especifica a largura, em unidades lógicas, do retângulo de origem.  
  
 `nSrcHeight`  
 Especifica a altura, em unidades lógicas, do retângulo de origem.  
  
 *Blend*  
 Especifica um [BLENDFUNCTION](http://msdn.microsoft.com/library/windows/desktop/dd183393) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se bem-sucedido; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [AlphaBlend](http://msdn.microsoft.com/library/windows/desktop/dd183351) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações.  
  
##  <a name="a-nameanglearca--cdcanglearc"></a><a name="anglearc"></a>CDC::AngleArc  
 Desenha um segmento de linha e um arco.  
  
```  
BOOL AngleArc(
    int x,  
    int y,  
    int nRadius,  
    float fStartAngle,  
    float fSweepAngle);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica do centro do círculo.  
  
 *y*  
 Especifica a coordenada y lógica do centro do círculo.  
  
 *nRadius*  
 Especifica o raio do círculo em unidades lógicas. Esse valor deve ser positivo.  
  
 *fStartAngle*  
 Especifica o ângulo inicial em graus em relação ao eixo x.  
  
 *fSweepAngle*  
 Especifica o ângulo de flecha em graus em relação ao ângulo inicial.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O segmento de linha é desenhado na posição atual para o início do arco. O arco é desenhado ao longo do perímetro de um círculo com o centro e determinado raio. O comprimento do arco é definido pelos ângulos de início e de varredura de determinado.  
  
 `AngleArc`Move a posição atual para o ponto final do arco. O arco desenhado por essa função pode parecer elíptico, dependendo do modo de mapeamento e transformação atual. Antes de desenhar o arco, essa função desenha o segmento de linha da posição atual para o início do arco. O arco é desenhado construindo um círculo imaginário com raio especificado em torno do ponto central especificado. O ponto de partida do arco é determinado pela medição no sentido anti-horário do eixo x do círculo pelo número de graus no ângulo inicial. O ponto final encontra-se da mesma forma, no sentido anti-horário medindo do ponto de partida pelo número de graus no ângulo de flecha.  
  
 Se o ângulo de flecha é maior que 360 graus o arco é varridas para várias vezes. Essa função desenha linhas usando a caneta atual. A figura não foi preenchida.  
  
##  <a name="a-namearca--cdcarc"></a><a name="arc"></a>CDC::ARC  
 Desenha um arco elíptico.  
  
```  
BOOL Arc(
    int x1,  
    int y1,  
    int x2,  
    int y2,  
    int x3,  
    int y3,  
    int x4,  
    int y4);

 
BOOL Arc(
    LPCRECT lpRect,  
    POINT ptStart,  
    POINT ptEnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `x1`  
 Especifica a coordenada x do canto superior esquerdo do retângulo delimitador (em unidades lógicas).  
  
 `y1`  
 Especifica a coordenada y do canto superior esquerdo do retângulo delimitador (em unidades lógicas).  
  
 `x2`  
 Especifica a coordenada x do canto inferior direito do retângulo delimitador (em unidades lógicas).  
  
 `y2`  
 Especifica a coordenada y do canto inferior direito do retângulo delimitador (em unidades lógicas).  
  
 *X3*  
 Especifica a coordenada x do ponto que define o arco inicial do ponto (em unidades lógicas). Esse ponto não precisa estar exatamente em arco.  
  
 `y3`  
 Especifica a coordenada y do ponto que define o arco inicial do ponto (em unidades lógicas). Esse ponto não precisa estar exatamente em arco.  
  
 `x4`  
 Especifica a coordenada x do ponto que define o ponto de extremidade do arco (em unidades lógicas). Esse ponto não precisa estar exatamente em arco.  
  
 `y4`  
 Especifica a coordenada y do ponto que define o ponto de extremidade do arco (em unidades lógicas). Esse ponto não precisa estar exatamente em arco.  
  
 `lpRect`  
 Especifica o retângulo delimitador (em unidades lógicas). Você pode passar a uma `LPRECT` ou um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto para esse parâmetro.  
  
 `ptStart`  
 Especifica as coordenadas x e y do ponto que define o arco inicial do ponto (em unidades lógicas). Esse ponto não precisa estar exatamente em arco. Você pode passar a uma [ponto](../../mfc/reference/point-structure1.md) estrutura ou um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto para esse parâmetro.  
  
 `ptEnd`  
 Especifica as coordenadas x e y do ponto que define ponto final do arco (em unidades lógicas). Esse ponto não precisa estar exatamente em arco. Você pode passar a uma **ponto** estrutura ou um `CPoint` objeto para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O arco desenhado usando a função é um segmento da elipse definido pelo retângulo delimitador especificado.  
  
 O ponto de partida real do arco é o ponto no qual um raio desenhado no centro do retângulo delimitador através do ponto de partida especificado da interseção da elipse. O ponto final real do arco é o ponto no qual um raio desenhado do centro do retângulo delimitador através do ponto final especificado intercepta a elipse. O arco é desenhado no sentido anti-horário. Como um arco não é uma figura fechada, não foi preenchido. A largura e a altura do retângulo devem ser maiores que 2 unidades e inferior a 32.767.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[29 NVC_MFCDocView](../../mfc/codesnippet/cpp/cdc-class_1.cpp)]  
  
##  <a name="a-namearctoa--cdcarcto"></a><a name="arcto"></a>CDC::ArcTo  
 Desenha um arco elíptico.  
  
```  
BOOL ArcTo(
    int x1,  
    int y1,  
    int x2,  
    int y2,  
    int x3,  
    int y3,  
    int x4,  
    int y4);

 
BOOL ArcTo(
    LPCRECT lpRect,  
    POINT ptStart,  
    POINT ptEnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `x1`  
 Especifica a coordenada x do canto superior esquerdo do retângulo delimitador (em unidades lógicas).  
  
 `y1`  
 Especifica a coordenada y do canto superior esquerdo do retângulo delimitador (em unidades lógicas).  
  
 `x2`  
 Especifica a coordenada x do canto inferior direito do retângulo delimitador (em unidades lógicas).  
  
 `y2`  
 Especifica a coordenada y do canto inferior direito do retângulo delimitador (em unidades lógicas).  
  
 *X3*  
 Especifica a coordenada x do ponto que define o arco inicial do ponto (em unidades lógicas). Esse ponto não precisa estar exatamente em arco.  
  
 `y3`  
 Especifica a coordenada y do ponto que define o arco inicial do ponto (em unidades lógicas). Esse ponto não precisa estar exatamente em arco.  
  
 `x4`  
 Especifica a coordenada x do ponto que define o ponto de extremidade do arco (em unidades lógicas). Esse ponto não precisa estar exatamente em arco.  
  
 `y4`  
 Especifica a coordenada y do ponto que define o ponto de extremidade do arco (em unidades lógicas). Esse ponto não precisa estar exatamente em arco.  
  
 `lpRect`  
 Especifica o retângulo delimitador (em unidades lógicas). Você pode passar um ponteiro para um [RECT](../../mfc/reference/rect-structure1.md) estrutura de dados ou um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto para esse parâmetro.  
  
 `ptStart`  
 Especifica as coordenadas x e y do ponto que define o arco inicial do ponto (em unidades lógicas). Esse ponto não precisa estar exatamente em arco. Você pode passar a uma [ponto](../../mfc/reference/point-structure1.md) estrutura de dados ou um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto para esse parâmetro.  
  
 `ptEnd`  
 Especifica as coordenadas x e y do ponto que define ponto final do arco (em unidades lógicas). Esse ponto não precisa estar exatamente em arco. Você pode passar a uma **ponto** estrutura de dados ou um `CPoint` objeto para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função é semelhante ao `CDC::Arc`, exceto que a posição atual é atualizada. Os pontos ( `x1`, `y1`) e ( `x2`, `y2`) Especifique o retângulo delimitador. Uma elipse formada por determinado retângulo delimitador define a curva do arco. O arco no sentido anti-horário estende (a direção do arco padrão) do ponto onde ele faz interseção com a linha radial do centro do retângulo delimitador ( *x3*, `y3`). As extremidades de arco onde ele faz interseção com a linha radial do centro do retângulo delimitador ( `x4`, `y4`). Se o ponto inicial e final são os mesmos, uma elipse completa é desenhada.  
  
 Uma linha é desenhada da posição atual para o ponto de partida do arco. Se nenhum erro ocorrer, a posição atual é definida para o ponto final do arco. O arco é desenhado usando a caneta atual; não foi preenchido.  
  
##  <a name="a-nameattacha--cdcattach"></a><a name="attach"></a>CDC::Attach  
 Use esta função de membro para anexar um `hDC` para o `CDC` objeto.  
  
```  
BOOL Attach(HDC hDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hDC`  
 Um contexto de dispositivo do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `hDC` estão armazenadas nos `m_hDC`, o contexto de dispositivo de saída e no `m_hAttribDC`, o contexto de dispositivo do atributo.  
  
##  <a name="a-namebeginpatha--cdcbeginpath"></a><a name="beginpath"></a>CDC:: beginpath  
 Abre um colchete de caminho no contexto do dispositivo.  
  
```  
BOOL BeginPath();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Depois de abrir um colchete de caminho, um aplicativo pode começar a chamar funções de desenho do GDI para definir os pontos que estão no caminho. Um aplicativo pode fechar um colchete de caminho aberto chamando o `EndPath` função de membro. Quando um aplicativo chama `BeginPath`, todos os caminhos anteriores são descartados.  
  
 Consulte [BeginPath](http://msdn.microsoft.com/library/windows/desktop/dd183363) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma lista das funções de desenho que definem pontos em um caminho.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[30 NVC_MFCDocView](../../mfc/codesnippet/cpp/cdc-class_2.cpp)]  
  
##  <a name="a-namebitblta--cdcbitblt"></a><a name="bitblt"></a>CDC::BitBlt  
 Copia um bitmap do contexto do dispositivo de origem para este contexto de dispositivo atual.  
  
```  
BOOL BitBlt(
    int x,  
    int y,  
    int nWidth,  
    int nHeight,  
    CDC* pSrcDC,  
    int xSrc,  
    int ySrc,  
    DWORD dwRop);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica do canto superior esquerdo do retângulo de destino.  
  
 *y*  
 Especifica a coordenada y lógica do canto superior esquerdo do retângulo de destino.  
  
 `nWidth`  
 Especifica a largura (em unidades lógicas) do bitmap retângulo e fonte de destino.  
  
 `nHeight`  
 Especifica a altura (em unidades lógicas) do bitmap retângulo e fonte de destino.  
  
 `pSrcDC`  
 Ponteiro para uma `CDC` objeto que identifica o contexto de dispositivo do que o bitmap será copiado. Ele deve ser **nulo** se *dwRop* Especifica uma operação de varredura que não inclui uma fonte.  
  
 `xSrc`  
 Especifica a coordenada x lógica do canto superior esquerdo do bitmap de origem.  
  
 `ySrc`  
 Especifica a coordenada y lógica do canto superior esquerdo do bitmap de origem.  
  
 *dwRop*  
 Especifica a operação de varredura a ser executada. Códigos de operação de varredura definem como a GDI combina cores nas operações de saída que envolvem um pincel, um bitmap de origem possíveis e um bitmap de destino. Consulte [BitBlt](http://msdn.microsoft.com/library/windows/desktop/dd183370) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma lista dos códigos de operação de varredura para *dwRop* e suas descrições  
  
 Para obter uma lista completa dos códigos de operação de varredura, consulte [sobre códigos de operação de varredura](http://msdn.microsoft.com/library/windows/desktop/dd162892) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O aplicativo pode alinhar o windows ou áreas de cliente nos limites de byte para garantir que o `BitBlt` as operações ocorrem em retângulos bytes alinhado. (Definir a **CS_BYTEALIGNWINDOW** ou **CS_BYTEALIGNCLIENT** sinaliza ao registrar as classes de janela.)  
  
 `BitBlt`operações em bytes alinhado retângulos são consideravelmente mais rápidas que `BitBlt` operações em retângulos que não estão alinhada. Se você quiser especificar os estilos de classe, como alinhamento de bytes para seu próprio contexto de dispositivo, você precisa registrar uma classe de janela em vez de contar com as Microsoft Foundation classes para fazer isso para você. Use a função global [AfxRegisterWndClass](../../mfc/reference/application-information-and-management.md#afxregisterwndclass).  
  
 Transforma GDI `nWidth` e `nHeight`, uma vez usando o contexto de dispositivo de destino e uma vez usando o contexto de dispositivo de origem. Se as extensões resultantes não coincidirem, GDI usa o Windows `StretchBlt` função para compactar ou alongar o bitmap de origem conforme necessário.  
  
 Se o destino, origem e bitmaps padrão não têm o mesmo formato de cor, o `BitBlt` função converte os bitmaps de origem e padrão para coincidir com o destino. As cores de primeiro e segundo plano do bitmap de destino são usadas na conversão.  
  
 Quando o `BitBlt` função converte um bitmap monocromático em cor, ele definirá bits brancos (1) para a cor de plano de fundo e bits pretos (0) para a cor de primeiro plano. As cores de primeiro plano e plano de fundo do contexto do dispositivo de destino são usadas. Para converter a cor em monocromático, `BitBlt` define pixels que correspondam a cor de plano de fundo para branco e todos os outros pixels para preto. `BitBlt`usa as cores de primeiro plano e plano de fundo do contexto do dispositivo de cor para converter de cor em monocromático.  
  
 Observe que nem todos os contextos de dispositivo suporte para `BitBlt`. Para verificar se um determinado contexto de dispositivo suportam `BitBlt`, use o `GetDeviceCaps` membro de função e especificar o **RASTERCAPS** índice.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CDC::CreateCompatibleDC](#createcompatibledc).  
  
##  <a name="a-namecdca--cdccdc"></a><a name="cdc"></a>CDC::CDC  
 Constrói um objeto `CDC`.  
  
```  
CDC();
```  
  
##  <a name="a-namechorda--cdcchord"></a><a name="chord"></a>CDC::chord  
 Desenha um acorde (uma figura fechada limitada pela interseção de uma elipse e um segmento de linha).  
  
```  
BOOL Chord(
    int x1,  
    int y1,  
    int x2,  
    int y2,  
    int x3,  
    int y3,  
    int x4,  
    int y4);

 
BOOL Chord(
    LPCRECT lpRect,  
    POINT ptStart,  
    POINT ptEnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `x1`  
 Especifica que a coordenada x do canto superior esquerdo da corda delimitadora do retângulo (em unidades lógicas).  
  
 `y1`  
 Especifica que a coordenada y do canto superior esquerdo da corda delimitadora do retângulo (em unidades lógicas).  
  
 `x2`  
 Especifica que a coordenada x do canto inferior direito da corda delimitadora do retângulo (em unidades lógicas).  
  
 `y2`  
 Especifica que a coordenada y do canto inferior direito da corda delimitadora do retângulo (em unidades lógicas).  
  
 *X3*  
 Especifica a coordenada x do ponto que define a corda inicial do ponto (em unidades lógicas).  
  
 `y3`  
 Especifica a coordenada y do ponto que define a corda inicial do ponto (em unidades lógicas).  
  
 `x4`  
 Especifica a coordenada x do ponto que define o ponto de extremidade da corda (em unidades lógicas).  
  
 `y4`  
 Especifica a coordenada y do ponto que define o ponto de extremidade da corda (em unidades lógicas).  
  
 `lpRect`  
 Especifica o retângulo delimitador (em unidades lógicas). Você pode passar a uma `LPRECT` ou um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto para esse parâmetro.  
  
 `ptStart`  
 Especifica as coordenadas x e y do ponto que define a corda inicial do ponto (em unidades lógicas). Esse ponto não precisa estar exatamente na corda. Você pode passar a uma **ponto** estrutura ou um `CPoint` objeto para esse parâmetro.  
  
 `ptEnd`  
 Especifica as coordenadas x e y do ponto que define ponto final a corda (em unidades lógicas). Esse ponto não precisa estar exatamente na corda. Você pode passar a uma [ponto](../../mfc/reference/point-structure1.md) estrutura ou um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A ( `x1`, `y1`) e ( `x2`, `y2`) parâmetros especificam os cantos superior esquerda e inferior direita, respectivamente, de um retângulo delimitador elipse que faz parte da corda. A ( *x3*, `y3`) e ( `x4`, `y4`) parâmetros especificam os pontos de extremidade de uma linha que intercepta a elipse. Corda é desenhada usando a caneta selecionada e preenchida usando o pincel selecionado.  
  
 A Figura desenhada pelo `Chord` função se estende até, mas não inclui as coordenadas da direita e inferior. Isso significa que a altura da figura `y2` – `y1` e a largura da figura é `x2` – `x1`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#31;](../../mfc/codesnippet/cpp/cdc-class_3.cpp)]  
  
##  <a name="a-nameclosefigurea--cdcclosefigure"></a><a name="closefigure"></a>CDC::CloseFigure  
 Fecha uma figura aberta em um caminho.  
  
```  
BOOL CloseFigure();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A função fecha a figura para desenhar uma linha a partir da posição atual até o primeiro ponto da figura (em geral, o ponto especificado pela chamada mais recente para o `MoveTo` função de membro) e conecta-se as linhas usando o estilo de junção de linha. Se uma figura for fechada, usando o `LineTo` a função de membro em vez de `CloseFigure`, tampas são usadas para criar o canto, em vez de uma junção. `CloseFigure`deve ser chamado somente se houver um colchete de caminho aberto no contexto do dispositivo.  
  
 Uma figura em um caminho está aberta, a menos que ela é fechada explicitamente usando essa função. (Uma figura pode ser aberta mesmo se o ponto atual e o ponto de partida da figura são os mesmos.) Qualquer linha ou curva adicionado ao caminho após `CloseFigure` inicia uma nova figura.  
  
##  <a name="a-namecreatecompatibledca--cdccreatecompatibledc"></a><a name="createcompatibledc"></a>CDC::CreateCompatibleDC  
 Cria um contexto de dispositivo de memória que é compatível com o dispositivo especificado pelo `pDC`.  
  
```  
BOOL CreateCompatibleDC(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Um ponteiro para um contexto de dispositivo. Se `pDC` é **nulo**, a função cria um contexto de dispositivo de memória que é compatível com a exibição do sistema.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um contexto de dispositivo de memória é um bloco de memória que representa uma superfície de exibição. Ele pode ser usado para preparar imagens na memória antes de copiá-los para a superfície do dispositivo real do dispositivo compatível.  
  
 Quando um contexto de dispositivo de memória é criado, GDI seleciona automaticamente um bitmap de estoque monocromático de 1 a 1 para ele. Funções de GDI de saída podem ser usadas com um contexto de dispositivo de memória somente se um bitmap foi criado e selecionado no contexto.  
  
 Essa função só pode ser usada para criar contextos de dispositivo compatível para dispositivos que oferecem suporte a operações de varredura. Consulte o [CDC::BitBlt](#bitblt) a função de membro para obter informações sobre transferências de bloco de bits entre contextos de dispositivo. Para determinar se um contexto de dispositivo oferece suporte a operações de varredura, consulte o **RC_BITBLT** capacidade de varredura na função de membro `CDC::GetDeviceCaps`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[32 NVC_MFCDocView](../../mfc/codesnippet/cpp/cdc-class_4.cpp)]  
  
##  <a name="a-namecreatedca--cdccreatedc"></a><a name="createdc"></a>CDC::CreateDC  
 Cria um contexto de dispositivo para o dispositivo especificado.  
  
```  
BOOL CreateDC(
    LPCTSTR lpszDriverName,  
    LPCTSTR lpszDeviceName,  
    LPCTSTR lpszOutput,  
    const void* lpInitData);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszDriverName`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica o nome do arquivo (sem extensão) do driver de dispositivo (por exemplo, "EPSON"). Você também pode passar um `CString` objeto para esse parâmetro.  
  
 `lpszDeviceName`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica o nome do dispositivo específico com suporte (por exemplo, "EPSON FX-80"). O `lpszDeviceName` parâmetro é usado se o módulo oferece suporte a mais de um dispositivo. Você também pode passar um `CString` objeto para esse parâmetro.  
  
 `lpszOutput`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica o nome de arquivo ou dispositivo para o meio de saída física (porta de saída ou de arquivo). Você também pode passar um `CString` objeto para esse parâmetro.  
  
 `lpInitData`  
 Aponta para um `DEVMODE` estrutura que contém dados específicos do dispositivo de inicialização do driver de dispositivo. O Windows **DocumentProperties** função recupera essa estrutura preenchida por um determinado dispositivo. O `lpInitData` parâmetro deve ser **nulo** se o driver de dispositivo é usar a inicialização padrão (se houver) especificada pelo usuário no painel de controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A impressão. Arquivo de cabeçalho H é necessário se o [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) estrutura é usada.  
  
 Os nomes dos dispositivos seguem essas convenções: final um dois-pontos (:) são opcional mas recomendado. Windows retira o encerramento vírgula para que um nome de dispositivo terminando com dois-pontos é mapeado para a mesma porta que o mesmo nome sem dois-pontos. Os nomes de driver e a porta não devem conter espaços à esquerda ou à direita. Funções de GDI de saída não podem ser usadas com contextos de informações.  
  
##  <a name="a-namecreateica--cdccreateic"></a><a name="createic"></a>CDC::CreateIC  
 Cria um contexto de informações para o dispositivo especificado.  
  
```  
BOOL CreateIC(
    LPCTSTR lpszDriverName,  
    LPCTSTR lpszDeviceName,  
    LPCTSTR lpszOutput,  
    const void* lpInitData);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszDriverName`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica o nome do arquivo (sem extensão) do driver de dispositivo (por exemplo, "EPSON"). Você pode passar uma `CString` objeto para esse parâmetro.  
  
 `lpszDeviceName`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica o nome do dispositivo específico com suporte (por exemplo, "EPSON FX-80"). O `lpszDeviceName` parâmetro é usado se o módulo oferece suporte a mais de um dispositivo. Você pode passar uma `CString` objeto para esse parâmetro.  
  
 `lpszOutput`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica o nome de arquivo ou dispositivo para a mídia de saída físico (arquivo ou porta). Você pode passar uma `CString` objeto para esse parâmetro.  
  
 `lpInitData`  
 Pontos de dados específicos do dispositivo de inicialização para o driver de dispositivo. O `lpInitData` parâmetro deve ser **nulo** se o driver de dispositivo é usar a inicialização padrão (se houver) especificada pelo usuário no painel de controle. Consulte `CreateDC` para o formato de dados específicos do dispositivo de inicialização.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 As informações de contexto fornece uma maneira rápida de obter informações sobre o dispositivo sem criar um contexto de dispositivo.  
  
 Os nomes dos dispositivos seguem essas convenções: final um dois-pontos (:) são opcional mas recomendado. Windows retira o encerramento vírgula para que um nome de dispositivo terminando com dois-pontos é mapeado para a mesma porta que o mesmo nome sem dois-pontos. Os nomes de driver e a porta não devem conter espaços à esquerda ou à direita. Funções de GDI de saída não podem ser usadas com contextos de informações.  
  
##  <a name="a-namedeletedca--cdcdeletedc"></a><a name="deletedc"></a>CDC::DeleteDC  
 Em geral, não chame essa função; o destruidor fará isso para você.  
  
```  
BOOL DeleteDC();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função foi concluída com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `DeleteDC` função de membro exclui os contextos de dispositivo do Windows que estão associados `m_hDC` na atual `CDC` objeto. Se este `CDC` objeto é o último contexto de dispositivo ativo para um determinado dispositivo, o dispositivo é notificado e todos os recursos de armazenamento e sistema usados pelo dispositivo são liberados.  
  
 Um aplicativo não deve chamar `DeleteDC` se os objetos selecionados no contexto de dispositivo. Objetos devem ser selecionados primeiro fora do contexto de dispositivo antes de ser excluído.  
  
 Um aplicativo não deve excluir um contexto de dispositivo cujo identificador foi obtido chamando [CWnd::GetDC](../../mfc/reference/cwnd-class.md#getdc). Em vez disso, ele deve chamar [CWnd::ReleaseDC](../../mfc/reference/cwnd-class.md#releasedc) para liberar o contexto do dispositivo. O [CClientDC](../../mfc/reference/cclientdc-class.md) e [CWindowDC](../../mfc/reference/cwindowdc-class.md) classes são fornecidas para encapsular essa funcionalidade.  
  
 O `DeleteDC` função geralmente é usada para excluir os contextos de dispositivo criados com [CreateDC](#createdc), [CreateIC](#createic), ou [CreateCompatibleDC](#createcompatibledc).  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPrintDialog::GetPrinterDC](../../mfc/reference/cprintdialog-class.md#getprinterdc).  
  
##  <a name="a-namedeletetempmapa--cdcdeletetempmap"></a><a name="deletetempmap"></a>CDC::DeleteTempMap  
 Chamado automaticamente pelo `CWinApp` manipulador de tempo ocioso, `DeleteTempMap` exclui qualquer temporário `CDC` objetos criados por `FromHandle`, mas não destrói os identificadores de contexto de dispositivo ( `hDC`s) associada temporariamente o `CDC` objetos.  
  
```  
static void PASCAL DeleteTempMap();
```  
  
##  <a name="a-namedetacha--cdcdetach"></a><a name="detach"></a>CDC::Detach  
 Chame essa função desanexar `m_hDC` (o contexto de dispositivo de saída) do `CDC` de objeto e defina as `m_hDC` e `m_hAttribDC` para **nulo**.  
  
```  
HDC Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um contexto de dispositivo do Windows.  
  
##  <a name="a-namedptohimetrica--cdcdptohimetric"></a><a name="dptohimetric"></a>CDC::DPtoHIMETRIC  
 Usar essa função quando você der **HIMETRIC** tamanhos para OLE, convertendo pixels para **HIMETRIC**.  
  
```  
void DPtoHIMETRIC(LPSIZE lpSize) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpSize`  
 Aponta para um [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Se o modo de mapeamento de objeto de contexto de dispositivo for `MM_LOENGLISH`, `MM_HIENGLISH`, `MM_LOMETRIC`, ou `MM_HIMETRIC`, em seguida, a conversão é baseada no número de pixels física polegada. Se o modo de mapeamento é um dos outros modos não limitado (por exemplo, `MM_TEXT`), em seguida, a conversão é baseada no número de pixels de polegada lógica.  
  
##  <a name="a-namedptolpa--cdcdptolp"></a><a name="dptolp"></a>CDC::DPtoLP  
 Converte unidades de dispositivo em unidades lógicas.  
  
```  
void DPtoLP(
    LPPOINT lpPoints,  
    int nCount = 1) const;  
  
void DPtoLP(LPRECT lpRect) const;
void DPtoLP(LPSIZE lpSize) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPoints`  
 Aponta para uma matriz de [ponto](../../mfc/reference/point-structure1.md) estruturas ou [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objetos.  
  
 `nCount`  
 O número de pontos da matriz.  
  
 `lpRect`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto. Esse parâmetro é usado para o caso simple de conversão de um retângulo de pontos de dispositivo a pontos de lógicos.  
  
 `lpSize`  
 Aponta para um [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 A função mapeia as coordenadas de cada ponto ou a dimensão de tamanho, do sistema de coordenadas de dispositivo no sistema de coordenadas lógico da GDI. A conversão depende do modo de mapeamento atual e as configurações das origens e extensões para a janela do dispositivo e o visor.  
  
##  <a name="a-namedraw3drecta--cdcdraw3drect"></a><a name="draw3drect"></a>CDC::Draw3dRect  
 Chame essa função de membro para desenhar um retângulo tridimensional.  
  
```  
void Draw3dRect(
    LPCRECT lpRect,  
    COLORREF clrTopLeft,  
    COLORREF clrBottomRight);

 
void Draw3dRect(
    int x,  
    int y,  
    int cx,  
    int cy,  
    COLORREF clrTopLeft,  
    COLORREF clrBottomRight);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Especifica o retângulo delimitador (em unidades lógicas). Você pode passar um ponteiro para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto para esse parâmetro.  
  
 *clrTopLeft*  
 Especifica a cor dos lados superior e esquerdas do retângulo tridimensional.  
  
 `clrBottomRight`  
 Especifica a cor da parte inferior e direita do retângulo tridimensional.  
  
 *x*  
 Especifica a coordenada x lógica do canto superior esquerdo do retângulo tridimensional.  
  
 *y*  
 Especifica a coordenada y lógica do canto superior esquerdo do retângulo tridimensional.  
  
 CX  
 Especifica a largura do retângulo tridimensional.  
  
 Cy  
 Especifica a altura do retângulo tridimensional.  
  
### <a name="remarks"></a>Comentários  
 O retângulo será desenhado com lados superior e esquerdos na cor especificada por *clrTopLeft* e a parte inferior e à direita na cor especificada pelo `clrBottomRight`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[33 NVC_MFCDocView](../../mfc/codesnippet/cpp/cdc-class_5.cpp)]  
  
##  <a name="a-namedrawdragrecta--cdcdrawdragrect"></a><a name="drawdragrect"></a>CDC::DrawDragRect  
 Chame essa função de membro repetidamente para redesenhar um retângulo de arrastar.  
  
```  
void DrawDragRect(
    LPCRECT lpRect,  
    SIZE size,  
    LPCRECT lpRectLast,  
    SIZE sizeLast,  
    CBrush* pBrush = NULL,  
    CBrush* pBrushLast = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que especifica as coordenadas lógicas de um retângulo — neste caso, a posição final do retângulo sendo redesenhada.  
  
 `size`  
 Especifica o deslocamento do canto superior esquerdo da borda externa para o canto superior esquerdo da borda interna (ou seja, a espessura da borda) de um retângulo.  
  
 `lpRectLast`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que especifica as coordenadas lógicas da posição de um retângulo — neste caso, a posição do retângulo sendo redesenhada original.  
  
 *sizeLast*  
 Especifica o deslocamento do canto superior esquerdo da borda externa ao canto superior esquerdo da borda interna (ou seja, a espessura da borda) do retângulo original sendo redesenhada.  
  
 `pBrush`  
 Ponteiro para um objeto brush. Definido como **nulo** para usar o pincel de meio-tom padrão.  
  
 *pBrushLast*  
 Ponteiro para o último objeto pincel usado. Definido como **nulo** para usar o pincel de meio-tom padrão.  
  
### <a name="remarks"></a>Comentários  
 Chamá-lo em um loop, conforme o exemplo posição do mouse, para dar feedback visual. Quando você chama `DrawDragRect`, o retângulo anterior é apagado e uma nova é desenhada. Por exemplo, como o usuário arrasta um retângulo pela tela, `DrawDragRect` irá apagar o retângulo original e redesenhar um novo em sua nova posição. Por padrão, `DrawDragRect` desenha o retângulo usando um pincel de meio-tom para eliminar as intermitências e para criar a aparência de um retângulo mover sem problemas.  
  
 Na primeira vez que você chamar `DrawDragRect`, o `lpRectLast` parâmetro deve ser **nulo**.  
  
##  <a name="a-namedrawedgea--cdcdrawedge"></a><a name="drawedge"></a>CDC::DrawEdge  
 Chame essa função de membro para desenhar as bordas de um retângulo do tipo especificado e estilo.  
  
```  
BOOL DrawEdge(
    LPRECT lpRect,  
    UINT nEdge,  
    UINT nFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Um ponteiro para um **RECT** estrutura que contém as coordenadas lógicas do retângulo.  
  
 *nEdge*  
 Especifica o tipo de borda interno e externo para desenhar. Esse parâmetro deve ser uma combinação de um sinalizador de borda interna e um sinalizador de borda externa. Consulte [DrawEdge](http://msdn.microsoft.com/library/windows/desktop/dd162477) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para uma tabela de tipos do parâmetro.  
  
 `nFlags`  
 Os sinalizadores que especificam o tipo de borda a ser desenhada. Consulte `DrawEdge` no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para uma tabela de valores do parâmetro. Para linhas diagonais, o **BF_RECT** flags especificam o ponto de extremidade do vetor limitado pelo parâmetro retângulo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
##  <a name="a-namedrawescapea--cdcdrawescape"></a><a name="drawescape"></a>CDC::DrawEscape  
 Acessa os recursos de um monitor de vídeo que não estão diretamente disponíveis por meio da interface gráfica de dispositivo (GDI) de desenho.  
  
```  
int DrawEscape(
    int nEscape,  
    int nInputSize,  
    LPCSTR lpszInputData);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nEscape`  
 Especifica a função de escape para ser executada.  
  
 `nInputSize`  
 Especifica o número de bytes de dados que aponta para o `lpszInputData` parâmetro.  
  
 `lpszInputData`  
 Aponta para a estrutura de entrada necessários para o escape especificado.  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o resultado da função. Maior que zero se tiver êxito, exceto para o **QUERYESCSUPPORT** desenhar escape, que verifica se há implementação; ou zero se o escape não está implementado; ou menor que zero se um erro ocorreu.  
  
### <a name="remarks"></a>Comentários  
 Quando um aplicativo chama `DrawEscape`, os dados identificados por `nInputSize` e `lpszInputData` é passado diretamente para o driver de vídeo especificado.  
  
##  <a name="a-namedrawfocusrecta--cdcdrawfocusrect"></a><a name="drawfocusrect"></a>CDC::DrawFocusRect  
 Desenha um retângulo no estilo usado para indicar que o retângulo tem o foco.  
  
```  
void DrawFocusRect(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que especifica as coordenadas lógicas do retângulo a ser desenhada.  
  
### <a name="remarks"></a>Comentários  
 Como essa é uma função XOR booliano, chamar essa função uma segunda vez com o mesmo retângulo remove o retângulo da exibição. O retângulo desenhado por essa função não pode ser rolado. Para rolar uma área que contém um retângulo desenhado por essa função, primeiro chame `DrawFocusRect` para remover o retângulo da exibição, role a área e, em seguida, chame `DrawFocusRect` novamente para desenhar o retângulo na nova posição.  
  
> [!CAUTION]
> `DrawFocusRect`funciona somente em `MM_TEXT` modo. Em outros modos, essa função não desenhar o retângulo de foco corretamente, mas não retorna valores de erro.  
  
##  <a name="a-namedrawframecontrola--cdcdrawframecontrol"></a><a name="drawframecontrol"></a>CDC::DrawFrameControl  
 Chame essa função de membro para desenhar um controle de quadro do tipo especificado e estilo.  
  
```  
BOOL DrawFrameControl(
    LPRECT lpRect,  
    UINT nType,  
    UINT nState);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Um ponteiro para um **RECT** estrutura que contém as coordenadas lógicas do retângulo.  
  
 `nType`  
 Especifica o tipo de controle de quadro para desenhar. Consulte o *uType* parâmetro em [DrawFrameControl](http://msdn.microsoft.com/library/windows/desktop/dd162480) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma lista de valores possíveis deste parâmetro.  
  
 `nState`  
 Especifica o estado inicial do controle quadro. Pode ser um ou mais dos valores descritos para a *uState* parâmetro em `DrawFrameControl` no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Use o `nState` valor **DFCS_ADJUSTRECT** para ajustar o retângulo delimitador para excluir a borda ao redor do botão de envio.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Em muitos casos, `nState` depende do `nType` parâmetro. A lista a seguir mostra a relação entre os quatro `nType` valores e `nState`:  
  
- **DFC_BUTTON**  
  
    - **DFCS_BUTTON3STATE** botão de três estados  
  
    - **DFCS_BUTTONCHECK** caixa de seleção  
  
    - **DFCS_BUTTONPUSH** botão de ação  
  
    - **DFCS_BUTTONRADIO** botão de opção  
  
    - **DFCS_BUTTONRADIOIMAGE** imagem para o botão de opção (não quadrados precisa de imagem)  
  
    - **DFCS_BUTTONRADIOMASK** máscara para botão de opção (não quadrados precisa de máscara)  
  
- **DFC_CAPTION**  
  
    - **DFCS_CAPTIONCLOSE** botão Fechar  
  
    - **DFCS_CAPTIONHELP** botão Ajuda  
  
    - **DFCS_CAPTIONMAX** botão maximizar  
  
    - **DFCS_CAPTIONMIN** botão minimizar  
  
    - **DFCS_CAPTIONRESTORE** botão Restaurar  
  
- **DFC_MENU**  
  
    - **DFCS_MENUARROW** seta do Submenu  
  
    - **DFCS_MENUBULLET** marcador  
  
    - **DFCS_MENUCHECK** marca de seleção  
  
- **DFC_SCROLL**  
  
    - **DFCS_SCROLLCOMBOBOX** barra de rolagem de caixa de combinação  
  
    - **DFCS_SCROLLDOWN** para baixo da barra de rolagem  
  
    - **DFCS_SCROLLLEFT** seta para a esquerda da barra de rolagem  
  
    - **DFCS_SCROLLRIGHT** seta à direita da barra de rolagem  
  
    - **DFCS_SCROLLSIZEGRIP** alça de tamanho no canto inferior direito da janela  
  
    - **DFCS_SCROLLUP** a seta de barra de rolagem  
  
### <a name="example"></a>Exemplo  
 Esse código desenha garra tamanho no canto inferior direito da janela. Ele é apropriado para o `OnPaint` manipulador da caixa de diálogo, que não tem nenhum estilo e normalmente não contém outros controles (como uma barra de status) que podem dar a ele uma alça de tamanho.  
  
 [!code-cpp[NVC_MFCDocView&#34;](../../mfc/codesnippet/cpp/cdc-class_6.cpp)]  
  
##  <a name="a-namedrawicona--cdcdrawicon"></a><a name="drawicon"></a>CDC::DrawIcon  
 Desenha um ícone no dispositivo representado pelo atual `CDC` objeto.  
  
```  
BOOL DrawIcon(
    int x,  
    int y,  
    HICON hIcon);

 
BOOL DrawIcon(
    POINT point,  
    HICON hIcon);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica do canto superior esquerdo do ícone.  
  
 *y*  
 Especifica a coordenada y lógica do canto superior esquerdo do ícone.  
  
 `hIcon`  
 Identifica o identificador do ícone a ser desenhada.  
  
 `point`  
 Especifica a lógica coordenadas x e y-do canto superior esquerdo do ícone. Você pode passar um [ponto](../../mfc/reference/point-structure1.md) estrutura ou um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função foi concluída com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A função coloca o canto do superior esquerdo do ícone no local especificado por *x* e *y*. O local está sujeita ao modo atual do mapeamento do contexto do dispositivo.  
  
 O recurso de ícone deve ter sido carregado usando as funções `CWinApp::LoadIcon`, `CWinApp::LoadStandardIcon`, ou `CWinApp::LoadOEMIcon`. O `MM_TEXT` modo de mapeamento deve ser selecionado antes de usar essa função.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CWnd::IsIconic](../../mfc/reference/cwnd-class.md#isiconic).  
  
##  <a name="a-namedrawstatea--cdcdrawstate"></a><a name="drawstate"></a>CDC::DrawState  
 Chame essa função de membro para exibir uma imagem e aplicar um efeito visual para indicar um estado, como a desabilitado ou o estado padrão.  
  
> [!NOTE]
>  Para todos os `nFlag` estados exceto **DSS_NORMAL**, a imagem é convertida em monocromático antes do efeito visual é aplicado.  
  
```  
BOOL DrawState(
    CPoint pt,  
    CSize size,  
    HBITMAP hBitmap,  
    UINT nFlags,  
    HBRUSH hBrush = NULL);

 
BOOL DrawState(
    CPoint pt,  
    CSize size,  
    CBitmap* pBitmap,  
    UINT nFlags,  
    CBrush* pBrush = NULL);

 
BOOL DrawState(
    CPoint pt,  
    CSize size,  
    HICON hIcon,  
    UINT nFlags,  
    HBRUSH hBrush = NULL);

 
BOOL DrawState(
    CPoint pt,  
    CSize size,  
    HICON hIcon,  
    UINT nFlags,  
    CBrush* pBrush = NULL);

 
BOOL DrawState(
    CPoint pt,  
    CSize size,  
    LPCTSTR lpszText,  
    UINT nFlags,  
    BOOL bPrefixText = TRUE,  
    int nTextLen = 0,  
    HBRUSH hBrush = NULL);

 
BOOL DrawState(
    CPoint pt,  
    CSize size,  
    LPCTSTR lpszText,  
    UINT nFlags,  
    BOOL bPrefixText = TRUE,  
    int nTextLen = 0,  
    CBrush* pBrush = NULL);

 
BOOL DrawState(
    CPoint pt,  
    CSize size,  
    DRAWSTATEPROC lpDrawProc,  
    LPARAM lData,  
    UINT nFlags,  
    HBRUSH hBrush = NULL);

 
BOOL DrawState(
    CPoint pt,  
    CSize size,  
    DRAWSTATEPROC lpDrawProc,  
    LPARAM lData,  
    UINT nFlags,  
    CBrush* pBrush = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pt`  
 Especifica o local da imagem.  
  
 `size`  
 Especifica o tamanho da imagem.  
  
 `hBitmap`  
 Um identificador para um bitmap.  
  
 `nFlags`  
 Sinalizadores que especificam o tipo de imagem e o estado. Consulte [DrawState](http://msdn.microsoft.com/library/windows/desktop/dd162496) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para possíveis `nFlags` tipos e estados.  
  
 `hBrush`  
 Um identificador para um pincel.  
  
 `pBitmap`  
 Um ponteiro para um objeto CBitmap.  
  
 `pBrush`  
 Um ponteiro para um objeto CBrush.  
  
 `hIcon`  
 Um identificador para um ícone.  
  
 `lpszText`  
 Um ponteiro de texto.  
  
 *bPrefixText*  
 Texto que pode conter um mnemônico accelerator. O `lData` parâmetro especifica o endereço da cadeia de caracteres e o `nTextLen` parâmetro especifica o comprimento. Se `nTextLen` for 0, a cadeia de caracteres deve para ser terminada em nulo.  
  
 `nTextLen`  
 Comprimento da cadeia de texto apontada por `lpszText`. Se `nTextLen` for 0, a cadeia de caracteres deve para ser terminada em nulo.  
  
 *lpDrawProc*  
 Um ponteiro para uma função de retorno de chamada usado para processar uma imagem. Este parâmetro é obrigatório se o tipo de imagem em `nFlags` é **DST_COMPLEX**. Ele é opcional e pode ser **nulo** se o tipo de imagem é **DST_TEXT**. Para todos os outros tipos de imagem, este parâmetro é ignorado. Para obter mais informações sobre a função de retorno de chamada, consulte o [DrawStateProc](http://msdn.microsoft.com/library/windows/desktop/dd162497) funcionar a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `lData`  
 Especifica informações sobre a imagem. O significado desse parâmetro depende do tipo de imagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
##  <a name="a-namedrawtexta--cdcdrawtext"></a><a name="drawtext"></a>CDC::DrawText  
 Chame essa função de membro para formatar o texto no retângulo determinado. Para especificar opções de formatação adicionais, use [CDC::DrawTextEx](#drawtextex).  
  
```  
virtual int DrawText(
    LPCTSTR lpszString,  
    int nCount,  
    LPRECT lpRect,  
    UINT nFormat);

 
int DrawText(
    const CString& str,  
    LPRECT lpRect,  
    UINT nFormat);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszString`  
 Aponta para a cadeia de caracteres a ser desenhada. Se `nCount` é –&1;, a cadeia de caracteres deve ser terminada em nulo.  
  
 `nCount`  
 Especifica o número de caracteres na cadeia de caracteres. Se `nCount` é –&1;, em seguida, `lpszString` é considerado como um ponteiro long para uma cadeia de caracteres terminada em nulo e `DrawText` calcula o número de caracteres automaticamente.  
  
 `lpRect`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que contém o retângulo (em coordenadas lógicas) no qual o texto é a ser formatado.  
  
 `str`  
 A [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém os caracteres especificados a ser desenhada.  
  
 `nFormat`  
 Especifica o método de formatação de texto. Ele pode ser qualquer combinação dos valores descritos para a `uFormat` parâmetro em [DrawText](http://msdn.microsoft.com/library/windows/desktop/dd162498) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. (combine, usando o operador OR bit a bit):  
  
> [!NOTE]
>  Alguns `uFormat` combinações de sinalizador podem fazer com que a cadeia de caracteres transmitida a ser modificado. Usando **DT_MODIFYSTRING** com um **DT_END_ELLIPSIS** ou **DT_PATH_ELLIPSIS** pode fazer com que a cadeia de caracteres a ser modificada, causando uma asserção no `CString` substituir. Os valores `DT_CALCRECT`, `DT_EXTERNALLEADING`, **DT_INTERNAL**, `DT_NOCLIP`, e `DT_NOPREFIX` não pode ser usado com o `DT_TABSTOP` valor.  
  
### <a name="return-value"></a>Valor de retorno  
 A altura do texto se a função for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 Formata texto, expandindo tabulações em espaços apropriados, alinhar texto à esquerda, direita ou centro do retângulo de determinado e dividindo o texto em linhas que cabem dentro do retângulo de determinado. O tipo de formatação é especificado pelo `nFormat`.  
  
 Essa função de membro usa o contexto de dispositivo fonte selecionada, cor do texto e cor de plano de fundo para desenhar o texto. A menos que o `DT_NOCLIP` formato é usado, `DrawText` recorta o texto para que o texto não é exibido fora do retângulo determinado. Toda a formatação é considerado para ter várias linhas, a menos que o `DT_SINGLELINE` formato é fornecido.  
  
 Se a fonte selecionada é muito grande para o retângulo especificado, o `DrawText` função de membro não tenta substituir uma fonte menor.  
  
 Se o `DT_CALCRECT` sinalizador for especificado, o retângulo especificado por `lpRect` será atualizada para refletir a largura e altura necessários para desenhar o texto.  
  
 Se o **TA_UPDATECP** alinhamento de texto sinalizador foi definido (consulte [CDC::SetTextAlign](#settextalign)), `DrawText` exibirá o texto que começa na posição atual, em vez de na parte esquerda do retângulo determinado. `DrawText`não será quebrado quando o **TA_UPDATECP** sinalizador foi definido (ou seja, o `DT_WORDBREAK` sinalizador não terá nenhum efeito).  
  
 A cor do texto pode ser definida pelo [CDC::SetTextColor](#settextcolor).  
  
##  <a name="a-namedrawtextexa--cdcdrawtextex"></a><a name="drawtextex"></a>CDC::DrawTextEx  
 Formata o texto no retângulo determinado.  
  
```  
virtual int DrawTextEx(
    LPTSTR lpszString,  
    int nCount,  
    LPRECT lpRect,  
    UINT nFormat,
    LPDRAWTEXTPARAMS lpDTParams);

 
int DrawTextEx(
    const CString& str,  
    LPRECT lpRect,  
    UINT nFormat,
    LPDRAWTEXTPARAMS lpDTParams);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszString`  
 Aponta para a cadeia de caracteres a ser desenhada. Se `nCount` é –&1;, a cadeia de caracteres deve ser terminado em null.  
  
 `nCount`  
 Especifica o número de caracteres na cadeia de caracteres. Se `nCount` é –&1;, em seguida, `lpszString` é considerado como um ponteiro long para uma cadeia de caracteres terminada em nulo e `DrawText` calcula o número de caracteres automaticamente.  
  
 `lpRect`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que contém o retângulo (em coordenadas lógicas) no qual o texto é a ser formatado.  
  
 `str`  
 A [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém os caracteres especificados a ser desenhada.  
  
 `nFormat`  
 Especifica o método de formatação de texto. Ele pode ser qualquer combinação dos valores descritos para a `uFormat` parâmetro em [DrawText](http://msdn.microsoft.com/library/windows/desktop/dd162498) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. (Combinar, usando o bit a bit `OR` operador):  
  
> [!NOTE]
>  Alguns `uFormat` combinações de sinalizador podem fazer com que a cadeia de caracteres transmitida a ser modificado. Usando **DT_MODIFYSTRING** com um **DT_END_ELLIPSIS** ou **DT_PATH_ELLIPSIS** pode fazer com que a cadeia de caracteres a ser modificada, causando uma asserção no `CString` substituir. Os valores `DT_CALCRECT`, `DT_EXTERNALLEADING`, **DT_INTERNAL**, `DT_NOCLIP`, e `DT_NOPREFIX` não pode ser usado com o `DT_TABSTOP` valor.  
  
 `lpDTParams`  
 Ponteiro para uma [DRAWTEXTPARAMS](http://msdn.microsoft.com/library/windows/desktop/dd162500) opções de estrutura que especifica a formatação adicional. Esse parâmetro pode ser **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Formata texto, expandindo tabulações em espaços apropriados, alinhar texto à esquerda, direita ou centro do retângulo de determinado e dividindo o texto em linhas que cabem dentro do retângulo de determinado. O tipo de formatação é especificado pelo `nFormat` e `lpDTParams`. Para obter mais informações, consulte [CDC::DrawText](#drawtext) e [DrawTextEx](http://msdn.microsoft.com/library/windows/desktop/dd162499) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 A cor do texto pode ser definida pelo [CDC::SetTextColor](#settextcolor).  
  
##  <a name="a-nameellipsea--cdcellipse"></a><a name="ellipse"></a>CDC::Ellipse  
 Desenha uma elipse.  
  
```  
BOOL Ellipse(
    int x1,  
    int y1,  
    int x2,  
    int y2);  
  
BOOL Ellipse(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `x1`  
 Especifica a coordenada x lógica do canto superior esquerdo do retângulo delimitador da elipse.  
  
 `y1`  
 Especifica a coordenada y lógica do canto superior esquerdo do retângulo delimitador da elipse.  
  
 `x2`  
 Especifica a coordenada x lógica do canto inferior direito do retângulo delimitador da elipse.  
  
 `y2`  
 Especifica a coordenada y lógica do canto inferior direito do retângulo delimitador da elipse.  
  
 `lpRect`  
 Especifica que a elipse delimitadora do retângulo. Você também pode passar um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O centro da elipse é o centro do retângulo delimitador especificado por `x1`, `y1`, `x2`, e `y2`, ou `lpRect`. A elipse é desenhada com a caneta atual e seu interior é preenchido com o pincel atual.  
  
 A Figura desenhada por essa função se estende até, mas não inclui as coordenadas da direita e inferior. Isso significa que a altura da figura `y2` – `y1` e a largura da figura é `x2` – `x1`.  
  
 Se a largura ou altura do retângulo delimitador for 0, nenhum elipse é desenhada.  
  
##  <a name="a-nameenddoca--cdcenddoc"></a><a name="enddoc"></a>CDC::EndDoc  
 Termina um trabalho de impressão iniciado por uma chamada para o [StartDoc](#startdoc) função de membro.  
  
```  
int EndDoc();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Maior que ou igual a 0 se a função for bem-sucedida, ou um valor negativo se ocorreu um erro.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro substitui o **ENDDOC** escape de impressora e deve ser chamado imediatamente depois de concluir um trabalho de impressão com êxito.  
  
 Se um aplicativo encontra um erro de impressão ou uma operação de impressa cancelada, ele não deve tentar encerrar a operação usando o `EndDoc` ou [AbortDoc](#abortdoc). GDI interrompe a operação antes de retornar o valor de erro.  
  
 Essa função não deve ser usada dentro de metarquivos.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CDC::StartDoc](#startdoc).  
  
##  <a name="a-nameendpagea--cdcendpage"></a><a name="endpage"></a>CDC::EndPage  
 Informa ao dispositivo que o aplicativo terminar de gravar em uma página.  
  
```  
int EndPage();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Maior que ou igual a 0 se a função for bem-sucedida, ou um valor negativo se ocorreu um erro.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro normalmente é usada para direcionar o driver de dispositivo para ir para uma nova página.  
  
 Essa função membro substitui o **NEWFRAME** escape de impressora. Ao contrário de **NEWFRAME**, essa função é sempre chamada depois de imprimir uma página.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CDC::StartDoc](#startdoc).  
  
##  <a name="a-nameendpatha--cdcendpath"></a><a name="endpath"></a>CDC::EndPath  
 Fecha um colchete de caminho e seleciona o caminho definido pelo suporte para o contexto de dispositivo.  
  
```  
BOOL EndPath();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CDC:: beginpath](#beginpath).  
  
##  <a name="a-nameenumobjectsa--cdcenumobjects"></a><a name="enumobjects"></a>CDC:: enumobjects  
 Enumera as canetas e pincéis disponíveis em um contexto de dispositivo.  
  
```  
int EnumObjects(
    int nObjectType,  
    int (CALLBACK* lpfn)(
    LPVOID,
    LPARAM),  
    LPARAM lpData);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nObjectType*  
 Especifica o tipo de objeto. Ele pode ter os valores **OBJ_BRUSH** ou **OBJ_PEN**.  
  
 `lpfn`  
 É o endereço do procedimento instância da função de retorno de chamada fornecido pelo aplicativo. Consulte a seção "Comentários" abaixo.  
  
 `lpData`  
 Aponta para os dados fornecidos pelo aplicativo. Os dados são passados para a função de retorno de chamada junto com as informações do objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o último valor retornado pelo [função de retorno de chamada](../../mfc/reference/callback-function-for-cdc-enumobjects.md). Seu significado é definido pelo usuário.  
  
### <a name="remarks"></a>Comentários  
 Para cada objeto de um determinado tipo, a função de retorno de chamada que você passe é chamada com as informações para esse objeto. O sistema chama a função de retorno de chamada até que não existem mais objetos ou a função de retorno de chamada retornará 0.  
  
 Observe que novos recursos do Microsoft Visual C++ permitem que você use uma função comum como a função passado para `EnumObjects`. O endereço passado para `EnumObjects` é um ponteiro para uma função exportada com **exportar** e com a convenção de chamada do Pascal. Em aplicativos de modo de segurança, você não precisa criar esta função com a função em MakeProcInstanc Windows ou liberar a função após o uso com a função do FreeProcInstance Windows.  
  
 Também não é necessário exportar o nome de função em uma **exportações** declaração no arquivo de definição de módulo do aplicativo. Você pode usar o **exportar** função modificador, como em  
  
 **int exportar de retorno de chamada** AFunction **(LPSTR**, **LPSTR);**  
  
 Para fazer com que o compilador emita o registro de exportação adequado para exportação por nome sem alias. Isso funciona para a maioria das necessidades. Em alguns casos especiais, como exportar uma função por ordinal ou alias a exportação, você ainda precisa usar um **exportações** instrução em um arquivo de definição de módulo.  
  
 Para compilar programas do Microsoft Foundation, você usará normalmente o /GA e opções do compilador /GEs. A opção de compilador /Gw não é usada com as Microsoft Foundation classes. (Se você usar a função do Windows **em MakeProcInstanc**, será necessário converter explicitamente o ponteiro de função retornado de **FARPROC** no tipo necessário nessa API.) Interfaces de registro de retorno de chamada agora são fortemente tipadas (você deve transmitir um ponteiro de função que aponta para o tipo correto de função para o retorno de chamada específico).  
  
 Observe também que todas as funções de retorno de chamada devem interceptar exceções Microsoft Foundation antes de retornar ao Windows, como exceções não podem ser geradas em limites de retorno de chamada. Para obter mais informações sobre exceções, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#35;](../../mfc/codesnippet/cpp/cdc-class_7.cpp)]  
  
##  <a name="a-nameescapea--cdcescape"></a><a name="escape"></a>CDC::escape  
 Essa função de membro é praticamente obsoleta para programação Win32.  
  
```  
virtual int Escape(
    int nEscape,  
    int nCount,  
    LPCSTR lpszInData,  
    LPVOID lpOutData);

 
int Escape(
    int nEscape,  
    int nInputSize,  
    LPCSTR lpszInputData,  
    int nOutputSize,  
    LPSTR lpszOutputData);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nEscape`  
 Especifica a função de escape para ser executada.  
  
 Para obter uma lista completa das funções de escape, consulte [Escape](http://msdn.microsoft.com/library/windows/desktop/dd162701) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `nCount`  
 Especifica o número de bytes dos dados apontados por `lpszInData`.  
  
 `lpszInData`  
 Aponta para a estrutura de dados de entrada necessários para este escape.  
  
 `lpOutData`  
 Aponta para a estrutura que deve receber a saída desse escape. O `lpOutData` parâmetro é **nulo** se nenhum dado será retornado.  
  
 `nInputSize`  
 Especifica o número de bytes de dados que aponta para o `lpszInputData` parâmetro.  
  
 `lpszInputData`  
 Aponta para a estrutura de entrada necessários para o escape especificado.  
  
 `nOutputSize`  
 Especifica o número de bytes de dados que aponta para o `lpszOutputData` parâmetro.  
  
 `lpszOutputData`  
 Aponta para a estrutura que recebe a saída desse escape. Este parâmetro deve ser **nulo** se nenhum dado será retornado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor positivo será retornado se a função for bem-sucedida, exceto para o **QUERYESCSUPPORT** escape, que verifica somente para implementação. Zero será retornada se o escape não está implementado. Um valor negativo é retornado se ocorreu um erro. Os seguintes valores de erro comuns são:  
  
- **SP_ERROR** erro geral.  
  
- **SP_OUTOFDISK** não há espaço em disco está disponível atualmente para o spool e não há mais espaço se tornará disponível.  
  
- **SP_OUTOFMEMORY** não há memória suficiente está disponível para o spool.  
  
- **SP_USERABORT** usuário terminou o trabalho por meio do Gerenciador de impressão.  
  
### <a name="remarks"></a>Comentários  
 Do que o original escapes de impressora, apenas **QUERYESCSUPPORT** é compatível com aplicativos Win32. Todos os outros escapes de impressora são obsoletos e têm suporte somente para compatibilidade com aplicativos de 16 bits.  
  
 Para a programação do Win32, `CDC` agora fornece seis funções de membro que substituem seus correspondentes escapes de impressora:  
  
- [CDC::AbortDoc](#abortdoc)  
  
- [CDC::EndDoc](#enddoc)  
  
- [CDC::EndPage](#endpage)  
  
- [CDC:: SetAbortProc](#setabortproc)  
  
- [CDC::StartDoc](#startdoc)  
  
- [CDC::StartPage](#startpage)  
  
 Além disso, [CDC::GetDeviceCaps](#getdevicecaps) oferece suporte a índices de Win32 que substituem outros escapes de impressora. Consulte [GetDeviceCaps](http://msdn.microsoft.com/library/windows/desktop/dd144877) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações.  
  
 Essa função de membro permite que aplicativos acessem os recursos de um determinado dispositivo que não estão diretamente disponíveis através de GDI.  
  
 Use a primeira versão, se seu aplicativo usa os valores de escape predefinidos. Use a segunda versão, se seu aplicativo define os valores de escape privada. Consulte [ExtEscape](http://msdn.microsoft.com/library/windows/desktop/dd162708) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações sobre a segunda versão.  
  
##  <a name="a-nameexcludecliprecta--cdcexcludecliprect"></a><a name="excludecliprect"></a>CDC::ExcludeClipRect  
 Cria uma nova região de recorte consiste da região de recorte existente, menos o retângulo especificado.  
  
```  
int ExcludeClipRect(
    int x1,  
    int y1,  
    int x2,  
    int y2);  
  
int ExcludeClipRect(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `x1`  
 Especifica a coordenada x lógica do canto superior esquerdo do retângulo.  
  
 `y1`  
 Especifica a coordenada y lógica do canto superior esquerdo do retângulo.  
  
 `x2`  
 Especifica a coordenada x lógica do canto inferior direito do retângulo.  
  
 `y2`  
 Especifica a coordenada y lógica do canto inferior direito do retângulo.  
  
 `lpRect`  
 Especifica o retângulo. Também pode ser um `CRect` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o tipo da nova região de recorte. Ele pode ser qualquer um dos seguintes valores:  
  
- **COMPLEXREGION** a região tiver bordas de sobreposição.  
  
- **Erro** nenhuma região foi criado.  
  
- **NULLREGION** a região está vazia.  
  
- **SIMPLEREGION** a região tem sem bordas sobrepostas.  
  
### <a name="remarks"></a>Comentários  
 A largura do retângulo, especificado pelo valor absoluto do `x2` – `x1`, não deve exceder 32.767 unidades. Esse limite se aplica à altura do retângulo também.  
  
##  <a name="a-nameexcludeupdatergna--cdcexcludeupdatergn"></a><a name="excludeupdatergn"></a>CDC::ExcludeUpdateRgn  
 Impede que o desenho nas áreas inválidos de uma janela com a exclusão de uma região atualizada na janela da região de recorte associado a `CDC` objeto.  
  
```  
int ExcludeUpdateRgn(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Aponta para o objeto de janela cuja janela está sendo atualizada.  
  
### <a name="return-value"></a>Valor de retorno  
 O tipo de região excluído. Ele pode ser qualquer um dos seguintes valores:  
  
- **COMPLEXREGION** a região tiver bordas de sobreposição.  
  
- **Erro** nenhuma região foi criado.  
  
- **NULLREGION** a região está vazia.  
  
- **SIMPLEREGION** a região tem sem bordas sobrepostas.  
  
##  <a name="a-nameextfloodfilla--cdcextfloodfill"></a><a name="extfloodfill"></a>CDC::ExtFloodFill  
 Preenche uma área da superfície de exibição com o pincel atual.  
  
```  
BOOL ExtFloodFill(
    int x,  
    int y,  
    COLORREF crColor,  
    UINT nFillType);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica do ponto onde começa o preenchimento.  
  
 *y*  
 Especifica a coordenada y lógica do ponto onde começa o preenchimento.  
  
 `crColor`  
 Especifica a cor do limite ou da área a ser preenchido. A interpretação de `crColor` depende do valor de `nFillType`.  
  
 `nFillType`  
 Especifica o tipo de preenchimento de saturação a ser executada. Ele deve ser um dos seguintes valores:  
  
- **FLOODFILLBORDER** na área de preenchimento é limitada pela cor especificada pelo `crColor`. Esse estilo é idêntico ao preenchimento executado pelo `FloodFill`.  
  
- **FLOODFILLSURFACE** na área de preenchimento é definida pela cor especificada pelo `crColor`. Preenchimento para fora continua em todas as direções, desde que a cor é encontrada. Esse estilo é útil para preencher as áreas com limites multicoloridos.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 se o preenchimento não pôde ser concluído, se o ponto tem o limite de cor especificada por `crColor` (se **FLOODFILLBORDER** foi solicitado), se o ponto fornecido não tem a cor especificada pela `crColor` (se **FLOODFILLSURFACE** foi solicitado), ou se o ponto está fora da região de recorte.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro oferece mais flexibilidade do que `FloodFill` porque você pode especificar um tipo de preenchimento em `nFillType`.  
  
 Se `nFillType` é definido como **FLOODFILLBORDER**, a área deve ser completamente limitado pela cor especificada pelo `crColor`. A função começa no ponto especificado por *x* e *y* e preencha todas as direções para o limite de cor.  
  
 Se `nFillType` é definido como **FLOODFILLSURFACE**, a função começa no ponto especificado por *x* e *y* e continua em todas as direções, preenchimento de todas as áreas adjacentes que contém a cor especificada pela `crColor`.  
  
 Apenas contextos de dispositivo de memória e os dispositivos que suportam o suporte à tecnologia de exibição de varredura `ExtFloodFill`. Para obter mais informações, consulte o [GetDeviceCaps](#getdevicecaps) função de membro.  
  
##  <a name="a-nameexttextouta--cdcexttextout"></a><a name="exttextout"></a>CDC::ExtTextOut  
 Chame essa função de membro para gravar uma cadeia de caracteres dentro de uma região retangular usando a fonte atualmente selecionada.  
  
```  
virtual BOOL ExtTextOut(
    int x,  
    int y,  
    UINT nOptions,  
    LPCRECT lpRect,  
    LPCTSTR lpszString,  
    UINT nCount,  
    LPINT lpDxWidths);

 
BOOL ExtTextOut(
    int x,  
    int y,  
    UINT nOptions,  
    LPCRECT lpRect,  
    const CString& str,  
    LPINT lpDxWidths);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica da célula do caractere para o primeiro caractere na cadeia de caracteres especificada.  
  
 *y*  
 Especifica a coordenada y lógica na parte superior da célula do caractere para o primeiro caractere na cadeia de caracteres especificada.  
  
 `nOptions`  
 Especifica o tipo de retângulo. Esse parâmetro pode ser um, ambos ou nenhum dos seguintes valores:  
  
- **ETO_CLIPPED** Especifica que o texto é recortado para o retângulo.  
  
- **ETO_OPAQUE** Especifica que a cor atual do plano de fundo preenche o retângulo. (Você pode definir e consultar a cor de plano de fundo atual com o [SetBkColor](#setbkcolor) e [GetBkColor](#getbkcolor) funções de membro.)  
  
 `lpRect`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura que determina as dimensões do retângulo. Esse parâmetro pode ser **nulo**. Você também pode passar um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto para esse parâmetro.  
  
 `lpszString`  
 Aponta para a cadeia de caracteres especificada a ser desenhada. Você também pode passar um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto para esse parâmetro.  
  
 `nCount`  
 Especifica o número de caracteres na cadeia de caracteres.  
  
 `lpDxWidths`  
 Aponta para uma matriz de valores que indicam a distância entre as origens das células adjacentes de caracteres. Por exemplo, `lpDxWidths`[ *,*] unidades lógicas separará as origens de célula do caractere *,* e caractere célula *,* + 1. Se `lpDxWidths` é **nulo**, `ExtTextOut` usa o espaçamento padrão entre caracteres.  
  
 `str`  
 Um `CString` objeto que contém os caracteres especificados a ser desenhada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A região retangular pode ser opaca (preenchida com a cor de plano de fundo atual) e pode ser uma região de recorte.  
  
 Se `nOptions` é 0 e `lpRect` é **nulo**, a função escreve o texto para o contexto de dispositivo sem usar uma região retangular. Por padrão, a posição atual não é usada nem atualizada pela função. Se um aplicativo precisar atualizar a posição atual quando ele chama `ExtTextOut`, o aplicativo pode chamar o `CDC` função de membro [SetTextAlign](#settextalign) com `nFlags` definida como **TA_UPDATECP**. Quando esse sinalizador estiver definido, o Windows ignora *x* e *y* em chamadas subsequentes para `ExtTextOut` e usa a posição atual em vez disso. Quando um aplicativo usa **TA_UPDATECP** para atualizar a posição atual, `ExtTextOut` define a posição atual no final da linha anterior de texto ou para a posição especificada, o último elemento da matriz apontada por `lpDxWidths`, o que for maior.  
  
##  <a name="a-namefillpatha--cdcfillpath"></a><a name="fillpath"></a>CDC::FillPath  
 Fecha qualquer figuras abertas no caminho atual e preenche o interior do caminho usando o pincel atual e o modo de preenchimento de polígono.  
  
```  
BOOL FillPath();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Depois que seu interior é preenchido, o caminho é descartado do contexto do dispositivo.  
  
##  <a name="a-namefillrecta--cdcfillrect"></a><a name="fillrect"></a>CDC::FillRect  
 Chame essa função de membro para preencher um retângulo determinado usando o pincel especificado.  
  
```  
void FillRect(
    LPCRECT lpRect,  
    CBrush* pBrush);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura que contém as coordenadas lógicas do retângulo para ser preenchido. Você também pode passar um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto para esse parâmetro.  
  
 `pBrush`  
 Identifica o pincel usado para preencher o retângulo.  
  
### <a name="remarks"></a>Comentários  
 A função preenche o retângulo completo, incluindo as bordas esquerdas e superior, mas ela não preencher as bordas direita e inferior.  
  
 O pincel precisa ao ser criado usando o [CBrush](../../mfc/reference/cbrush-class.md) funções de membro [CreateHatchBrush](../../mfc/reference/cbrush-class.md#createhatchbrush), [CreatePatternBrush](../../mfc/reference/cbrush-class.md#createpatternbrush), e [CreateSolidBrush](../../mfc/reference/cbrush-class.md#createsolidbrush), ou recuperada pelo `GetStockObject` função do Windows.  
  
 Durante o preenchimento do retângulo especificado, `FillRect` não inclui os lados de direita e inferior do retângulo. GDI preenche um retângulo até, mas não inclui a linha inferior e de coluna à direita, independentemente do modo de mapeamento atual. `FillRect`compara os valores da **superior**, **inferior**, **esquerda**, e **direita** membros do retângulo especificado. Se **inferior** é menor que ou igual a **superior**, ou se **direita** é menor que ou igual a **esquerda**, o retângulo não é desenhado.  
  
 `FillRect`é semelhante ao [CDC::FillSolidRect](#fillsolidrect); no entanto, `FillRect` usa um pincel e, portanto, pode ser usado para preencher um retângulo com uma cor sólida, uma cor pontilhada, tracejadas pincéis ou um padrão. `FillSolidRect`usa apenas cores sólidas (indicado por um **COLORREF** parâmetro). `FillRect`geralmente é mais lenta que `FillSolidRect`.  
  
##  <a name="a-namefillrgna--cdcfillrgn"></a><a name="fillrgn"></a>CDC::FillRgn  
 Preenche a área especificada pelo `pRgn` com o pincel especificado por `pBrush`.  
  
```  
BOOL FillRgn(
    CRgn* pRgn,  
    CBrush* pBrush);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRgn`  
 Um ponteiro para a região a ser preenchido. As coordenadas de determinada região são especificadas em unidades lógicas.  
  
 `pBrush`  
 Identifica o pincel a ser usada para preencher a região.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O pincel deve ser criado usando o `CBrush` funções de membro `CreateHatchBrush`, `CreatePatternBrush`, `CreateSolidBrush`, ou ser recuperada pelo **GetStockObject**.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRgn::CreateRoundRectRgn](../../mfc/reference/crgn-class.md#createroundrectrgn).  
  
##  <a name="a-namefillsolidrecta--cdcfillsolidrect"></a><a name="fillsolidrect"></a>CDC::FillSolidRect  
 Chame essa função de membro para preencher o retângulo fornecido com a cor sólida especificada.  
  
```  
void FillSolidRect(
    LPCRECT lpRect,  
    COLORREF clr);

 
void FillSolidRect(
    int x,  
    int y,  
    int cx,  
    int cy,  
    COLORREF clr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Especifica o retângulo delimitador (em unidades lógicas). Você pode passar um ponteiro para um [RECT](../../mfc/reference/rect-structure1.md) estrutura de dados ou um `CRect` objeto para esse parâmetro.  
  
 `clr`Especifica a cor a ser usada para preencher o retângulo.  
  
 *x*  
 Especifica a coordenada x lógica do canto superior esquerdo do retângulo.  
  
 *y*  
 Especifica a coordenada y lógica do canto superior esquerdo do retângulo de destino.  
  
 `cx`  
 Especifica a largura do retângulo.  
  
 `cy`  
 Especifica a altura do retângulo.  
  
### <a name="remarks"></a>Comentários  
 `FillSolidRect`é muito semelhante ao [CDC::FillRect](#fillrect); no entanto, `FillSolidRect` usa apenas cores sólidas (indicado pelo **COLORREF** parâmetro), enquanto `FillRect` usa um pincel e, portanto, pode ser usado para preencher um retângulo com uma cor sólida, uma cor pontilhada, tracejadas pincéis ou um padrão. `FillSolidRect`geralmente é mais rápido do que `FillRect`.  
  
> [!NOTE]
>  Quando você chama `FillSolidRect`, a cor de fundo definida anteriormente usando [SetBkColor](#setbkcolor), é definido como a cor indicada por `clr`.  
  
##  <a name="a-nameflattenpatha--cdcflattenpath"></a><a name="flattenpath"></a>CDC::FlattenPath  
 Transforma qualquer curvas no caminho selecionado no contexto de dispositivo atual e transforma cada curva em uma sequência de linhas.  
  
```  
BOOL FlattenPath();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
##  <a name="a-namefloodfilla--cdcfloodfill"></a><a name="floodfill"></a>CDC::FloodFill  
 Preenche uma área da superfície de exibição com o pincel atual.  
  
```  
BOOL FloodFill(
    int x,  
    int y,  
    COLORREF crColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica do ponto onde começa o preenchimento.  
  
 *y*  
 Especifica a coordenada y lógica do ponto onde começa o preenchimento.  
  
 `crColor`  
 Especifica a cor do limite.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 é retornado se o preenchimento não pôde ser concluído, o ponto tem a cor do limite especificada pelo `crColor`, ou o ponto está fora da região de recorte.  
  
### <a name="remarks"></a>Comentários  
 A área é considerada ser delimitada como especificado pelo `crColor`. O `FloodFill` função começa no ponto especificado por *x* e *y* e continua em todas as direções para o limite de cor.  
  
 Apenas contextos de dispositivo de memória e os dispositivos que suportam o suporte à tecnologia de exibição de varredura de `FloodFill` função de membro. Para obter informações sobre **RC_BITBLT** recurso, consulte o `GetDeviceCaps` função de membro.  
  
 O `ExtFloodFill` função fornece funcionalidade semelhante mas maior flexibilidade.  
  
##  <a name="a-nameframerecta--cdcframerect"></a><a name="framerect"></a>CDC::FrameRect  
 Desenha uma borda em torno do retângulo especificado por `lpRect`.  
  
```  
void FrameRect(
    LPCRECT lpRect,  
    CBrush* pBrush);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que contém as coordenadas lógicas dos cantos superior esquerdo e direito inferior do retângulo. Você também pode passar um `CRect` objeto para esse parâmetro.  
  
 `pBrush`  
 Identifica o pincel a ser usado para o retângulo de delimitação de quadros.  
  
### <a name="remarks"></a>Comentários  
 A função usa o pincel determinado para desenhar a borda. A largura e altura da borda é sempre 1 unidade lógica.  
  
 Se o retângulo **inferior** coordenada é menor ou igual a **superior**, ou se **direita** é menor que ou igual a **esquerda**, o retângulo não é desenhado.  
  
 A borda desenhada pelo `FrameRect` está na mesma posição de uma borda desenhada pelo **retângulo** usando as mesmas coordenadas de função de membro (se **retângulo** usa uma caneta é 1 ampla de unidade lógica). O interior do retângulo não é preenchido por `FrameRect`.  
  
##  <a name="a-nameframergna--cdcframergn"></a><a name="framergn"></a>CDC::FrameRgn  
 Desenha uma borda em torno da região especificada por `pRgn` usando o pincel especificado por `pBrush`.  
  
```  
BOOL FrameRgn(
    CRgn* pRgn,  
    CBrush* pBrush,  
    int nWidth,  
    int nHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRgn`  
 Aponta para a `CRgn` objeto que identifica a região sejam colocados em uma borda. As coordenadas de determinada região são especificadas em unidades lógicas.  
  
 `pBrush`  
 Aponta para a `CBrush` objeto que identifica o pincel a ser usado para desenhar a borda.  
  
 `nWidth`  
 Especifica a largura da borda em traçados de pincel vertical em unidades de dispositivo.  
  
 `nHeight`  
 Especifica a altura da borda em traçados de pincel horizontal em unidades de dispositivo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRgn::CombineRgn](../../mfc/reference/crgn-class.md#combinergn).  
  
##  <a name="a-namefromhandlea--cdcfromhandle"></a><a name="fromhandle"></a>CDC::FromHandle  
 Retorna um ponteiro para um `CDC` objeto quando recebe um identificador para um contexto de dispositivo.  
  
```  
static CDC* PASCAL FromHandle(HDC hDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hDC`  
 Contém um identificador para um contexto de dispositivo do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 O ponteiro pode ser temporário e não deve ser armazenado além do uso imediato.  
  
### <a name="remarks"></a>Comentários  
 Se um `CDC` objeto não está anexado ao identificador, um temporário `CDC` objeto é criado e anexado.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPrintDialog::GetPrinterDC](../../mfc/reference/cprintdialog-class.md#getprinterdc).  
  
##  <a name="a-namegetarcdirectiona--cdcgetarcdirection"></a><a name="getarcdirection"></a>CDC::GetArcDirection  
 Retorna a direção do arco atual para o contexto do dispositivo.  
  
```  
int GetArcDirection() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica a direção do arco atual, se for bem-sucedido. A seguir está os valores de retornos válidos:  
  
- **AD_COUNTERCLOCKWISE** arcos e retângulos desenhados no sentido anti-horário.  
  
- **AD_CLOCKWISE** arcos e retângulos desenhados no sentido horário.  
  
 Se ocorrer um erro, o valor de retorno será zero.  
  
### <a name="remarks"></a>Comentários  
 Arco e retângulo funções usam a direção do arco.  
  
##  <a name="a-namegetaspectratiofiltera--cdcgetaspectratiofilter"></a><a name="getaspectratiofilter"></a>CDC::GetAspectRatioFilter  
 Recupera a configuração para o filtro de taxa de proporção atual.  
  
```  
CSize GetAspectRatioFilter() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CSize` objeto que representa a taxa de proporção usada pelo filtro de taxa de proporção atual.  
  
### <a name="remarks"></a>Comentários  
 A taxa de proporção é a proporção formada pela largura em pixels do dispositivo e a altura. Informações sobre a taxa de proporção de um dispositivo são usadas na criação, seleção e exibição de fontes. O Windows fornece um filtro especial, o filtro de taxa de proporção, selecione fontes destinadas a uma determinada taxa de proporção de todas as fontes disponíveis. O filtro usa a taxa de proporção especificada pelo `SetMapperFlags` função de membro.  
  
##  <a name="a-namegetbkcolora--cdcgetbkcolor"></a><a name="getbkcolor"></a>CDC::GetBkColor  
 Retorna a cor de plano de fundo atual.  
  
```  
COLORREF GetBkColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de cor RGB.  
  
### <a name="remarks"></a>Comentários  
 Se o modo de plano de fundo é **OPACO**, o sistema usa a cor de plano de fundo para preencher as lacunas em linhas com estilo, as lacunas entre linhas tracejadas pincéis e o plano de fundo em células de caractere. O sistema também usa a cor de plano de fundo ao converter bitmaps entre cor e contextos de dispositivo monocromático.  
  
##  <a name="a-namegetbkmodea--cdcgetbkmode"></a><a name="getbkmode"></a>CDC::GetBkMode  
 Retorna o modo de plano de fundo.  
  
```  
int GetBkMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O modo de plano de fundo atual, que pode ser **OPACO** ou **TRANSPARENT**.  
  
### <a name="remarks"></a>Comentários  
 O modo de plano de fundo define se o sistema remove as cores de plano de fundo existentes na superfície de desenho antes de desenho de texto, pincéis tracejadas ou qualquer estilo de caneta que não seja uma linha sólida.  
  
##  <a name="a-namegetboundsrecta--cdcgetboundsrect"></a><a name="getboundsrect"></a>CDC::GetBoundsRect  
 Retorna o retângulo delimitador acumulado atual para o contexto de dispositivo especificado.  
  
```  
UINT GetBoundsRect(
    LPRECT lpRectBounds,  
    UINT flags);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRectBounds`  
 Aponta para um buffer que receberá o retângulo delimitador atual. O retângulo é retornado em coordenadas lógicas.  
  
 `flags`  
 Especifica se o retângulo delimitador deve ser limpa depois que ele é retornado. Esse parâmetro deve ser zero ou definido para o seguinte valor:  
  
- **DCB_RESET** força o retângulo delimitador a ser limpa depois que ele é retornado.  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o estado atual do retângulo delimitador se a função for bem-sucedida. Pode ser uma combinação dos seguintes valores:  
  
- **DCB_ACCUMULATE** delimitadora acúmulo de retângulo está ocorrendo.  
  
- **DCB_RESET** Bounding retângulo está vazio.  
  
- **DCB_SET** Bounding retângulo não está vazio.  
  
- **DCB_ENABLE** delimitadora acúmulo é no.  
  
- **DCB_DISABLE** delimitadora acúmulo está desativado.  
  
##  <a name="a-namegetbrushorga--cdcgetbrushorg"></a><a name="getbrushorg"></a>CDC::GetBrushOrg  
 Recupera a origem (em unidades de dispositivo) do pincel selecionada no momento para o contexto do dispositivo.  
  
```  
CPoint GetBrushOrg() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A origem atual do pincel (em unidades de dispositivo) como um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 A origem do pincel inicial é em (0,0) da área do cliente. O valor de retorno especifica esse ponto em unidades de dispositivo em relação à origem da janela da área de trabalho.  
  
##  <a name="a-namegetcharacterplacementa--cdcgetcharacterplacement"></a><a name="getcharacterplacement"></a>CDC::GetCharacterPlacement  
 Recupera vários tipos de informações em uma cadeia de caracteres.  
  
```  
DWORD GetCharacterPlacement(
    LPCTSTR lpString,  
    int nCount,  
    int nMaxExtent,  
    LPGCP_RESULTS lpResults,  
    DWORD dwFlags) const;  
  
DWORD GetCharacterPlacement(
    CString& str,  
    int nMaxExtent,  
    LPGCP_RESULTS lpResults,  
    DWORD dwFlags) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpString`  
 Um ponteiro para a cadeia de caracteres para processar.  
  
 `nCount`  
 Especifica o comprimento da cadeia de caracteres. Para a versão ANSI, é uma contagem de bytes e para a função Unicode é uma contagem de PALAVRAS. Para obter mais informações, consulte [GetCharacterPlacement](http://msdn.microsoft.com/library/windows/desktop/dd144860\(v=vs.85\).aspx).  
  
 `nMaxExtent`  
 Especifica o máximo (em unidades lógicas) para que a cadeia de caracteres é processada. Caracteres que, se processado, excederão dessa extensão são ignorados. Computações de quaisquer matrizes de ordenação ou glifo necessário se aplicam somente aos caracteres incluídos. Esse parâmetro é usado somente se o valor GCP_MAXEXTENT é especificado no `dwFlags` parâmetro. Como a função processa a cadeia de caracteres de entrada, cada caractere e sua extensão é adicionada para a saída, extensão e outras matrizes somente se a extensão total ainda não excedeu o máximo. Quando o limite for atingido, o processamento será interrompido.  
  
 lpResults  
 Ponteiro para uma [GCP_Results](http://msdn.microsoft.com/library/windows/desktop/dd144842\(v=vs.85\).aspx) estrutura que recebe os resultados da função.  
  
 `dwFlags`  
 Especifica como processar a cadeia de caracteres nas matrizes necessárias. Esse parâmetro pode ser um ou mais dos valores listados no `dwFlags` seção o [GetCharacterPlacement](http://msdn.microsoft.com/library/windows/desktop/dd144860\(v=vs.85\).aspx) tópico.  
  
 `str`  
 Um ponteiro para um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto ao processo.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função obtiver êxito, o valor de retorno é a largura e altura da cadeia de caracteres em unidades lógicas.  
  
 Se a função falhar, o valor retornado será zero.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade da função [GetCharacterPlacement](http://msdn.microsoft.com/library/windows/desktop/dd144860\(v=vs.85\).aspx), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetcharabcwidthsa--cdcgetcharabcwidths"></a><a name="getcharabcwidths"></a>CDC::GetCharABCWidths  
 Recupera as larguras de caracteres consecutivos em um intervalo especificado de fonte TrueType atual.  
  
```  
BOOL GetCharABCWidths(
    UINT nFirstChar,  
    UINT nLastChar,  
    LPABC lpabc) const;  
  
BOOL GetCharABCWidths(
    UINT nFirstChar,  
    UINT nLastChar,  
    LPABCFLOAT lpABCF) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nFirstChar`  
 Especifica o primeiro caractere no intervalo de caracteres da fonte atual para o qual as larguras de caracteres são retornadas.  
  
 `nLastChar`  
 Especifica o último caractere no intervalo de caracteres da fonte atual para o qual as larguras de caracteres são retornadas.  
  
 `lpabc`  
 Aponta para uma matriz de [ABC](../../mfc/reference/abc-structure.md) estruturas que recebem as larguras de caracteres quando a função retorna. Essa matriz deve conter pelo menos tantos **ABC** estruturas como há caracteres no intervalo especificado pelo `nFirstChar` e `nLastChar` parâmetros.  
  
 *lpABCF*  
 Aponta para um buffer de aplicativo fornecido com uma matriz de [ABCFLOAT](../../mfc/reference/abcfloat-structure.md) estruturas para receber as larguras de caracteres quando a função retorna. As larguras retornadas por essa função estiver no formato de ponto flutuante IEEE.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 As larguras são retornadas em unidades lógicas. Essa função terá êxito apenas com fontes TrueType.  
  
 O rasterizador TrueType fornece espaçamento de caracteres "ABC" depois de um tamanho de ponto específico tiver sido selecionado. Espaçamento de "A" é a distância é adicionada à posição atual antes de colocar o glifo. Espaçamento de "B" é a largura da parte preta do glifo. Espaçamento de "C" é adicionado à posição atual para levar em conta o espaço em branco à direita do glifo. Avançado largura total é determinado por um + B + C.  
  
 Quando o `GetCharABCWidths` função de membro recupera negativa "A" ou "C" larguras de um caractere, o caractere inclui underhangs ou overhangs.  
  
 Para converter as larguras de ABC para unidades de design de fonte, um aplicativo deve criar uma fonte cuja altura (conforme especificado no **lfHeight** membro do [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037) estrutura) é igual ao valor armazenado na **ntmSizeEM** membro do [NEWTEXTMETRIC](http://msdn.microsoft.com/library/windows/desktop/dd162741) estrutura. (O valor de **ntmSizeEM** membro pode ser recuperado chamando o [EnumFontFamilies](http://msdn.microsoft.com/library/windows/desktop/dd162619) função do Windows.)  
  
 As larguras de ABC do caractere padrão são usadas para os caracteres que estão fora do intervalo da fonte selecionada atualmente.  
  
 Para recuperar as larguras de caracteres em fontes não-TrueType, os aplicativos devem usar o [GetCharWidth](http://msdn.microsoft.com/library/windows/desktop/dd144861) função do Windows.  
  
##  <a name="a-namegetcharabcwidthsia--cdcgetcharabcwidthsi"></a><a name="getcharabcwidthsi"></a>CDC::GetCharABCWidthsI  
 Recupera as larguras, em unidades lógicas, de índices de glifo consecutivas em um intervalo especificado de fonte TrueType atual.  
  
```  
BOOL GetCharABCWidthsI(
    UINT giFirst,  
    UINT cgi,  
    LPWORD pgi,  
    LPABC lpabc) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `giFirst`  
 Especifica o primeiro índice de glifo no grupo de índices de glifo consecutivas da fonte atual. Este parâmetro é usado somente se o `pgi` parâmetro é **nulo**.  
  
 `cgi`  
 Especifica o número de índices de glifo.  
  
 `pgi`  
 Um ponteiro para uma matriz que contém índices de glifo. Se o valor for **nulo**, o `giFirst` parâmetro é usado em vez disso. O `cgi` parâmetro especifica o número de índices de glifo nesta matriz.  
  
 `lpabc`  
 Ponteiro para uma matriz de [ABC](http://msdn.microsoft.com/library/windows/desktop/dd162454) estruturas recebendo as larguras de caracteres. Essa matriz deve conter pelo menos tantos **ABC** estruturas como existem índices de glifo especificados pela `cgi` parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade da função [GetCharABCWidthsI](http://msdn.microsoft.com/library/windows/desktop/dd144859), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetcharwidtha--cdcgetcharwidth"></a><a name="getcharwidth"></a>CDC::GetCharWidth  
 Recupera as larguras de caracteres individuais em um grupo de caracteres consecutivos de fonte atual, usando `m_hAttribDC`, o contexto de dispositivo de entrada.  
  
```  
BOOL GetCharWidth(
    UINT nFirstChar,  
    UINT nLastChar,  
    LPINT lpBuffer) const;  
  
BOOL GetCharWidth(
    UINT nFirstChar,  
    UINT nLastChar,  
    float* lpFloatBuffer) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nFirstChar`  
 Especifica o primeiro caractere em um grupo de caracteres na fonte atual consecutivos.  
  
 `nLastChar`  
 Especifica o último caractere em um grupo de caracteres na fonte atual consecutivos.  
  
 `lpBuffer`  
 Aponta para um buffer que receberá os valores de largura de um grupo de caracteres consecutivos na fonte atual.  
  
 *lpFloatBuffer*  
 Aponta para um buffer para receber as larguras de caracteres. As larguras retornadas estão no formato de ponto flutuante IEEE de 32 bits. (As larguras são medidas ao longo da linha de base de dados de caracteres).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Por exemplo, se `nFirstChar` identifica a letra 'a' e `nLastChar` identifica a letra 'z', o função recupera as larguras de todos os caracteres em minúsculas.  
  
 A função armazena os valores no buffer apontado por `lpBuffer`. Esse buffer deve ser grande o suficiente para conter todas as larguras. Ou seja, deve haver pelo menos 26 entradas no exemplo dado.  
  
 Se não existir um caractere no grupo de caracteres consecutivo em uma determinada fonte, ele será atribuído o valor da largura do caractere padrão.  
  
##  <a name="a-namegetcharwidthia--cdcgetcharwidthi"></a><a name="getcharwidthi"></a>CDC::GetCharWidthI  
 Recupera as larguras, em coordenadas lógicas, de índices de glifo consecutivas em um intervalo especificado da fonte atual.  
  
```  
BOOL GetCharWidthI(
    UINT giFirst,  
    UINT cgi,  
    LPWORD pgi,  
    LPINT lpBuffer) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `giFirst`  
 Especifica o primeiro índice de glifo no grupo de índices de glifo consecutivas da fonte atual. Este parâmetro é usado somente se o `pgi` parâmetro é **nulo**.  
  
 `cgi`  
 Especifica o número de índices de glifo.  
  
 `pgi`  
 Um ponteiro para uma matriz que contém índices de glifo. Se o valor for **nulo**, o `giFirst` parâmetro é usado em vez disso. O `cgi` parâmetro especifica o número de índices de glifo nesta matriz.  
  
 `lpBuffer`  
 Um ponteiro para um buffer que receberá as larguras.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade da função [GetCharWidthI](http://msdn.microsoft.com/library/windows/desktop/dd144864), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetclipboxa--cdcgetclipbox"></a><a name="getclipbox"></a>CDC::GetClipBox  
 Recupera as dimensões do retângulo delimitador tightest em torno do limite do recorte atual.  
  
```  
virtual int GetClipBox(LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para a [RECT](../../mfc/reference/rect-structure1.md) estrutura ou [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que receberá as dimensões do retângulo.  
  
### <a name="return-value"></a>Valor de retorno  
 Tipo da região de recorte. Ele pode ser qualquer um dos seguintes valores:  
  
- **COMPLEXREGION** região de recorte tiver bordas de sobreposição.  
  
- **Erro** o contexto de dispositivo não é válido.  
  
- **NULLREGION** região de recorte está vazio.  
  
- **SIMPLEREGION** região de recorte tiver sem bordas sobrepostas.  
  
### <a name="remarks"></a>Comentários  
 As dimensões são copiadas para o buffer apontado por `lpRect`.  
  
##  <a name="a-namegetcoloradjustmenta--cdcgetcoloradjustment"></a><a name="getcoloradjustment"></a>CDC::GetColorAdjustment  
 Recupera os valores de ajuste de cor para o contexto de dispositivo.  
  
```  
BOOL GetColorAdjustment(LPCOLORADJUSTMENT lpColorAdjust) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpColorAdjust`  
 Aponta para um [COLORADJUSTMENT](../../mfc/reference/coloradjustment-structure.md) estrutura de dados para receber os valores de ajuste de cor.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
##  <a name="a-namegetcurrentbitmapa--cdcgetcurrentbitmap"></a><a name="getcurrentbitmap"></a>CDC::GetCurrentBitmap  
 Retorna um ponteiro para selecionado no momento `CBitmap` objeto.  
  
```  
CBitmap* GetCurrentBitmap() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma `CBitmap` objeto, se bem-sucedida; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Esta função de membro pode retornar objetos temporários.  
  
##  <a name="a-namegetcurrentbrusha--cdcgetcurrentbrush"></a><a name="getcurrentbrush"></a>CDC::GetCurrentBrush  
 Retorna um ponteiro para selecionado no momento `CBrush` objeto.  
  
```  
CBrush* GetCurrentBrush() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma `CBrush` objeto, se bem-sucedida; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Esta função de membro pode retornar objetos temporários.  
  
##  <a name="a-namegetcurrentfonta--cdcgetcurrentfont"></a><a name="getcurrentfont"></a>CDC::GetCurrentFont  
 Retorna um ponteiro para selecionado no momento `CFont` objeto.  
  
```  
CFont* GetCurrentFont() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma `CFont` objeto, se bem-sucedida; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Esta função de membro pode retornar objetos temporários.  
  
##  <a name="a-namegetcurrentpalettea--cdcgetcurrentpalette"></a><a name="getcurrentpalette"></a>CDC::GetCurrentPalette  
 Retorna um ponteiro para selecionado no momento `CPalette` objeto.  
  
```  
CPalette* GetCurrentPalette() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma `CPalette` objeto, se bem-sucedida; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Esta função de membro pode retornar objetos temporários.  
  
##  <a name="a-namegetcurrentpena--cdcgetcurrentpen"></a><a name="getcurrentpen"></a>CDC::GetCurrentPen  
 Retorna um ponteiro para selecionado no momento `CPen` objeto.  
  
```  
CPen* GetCurrentPen() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma `CPen` objeto, se bem-sucedida; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Esta função de membro pode retornar objetos temporários.  
  
##  <a name="a-namegetcurrentpositiona--cdcgetcurrentposition"></a><a name="getcurrentposition"></a>CDC::GetCurrentPosition  
 Recupera a posição atual (em coordenadas lógicas).  
  
```  
CPoint GetCurrentPosition() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A posição atual como uma `CPoint` objeto.  
  
### <a name="remarks"></a>Comentários  
 A posição atual pode ser definida com o `MoveTo` função de membro.  
  
##  <a name="a-namegetdcbrushcolora--cdcgetdcbrushcolor"></a><a name="getdcbrushcolor"></a>CDC::GetDCBrushColor  
 Recupera a cor atual do pincel.  
  
```  
COLORREF GetDCBrushColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função obtiver êxito, o valor de retorno é o [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor para a cor do pincel atual.  
  
 Se a função falhar, o valor de retorno é **CLR_INVALID**.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade da função [GetDCBrushColor](http://msdn.microsoft.com/library/windows/desktop/dd144872), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetdcpencolora--cdcgetdcpencolor"></a><a name="getdcpencolor"></a>CDC::GetDCPenColor  
 Recupera a cor atual da caneta.  
  
```  
COLORREF GetDCPenColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função obtiver êxito, o valor de retorno é o [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor para a cor atual da caneta.  
  
 Se a função falhar, o valor de retorno é **CLR_INVALID**.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro utiliza a função Win32 [GetDCPenColor](http://msdn.microsoft.com/library/windows/desktop/dd144875), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetdevicecapsa--cdcgetdevicecaps"></a><a name="getdevicecaps"></a>CDC::GetDeviceCaps  
 Recupera uma ampla variedade de informações específicas de dispositivo sobre o dispositivo de vídeo.  
  
```  
int GetDeviceCaps(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o tipo de informação a ser retornada. Consulte [GetDeviceCaps](http://msdn.microsoft.com/library/windows/desktop/dd144877) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma lista de valores.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor do recurso solicitado se a função for bem-sucedida.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPrintDialog::GetDefaults](../../mfc/reference/cprintdialog-class.md#getdefaults).  
  
##  <a name="a-namegetfontdataa--cdcgetfontdata"></a><a name="getfontdata"></a>CDC::GetFontData  
 Recupera informações de métrica de fonte de um arquivo de fonte escalonável.  
  
```  
DWORD GetFontData(
    DWORD dwTable,  
    DWORD dwOffset,  
    LPVOID lpData,  
    DWORD cbData) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwTable`  
 Especifica o nome da tabela de métricas a serem retornados. Esse parâmetro pode ser uma das tabelas de métricas documentadas na especificação de arquivos de fonte TrueType, publicada pela Microsoft Corporation. Se esse parâmetro for 0, as informações são recuperadas desde o início do arquivo fonte.  
  
 `dwOffset`  
 Especifica o deslocamento do início da tabela na qual iniciar a recuperação de informações. Se esse parâmetro for 0, as informações são recuperadas desde o início da tabela especificada o `dwTable` parâmetro. Se esse valor for maior que ou igual ao tamanho da tabela, `GetFontData` retornará 0.  
  
 `lpData`  
 Aponta para um buffer que receberá as informações de fonte. Se esse valor for **nulo**, a função retorna o tamanho do buffer necessário para os dados de fonte especificados no `dwTable` parâmetro.  
  
 `cbData`  
 Especifica o comprimento, em bytes, das informações a serem recuperados. Se esse parâmetro for 0, `GetFontData` retorna o tamanho dos dados especificados no `dwTable` parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o número de bytes retornados no buffer apontado por `lpData` se a função for bem-sucedida; caso contrário -1.  
  
### <a name="remarks"></a>Comentários  
 As informações para recuperar são identificadas, especificando um deslocamento para o arquivo de fonte e o tamanho das informações a retornar.  
  
 Um aplicativo, às vezes, pode usar o `GetFontData` a função de membro para salvar uma fonte TrueType com um documento. Para fazer isso, o aplicativo determina se a fonte pode ser inserida e, em seguida, recupera o arquivo de fonte inteira, especificar 0 para o `dwTable`, `dwOffset`, e `cbData` parâmetros.  
  
 Os aplicativos podem determinar se uma fonte pode ser incorporada, verificando o **otmfsType** membro o [OUTLINETEXTMETRIC](http://msdn.microsoft.com/library/windows/desktop/dd162755) estrutura. Se o bit 1 do **otmfsType** estiver definido, a incorporação não é permitida para a fonte. Se bit 1 estiver desmarcada, a fonte pode ser incorporada. Se bit 2 estiver definido, a incorporação é somente leitura.  
  
 Se um aplicativo tenta usar essa função para recuperar informações de uma fonte não-TrueType, o `GetFontData` função membro retorna –&1;.  
  
##  <a name="a-namegetfontlanguageinfoa--cdcgetfontlanguageinfo"></a><a name="getfontlanguageinfo"></a>CDC::GetFontLanguageInfo  
 Retorna informações sobre a fonte atualmente selecionada para o contexto de exibição especificado.  
  
```  
DWORD GetFontLanguageInfo() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno identifica as características da fonte selecionada atualmente. Para obter uma lista completa de valores possíveis, consulte [GetFontLanguageInfo](http://msdn.microsoft.com/library/windows/desktop/dd144886).  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade da função [GetFontLanguageInfo](http://msdn.microsoft.com/library/windows/desktop/dd144886), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetglyphoutlinea--cdcgetglyphoutline"></a><a name="getglyphoutline"></a>CDC::GetGlyphOutline  
 Recupera a curva de estrutura de tópicos ou um bitmap de um caractere de estrutura de tópicos na fonte atual.  
  
```  
DWORD GetGlyphOutline(
    UINT nChar,  
    UINT nFormat,  
    LPGLYPHMETRICS lpgm,  
    DWORD cbBuffer,  
    LPVOID lpBuffer,  
    const MAT2* lpmat2) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nChar`  
 Especifica o caractere para que informações deve ser retornado.  
  
 `nFormat`  
 Especifica o formato no qual a função é retornar informações. Ele pode ser um dos valores a seguir, ou 0:  
  
|Valor|Significado|  
|-----------|-------------|  
|**GGO_BITMAP**|Retorna o bitmap de glifo. Quando a função retornar, o buffer apontado por `lpBuffer` contém um bitmap de 1 bit por pixel cujas linhas Iniciar em limites de palavras duplas.|  
|**GGO_NATIVE**|Retorna a curva de pontos de dados em formato nativo do rasterizador, usando unidades de dispositivo. Quando esse valor for especificado, qualquer transformação especificado em `lpmat2` é ignorado.|  
  
 Quando o valor de `nFormat` for 0, a função preenche uma [GLYPHMETRICS](http://msdn.microsoft.com/library/windows/desktop/dd144955) estrutura, mas não retorna dados de contorno do glifo.  
  
 *lpgm*  
 Aponta para um **GLYPHMETRICS** estrutura que descreve o posicionamento do glifo na célula do caractere.  
  
 `cbBuffer`  
 Especifica o tamanho do buffer no qual a função copia informações sobre o caractere de estrutura de tópicos. Se esse valor for 0 e o `nFormat` parâmetro seja o **GGO_BITMAP** ou **GGO_NATIVE** valores, a função retorna o tamanho necessário do buffer.  
  
 `lpBuffer`  
 Aponta para um buffer no qual a função copia informações sobre o caractere de estrutura de tópicos. Se `nFormat` Especifica o **GGO_NATIVE** valor, as informações é copiado na forma de **TTPOLYGONHEADER** e **TTPOLYCURVE** estruturas. Se esse valor for **nulo** e `nFormat` é o **GGO_BITMAP** ou **GGO_NATIVE** valor, a função retorna o tamanho necessário do buffer.  
  
 `lpmat2`  
 Aponta para um [MAT2](http://msdn.microsoft.com/library/windows/desktop/dd145048) estrutura que contém uma matriz de transformação do caractere. Esse parâmetro não pode ser **nulo**, mesmo quando o **GGO_NATIVE** valor for especificado para `nFormat`.  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho, em bytes, do buffer necessário para as informações recuperadas se `cbBuffer` é 0 ou `lpBuffer` é **nulo**. Caso contrário, é um valor positivo se a função for bem-sucedida, ou -1 se não houver um erro.  
  
### <a name="remarks"></a>Comentários  
 Um aplicativo pode girar caracteres recuperados no formato de bitmap especificando uma matriz de transformação 2 por 2 na estrutura apontada por `lpmat2`.  
  
 Um contorno do glifo é retornado como uma série de contornos. Cada contorno é definido por uma [TTPOLYGONHEADER](http://msdn.microsoft.com/library/windows/desktop/dd145158) estrutura seguido por tantas **TTPOLYCURVE** estruturas conforme necessário para descrevê-lo. Todos os pontos são retornados como [POINTFX](http://msdn.microsoft.com/library/windows/desktop/dd162806) estruturas e representam posições absolutas, move não relativo. O ponto inicial fornecido pelo **pfxStart** membro o [TTPOLYGONHEADER](http://msdn.microsoft.com/library/windows/desktop/dd145158) estrutura é o ponto em que a estrutura de tópicos para uma delimitação começa. O [TTPOLYCURVE](http://msdn.microsoft.com/library/windows/desktop/dd145157) estruturas a seguem podem ser polyline registros ou registros de spline. Registros de polilinha são uma série de pontos; linhas desenhadas entre os pontos descrevem o contorno do caractere. Registros de spline representam as curvas quadráticas usadas pelo TrueType (ou seja, quadrática de b-splines).  
  
##  <a name="a-namegetgraphicsmodea--cdcgetgraphicsmode"></a><a name="getgraphicsmode"></a>CDC::GetGraphicsMode  
 Recupera o modo gráfico atual para o contexto de dispositivo especificado.  
  
```  
int GetGraphicsMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o modo gráfico atual com êxito. Para obter uma lista dos valores que esse método pode retornar, consulte [GetGraphicsMode](http://msdn.microsoft.com/library/windows/desktop/dd144892).  
  
 Retorna 0 em caso de falha.  
  
 Para obter mais informações sobre o erro, chame [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360).  
  
### <a name="remarks"></a>Comentários  
 Esse método encapsula a função Windows GDI [GetGraphicsMode](http://msdn.microsoft.com/library/windows/desktop/dd144892).  
  
##  <a name="a-namegethalftonebrusha--cdcgethalftonebrush"></a><a name="gethalftonebrush"></a>CDC::GetHalftoneBrush  
 Chame essa função de membro para recuperar um pincel de meio-tom.  
  
```  
static CBrush* PASCAL GetHalftoneBrush();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CBrush` objeto se bem-sucedido; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Um pincel de meio-tom mostra os pixels alternadamente cores de primeiro plano e plano de fundo para criar um padrão de pontilhado. A seguir está um exemplo de um padrão de pontilhado criado por um pincel de meio-tom.  
  
 ![Detalhes de um traço de caneta pontilhado](../../mfc/reference/media/vc318s1.gif "vc318s1")  
  
##  <a name="a-namegetkerningpairsa--cdcgetkerningpairs"></a><a name="getkerningpairs"></a>CDC::GetKerningPairs  
 Recupera o caractere kerning de pares para a fonte atualmente selecionada no contexto do dispositivo especificado.  
  
```  
int GetKerningPairs(
    int nPairs,  
    LPKERNINGPAIR lpkrnpair) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPairs`  
 Especifica o número de [KERNINGPAIR](http://msdn.microsoft.com/library/windows/desktop/dd145024) estruturas apontada por `lpkrnpair`. A função não copiará de pares de kerning mais que o especificado por `nPairs`.  
  
 `lpkrnpair`  
 Aponta para uma matriz de **KERNINGPAIR** estruturas que recebem o kerning de pares quando a função retorna. Essa matriz deve conter pelo menos tantos estruturas conforme especificado pelo `nPairs`. Se esse parâmetro for **nulo**, a função retorna o número total de kerning de pares da fonte.  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o número de pares recuperados o kerning ou o número total de kerning de pares na fonte, se a função for bem-sucedida. Zero será retornada se a função falhar ou não se houver nenhum par kerning para a fonte.  
  
##  <a name="a-namegetlayouta--cdcgetlayout"></a><a name="getlayout"></a>CDC::GetLayout  
 Chame essa função de membro para determinar o layout de texto e elementos gráficos para um contexto de dispositivo, como uma impressora ou um metarquivo.  
  
```  
DWORD GetLayout() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, o layout sinaliza para o contexto de dispositivo atual. Caso contrário, **GDI_ERROR**. Para obter informações de erro estendidas, chame [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360). Para obter uma lista dos sinalizadores de layout, consulte [CDC::SetLayout](#setlayout).  
  
### <a name="remarks"></a>Comentários  
 O layout padrão é da esquerda para a direita.  
  
##  <a name="a-namegetmapmodea--cdcgetmapmode"></a><a name="getmapmode"></a>CDC::GetMapMode  
 Recupera o modo de mapeamento atual.  
  
```  
int GetMapMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O modo de mapeamento.  
  
### <a name="remarks"></a>Comentários  
 Para obter uma descrição dos modos de mapeamento, consulte o `SetMapMode` função de membro.  
  
> [!NOTE]
>  Se você chamar [SetLayout](#setlayout) para alterar o controlador de domínio para o layout da direita para esquerda, **SetLayout** altera automaticamente o modo de mapeamento para `MM_ISOTROPIC`. Consequentemente, todas as chamadas subsequentes de `GetMapMode` retornará `MM_ISOTROPIC`.  
  
##  <a name="a-namegetmiterlimita--cdcgetmiterlimit"></a><a name="getmiterlimit"></a>CDC::GetMiterLimit  
 Retorna o limite de Malhete para o contexto do dispositivo.  
  
```  
float GetMiterLimit() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O limite de mitre é usado quando desenhar linhas geométricas com esquadria junções.  
  
##  <a name="a-namegetnearestcolora--cdcgetnearestcolor"></a><a name="getnearestcolor"></a>CDC::GetNearestColor  
 Retorna a cor sólida que melhor corresponde a uma cor lógica especificada.  
  
```  
COLORREF GetNearestColor(COLORREF crColor) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `crColor`  
 Especifica a cor a ser correspondido.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de cor RGB (vermelho, verde, azul) que define a sólida de cores mais próximo do `crColor` valor que pode representar o dispositivo.  
  
### <a name="remarks"></a>Comentários  
 O dispositivo especificado deve ser capaz de representar essa cor.  
  
##  <a name="a-namegetoutlinetextmetricsa--cdcgetoutlinetextmetrics"></a><a name="getoutlinetextmetrics"></a>CDC::GetOutlineTextMetrics  
 Recupera informações de métrica de fontes TrueType.  
  
```  
UINT GetOutlineTextMetrics(
    UINT cbData,  
    LPOUTLINETEXTMETRIC lpotm) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpotm`  
 Aponta para uma matriz de [OUTLINETEXTMETRIC](http://msdn.microsoft.com/library/windows/desktop/dd162755) estruturas. Se esse parâmetro for **nulo**, a função retorna o tamanho do buffer necessário para os dados recuperados da métrica.  
  
 `cbData`  
 Especifica o tamanho, em bytes, do buffer para o qual as informações são retornadas.  
  
 `lpotm`  
 Aponta para um **OUTLINETEXTMETRIC** estrutura. Se esse parâmetro for **nulo**, a função retorna o tamanho do buffer necessário para as informações recuperadas de métrica.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O [OUTLINETEXTMETRIC](http://msdn.microsoft.com/library/windows/desktop/dd162755) estrutura contém a maioria das informações de métrica de fonte fornecidas com o formato TrueType, incluindo um [TEXTMETRIC](http://msdn.microsoft.com/library/windows/desktop/dd145132) estrutura. Os últimos quatro membros do **OUTLINETEXTMETRIC** estrutura são ponteiros para cadeias de caracteres. Aplicativos devem alocar espaço para essas cadeias de caracteres além do espaço necessário para os outros membros. Como não há nenhum limite imposto pelo sistema para o tamanho das cadeias de caracteres, o método mais simples para alocar memória é recuperar o tamanho necessário especificando **nulo** para `lpotm` na primeira chamada para o `GetOutlineTextMetrics` função.  
  
##  <a name="a-namegetoutputcharwidtha--cdcgetoutputcharwidth"></a><a name="getoutputcharwidth"></a>CDC::GetOutputCharWidth  
 Usa o contexto de dispositivo de saída, `m_hDC`e recupera as larguras de caracteres individuais em um grupo de caracteres consecutivos de fonte atual.  
  
```  
BOOL GetOutputCharWidth(
    UINT nFirstChar,  
    UINT nLastChar,  
    LPINT lpBuffer) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nFirstChar`  
 Especifica o primeiro caractere em um grupo de caracteres na fonte atual consecutivos.  
  
 `nLastChar`  
 Especifica o último caractere em um grupo de caracteres na fonte atual consecutivos.  
  
 `lpBuffer`  
 Aponta para um buffer que receberá os valores de largura de um grupo de caracteres consecutivos na fonte atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Por exemplo, se `nFirstChar` identifica a letra 'a' e `nLastChar` identifica a letra 'z', o função recupera as larguras de todos os caracteres em minúsculas.  
  
 A função armazena os valores no buffer apontado por `lpBuffer`. Esse buffer deve ser grande o suficiente para conter todas as larguras; ou seja, deve haver pelo menos 26 entradas no exemplo dado.  
  
 Se não existir um caractere no grupo de caracteres consecutivo em uma determinada fonte, ele será atribuído o valor da largura do caractere padrão.  
  
##  <a name="a-namegetoutputtabbedtextextenta--cdcgetoutputtabbedtextextent"></a><a name="getoutputtabbedtextextent"></a>CDC::GetOutputTabbedTextExtent  
 Chame essa função de membro para calcular a largura e altura de uma cadeia de caracteres usando [m_hDC](#m_hdc), o contexto de dispositivo de saída.  
  
```  
CSize GetOutputTabbedTextExtent(
    LPCTSTR lpszString,  
    int nCount,  
    int nTabPositions,  
    LPINT lpnTabStopPositions) const;  
  
CSize GetOutputTabbedTextExtent(
    const CString& str,  
    int nTabPositions,  
    LPINT lpnTabStopPositions) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszString`  
 Aponta para uma cadeia de caracteres a ser medido. Você também pode passar um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto para esse parâmetro.  
  
 `nCount`  
 Especifica o número de caracteres na cadeia de caracteres. Se `nCount` é –&1;, o comprimento será calculado.  
  
 `nTabPositions`  
 Especifica o número de posições de parada de tabulação na matriz apontada por `lpnTabStopPositions`.  
  
 `lpnTabStopPositions`  
 Aponta para uma matriz de inteiros que contém as posições de tabulação em unidades lógicas. As paradas de tabulação devem ser classificadas em ordem; crescente o menor valor de x deve ser o primeiro item na matriz. Tabulações à esquerda não são permitidas.  
  
 `str`  
 Um `CString` objeto que contém os caracteres especificados a ser medido.  
  
### <a name="return-value"></a>Valor de retorno  
 As dimensões da cadeia de caracteres (em unidades lógicas) em um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Se a cadeia de caracteres contém um ou mais caracteres de tabulação, a largura da cadeia de caracteres baseia as paradas de tabulação especificadas por `lpnTabStopPositions`. A função usa a fonte atualmente selecionada para calcular as dimensões da cadeia de caracteres.  
  
 A região de recorte atual não desloca a largura e altura retornado pelo `GetOutputTabbedTextExtent` função.  
  
 Uma vez que alguns dispositivos não colocar caracteres em matrizes de célula normal (ou seja, eles kerning de caracteres), a soma das extensões dos caracteres em uma cadeia de caracteres não pode ser igual a extensão da cadeia de caracteres.  
  
 Se `nTabPositions` é 0 e `lpnTabStopPositions` é **nulo**, guias são expandidas para oito larguras de caracteres médio. Se `nTabPositions` for 1, as paradas de tabulação serão separadas pela distância especificada pelo valor do primeiro na matriz para o qual `lpnTabStopPositions` pontos. Se `lpnTabStopPositions` aponta para mais de um único valor, uma parada de tabulação é definida para cada valor na matriz, até o número especificado por `nTabPositions`.  
  
##  <a name="a-namegetoutputtextextenta--cdcgetoutputtextextent"></a><a name="getoutputtextextent"></a>CDC::GetOutputTextExtent  
 Chame essa função de membro para usar o contexto de dispositivo de saída, [m_hDC](#m_hdc)e a largura e altura de uma linha de texto, usando a fonte atual de computação.  
  
```  
CSize GetOutputTextExtent(
    LPCTSTR lpszString,  
    int nCount) const;  
  
CSize GetOutputTextExtent(const CString& str) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszString`  
 Aponta para uma cadeia de caracteres. Você também pode passar um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto para esse parâmetro.  
  
 `nCount`  
 Especifica o número de caracteres na cadeia de caracteres. Se `nCount` é –&1;, o comprimento será calculado.  
  
 `str`  
 Um `CString` objeto que contém os caracteres especificados a ser medido.  
  
### <a name="return-value"></a>Valor de retorno  
 As dimensões da cadeia de caracteres (em unidades lógicas) retornadas em uma [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 A região de recorte atual não afeta a largura e altura retornado por `GetOutputTextExtent`.  
  
 Uma vez que alguns dispositivos não colocar caracteres em matrizes de célula normal (ou seja, eles realizarem kerning), a soma das extensões dos caracteres em uma cadeia de caracteres não pode ser igual a extensão da cadeia de caracteres.  
  
##  <a name="a-namegetoutputtextmetricsa--cdcgetoutputtextmetrics"></a><a name="getoutputtextmetrics"></a>CDC::GetOutputTextMetrics  
 Recupera as métricas para a fonte atual usando `m_hDC`, o contexto de dispositivo de saída.  
  
```  
BOOL GetOutputTextMetrics(LPTEXTMETRIC lpMetrics) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpMetrics`  
 Aponta para a [TEXTMETRIC](http://msdn.microsoft.com/library/windows/desktop/dd145132) estrutura que recebe as métricas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
##  <a name="a-namegetpatha--cdcgetpath"></a><a name="getpath"></a>CDC::GetPath  
 Recupera as coordenadas definindo os pontos de extremidade de linhas e pontos de controle de curvas encontrados no caminho selecionado no contexto de dispositivo.  
  
```  
int GetPath(
    LPPOINT lpPoints,  
    LPBYTE lpTypes,  
    int nCount) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPoints`  
 Aponta para uma matriz de [ponto](../../mfc/reference/point-structure1.md) estruturas de dados ou `CPoint` objetos onde os pontos de extremidade da linha e a curva de pontos de controle são colocados.  
  
 `lpTypes`  
 Aponta para uma matriz de bytes em que os tipos de vértice são colocados. Os valores são um dos seguintes:  
  
- **PT_MOVETO** Especifica que o correspondente point-in `lpPoints` inicia uma figura de separação.  
  
- **PT_LINETO** Especifica que ponto o ponto anterior e correspondente no `lpPoints` são os pontos de extremidade de uma linha.  
  
- **PT_BEZIERTO** Especifica que o correspondente point-in `lpPoints` é um ponto final de uma curva Bzier ou ponto de controle.  
  
 **PT_BEZIERTO** tipos sempre ocorrem em conjuntos de três. O ponto no caminho imediatamente, precedendo-as define o ponto de partida para a curva Bzier. Os dois primeiros **PT_BEZIERTO** pontos são os pontos de controle e a terceira **PT_BEZIERTO** ponto é o ponto final (se embutidos).  
  
     A **PT_LINETO** ou **PT_BEZIERTO** tipo pode ser combinado com o seguinte sinalizador (usando o operador bit a bit `OR`) para indicar que o ponto correspondente é o último ponto em uma figura e que a figura deve ser fechada:  
  
- **PT_CLOSEFIGURE** Especifica que a figura é fechada automaticamente após a linha correspondente ou curva é desenhada. A figura é fechada por desenhar uma linha do ponto de extremidade linha ou curva até o ponto correspondente ao último **PT_MOVETO**.  
  
 `nCount`  
 Especifica o número total de [ponto](../../mfc/reference/point-structure1.md) estruturas de dados que podem ser colocadas na `lpPoints` matriz. Esse valor deve ser igual ao número de bytes que pode ser colocado na `lpTypes` matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o `nCount` parâmetro é diferente de zero, o número de pontos enumerados. Se `nCount` é 0, o número total de pontos no caminho (e `GetPath` os buffers não grava nada). Se `nCount` for diferente de zero e for menor que o número de pontos no caminho, o valor de retorno é -1.  
  
### <a name="remarks"></a>Comentários  
 O contexto do dispositivo deve conter um caminho fechado. Os pontos do caminho são retornados em coordenadas lógicas. Pontos são armazenados no caminho nas coordenadas do dispositivo, então `GetPath` altera os pontos de coordenadas do dispositivo para coordenadas lógicas usando o inverso da transformação atual. O `FlattenPath` função de membro pode ser chamada antes de `GetPath`, converter todas as curvas no caminho em segmentos de linha.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CDC:: beginpath](#beginpath).  
  
##  <a name="a-namegetpixela--cdcgetpixel"></a><a name="getpixel"></a>CDC::GetPixel  
 Recupera o valor de cor RGB do pixel no ponto especificado por *x* e *y*.  
  
```  
COLORREF GetPixel(
    int x,  
    int y) const;  
  
COLORREF GetPixel(POINT point) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica do ponto a ser examinado.  
  
 *y*  
 Especifica a coordenada y lógica do ponto a ser examinado.  
  
 `point`  
 Especifica a lógica coordenadas x e y-do ponto a ser examinado.  
  
### <a name="return-value"></a>Valor de retorno  
 Versão da função, um valor de cor RGB da cor de ponto específico. É -1 se as coordenadas não especificar um ponto na região de recorte.  
  
### <a name="remarks"></a>Comentários  
 O ponto deve estar na região de recorte. Se o ponto não está na região de recorte, a função não tem nenhum efeito e retorna –&1;.  
  
 Nem todos os dispositivos oferecem suporte a **GetPixel** função. Para obter mais informações, consulte o **RC_BITBLT** capacidade de varredura sob o [GetDeviceCaps](#getdevicecaps) função de membro.  
  
 O **GetPixel** função de membro tem duas formas. O primeiro usa dois valores de coordenada; o segundo usa um [ponto](../../mfc/reference/point-structure1.md) estrutura ou um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto.  
  
##  <a name="a-namegetpolyfillmodea--cdcgetpolyfillmode"></a><a name="getpolyfillmode"></a>CDC::GetPolyFillMode  
 Recupera o modo de preenchimento de polígono atual.  
  
```  
int GetPolyFillMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O modo atual de polígono preenchido, **alternativo** ou **ENROLAMENTO**, se a função for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 Consulte o `SetPolyFillMode` a função de membro para obter uma descrição dos modos de preenchimento de polígono.  
  
##  <a name="a-namegetrop2a--cdcgetrop2"></a><a name="getrop2"></a>CDC::GetROP2  
 Recupera o modo de desenho atual.  
  
```  
int GetROP2() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O modo de desenho. Para obter uma lista dos valores de modo de desenho, consulte o `SetROP2` função de membro.  
  
### <a name="remarks"></a>Comentários  
 O modo de desenho Especifica como as cores da caneta e o interior do objetos preenchidos são combinados com a cor já na superfície de exibição.  
  
##  <a name="a-namegetsafehdca--cdcgetsafehdc"></a><a name="getsafehdc"></a>CDC::GetSafeHdc  
 Chame essa função de membro para obter [m_hDC](#m_hdc), o contexto de dispositivo de saída.  
  
```  
HDC GetSafeHdc() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador de contexto de dispositivo.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro também funciona com ponteiros nulos.  
  
##  <a name="a-namegetstretchbltmodea--cdcgetstretchbltmode"></a><a name="getstretchbltmode"></a>CDC::GetStretchBltMode  
 Recupera o modo atual alongando bitmap.  
  
```  
int GetStretchBltMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno Especifica o modo de alongamento de bitmap atual — **STRETCH_ANDSCANS**, **STRETCH_DELETESCANS**, ou **STRETCH_ORSCANS** — se a função for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O modo de alongamento bitmap define como as informações são removidas do bitmaps alongada ou compactados com o `StretchBlt` função de membro.  
  
 O **STRETCH_ANDSCANS** e **STRETCH_ORSCANS** modos normalmente são usados para preservar os pixels do primeiro plano em bitmaps monocromático. O **STRETCH_DELETESCANS** modo é normalmente usado para preservar a cor em bitmaps de cor.  
  
##  <a name="a-namegettabbedtextextenta--cdcgettabbedtextextent"></a><a name="gettabbedtextextent"></a>CDC::GetTabbedTextExtent  
 Chame essa função de membro para calcular a largura e altura de uma cadeia de caracteres usando [m_hAttribDC](#m_hattribdc), o contexto de dispositivo do atributo.  
  
```  
CSize GetTabbedTextExtent(
    LPCTSTR lpszString,  
    int nCount,  
    int nTabPositions,  
    LPINT lpnTabStopPositions) const;  
  
CSize GetTabbedTextExtent(
    const CString& str,  
    int nTabPositions,  
    LPINT lpnTabStopPositions) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszString`  
 Aponta para uma cadeia de caracteres. Você também pode passar um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto para esse parâmetro.  
  
 `nCount`  
 Especifica o número de caracteres na cadeia de caracteres. Se `nCount` é –&1;, o comprimento será calculado.  
  
 `nTabPositions`  
 Especifica o número de posições de parada de tabulação na matriz apontada por `lpnTabStopPositions`.  
  
 `lpnTabStopPositions`  
 Aponta para uma matriz de inteiros que contém as posições de tabulação em unidades lógicas. As paradas de tabulação devem ser classificadas em ordem; crescente o menor valor de x deve ser o primeiro item na matriz. Tabulações à esquerda não são permitidas.  
  
 `str`  
 Um `CString` objeto que contém os caracteres especificados a ser desenhada.  
  
### <a name="return-value"></a>Valor de retorno  
 As dimensões da cadeia de caracteres (em unidades lógicas) em um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Se a cadeia de caracteres contém um ou mais caracteres de tabulação, a largura da cadeia de caracteres baseia as paradas de tabulação especificadas por `lpnTabStopPositions`. A função usa a fonte atualmente selecionada para calcular as dimensões da cadeia de caracteres.  
  
 A região de recorte atual não desloca a largura e altura retornado pelo `GetTabbedTextExtent` função.  
  
 Uma vez que alguns dispositivos não colocar caracteres em matrizes de célula normal (ou seja, eles kerning de caracteres), a soma das extensões dos caracteres em uma cadeia de caracteres não pode ser igual a extensão da cadeia de caracteres.  
  
 Se `nTabPositions` é 0 e `lpnTabStopPositions` é **nulo**, guias são expandidas para oito vezes a largura de caractere médio. Se `nTabPositions` for 1, as paradas de tabulação serão separadas pela distância especificada pelo valor do primeiro na matriz para o qual `lpnTabStopPositions` pontos. Se `lpnTabStopPositions` aponta para mais de um único valor, uma parada de tabulação é definida para cada valor na matriz, até o número especificado por `nTabPositions`.  
  
##  <a name="a-namegettextaligna--cdcgettextalign"></a><a name="gettextalign"></a>CDC::GetTextAlign  
 Recupera o status dos sinalizadores de alinhamento de texto para o contexto de dispositivo.  
  
```  
UINT GetTextAlign() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O status dos sinalizadores de alinhamento de texto. O valor de retorno é um ou mais dos seguintes valores:  
  
- **TA_BASELINE** Especifica o alinhamento do eixo x e a linha de base da fonte escolhida dentro do retângulo delimitador.  
  
- **TA_BOTTOM** Especifica o alinhamento do eixo x e a parte inferior do retângulo delimitador.  
  
- **TA_CENTER** Especifica o alinhamento do eixo y e o centro do retângulo delimitador.  
  
- **TA_LEFT** Especifica o alinhamento do eixo y e o lado esquerdo do retângulo delimitador.  
  
- **TA_NOUPDATECP** Especifica que a posição atual não é atualizada.  
  
- **TA_RIGHT** Especifica o alinhamento do eixo y e à direita do retângulo delimitador.  
  
- **TA_TOP** Especifica o alinhamento do eixo x e a parte superior do retângulo delimitador.  
  
- **TA_UPDATECP** Especifica que a posição atual é atualizada.  
  
### <a name="remarks"></a>Comentários  
 Determinam os sinalizadores de alinhamento de texto como o `TextOut` e `ExtTextOut` funções de membro alinham uma cadeia de caracteres de texto em relação ao ponto de partida da cadeia de caracteres. Os sinalizadores de alinhamento de texto não são sinalizadores de bit único necessariamente e podem ser iguais a 0. Para testar se um sinalizador estiver definido, um aplicativo deve seguir estas etapas:  
  
1.  Aplica o operador OR bit a bit para o sinalizador e seus sinalizadores relacionados, agrupados da seguinte maneira:  
  
    - **TA_LEFT**, **TA_CENTER**, e **TA_RIGHT**  
  
    - **TA_BASELINE**, **TA_BOTTOM**, e **TA_TOP**  
  
    - **TA_NOUPDATECP** e **TA_UPDATECP**  
  
2.  Aplicar o bit a bit- e operador para o resultado e o valor de retorno `GetTextAlign`.  
  
3.  Testar a igualdade esse resultado e o sinalizador.  
  
##  <a name="a-namegettextcharacterextraa--cdcgettextcharacterextra"></a><a name="gettextcharacterextra"></a>CDC::GetTextCharacterExtra  
 Recupera a configuração atual para a quantidade de espaçamento intercharacter.  
  
```  
int GetTextCharacterExtra() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A quantidade de espaço intercharacter.  
  
### <a name="remarks"></a>Comentários  
 GDI adiciona esse espaçamento para cada caractere, incluindo caracteres de quebra, quando ele grava uma linha de texto para o contexto do dispositivo.  
  
 O valor padrão para a quantidade de espaçamento intercharacter é 0.  
  
##  <a name="a-namegettextcolora--cdcgettextcolor"></a><a name="gettextcolor"></a>CDC::GetTextColor  
 Recupera a cor do texto.  
  
```  
COLORREF GetTextColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cor do texto como um valor de cor RGB.  
  
### <a name="remarks"></a>Comentários  
 A cor do texto é a cor de primeiro plano dos caracteres desenhada usando as funções de membro de saída de texto GDI [TextOut](#textout), [ExtTextOut](#exttextout), e [TabbedTextOut](#tabbedtextout).  
  
##  <a name="a-namegettextextenta--cdcgettextextent"></a><a name="gettextextent"></a>CDC::getTextExtent  
 Chame essa função de membro para calcular a largura e altura de uma linha de texto usando a fonte atual para determinar as dimensões.  
  
```  
CSize GetTextExtent(
    LPCTSTR lpszString,  
    int nCount) const;  
  
CSize GetTextExtent(const CString& str) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszString`  
 Aponta para uma cadeia de caracteres. Você também pode passar um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto para esse parâmetro.  
  
 `nCount`  
 Especifica o número de caracteres na cadeia de caracteres.  
  
 `str`  
 Um `CString` objeto que contém os caracteres especificados.  
  
### <a name="return-value"></a>Valor de retorno  
 As dimensões da cadeia de caracteres (em unidades lógicas) em um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 As informações são recuperadas do [m_hAttribDC](#m_hattribdc), o contexto de dispositivo do atributo.  
  
 Por padrão, `GetTextExtent` pressupõe que o texto para que ele recupera a dimensão é definido por uma linha horizontal (ou seja, o escape é 0). Se você criar uma fonte especificando um escape diferente de zero, você deve converter o ângulo do texto explicitamente para obter as dimensões da cadeia de caracteres.  
  
 A região de recorte atual não afeta a largura e altura retornado por `GetTextExtent`.  
  
 Uma vez que alguns dispositivos não colocar caracteres em matrizes de célula normal (ou seja, eles realizarem kerning), a soma das extensões dos caracteres em uma cadeia de caracteres não pode ser igual a extensão da cadeia de caracteres.  
  
##  <a name="a-namegettextextentexpointia--cdcgettextextentexpointi"></a><a name="gettextextentexpointi"></a>CDC::GetTextExtentExPointI  
 Recupera o número de caracteres em uma cadeia de caracteres especificada que caiba dentro de um espaço especificado e preenche uma matriz com a extensão do texto para cada um desses caracteres.  
  
```  
BOOL GetTextExtentExPointI(
    LPWORD pgiIn,  
    int cgi,  
    int nMaxExtent,  
    LPINT lpnFit,  
    LPINT alpDx,  
    LPSIZE lpSize) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pgiIn`  
 Um ponteiro para uma matriz de índices de glifo para o qual as extensões devem ser recuperados.  
  
 `cgi`  
 Especifica o número de glifos na matriz apontada por `pgiIn`.  
  
 `nMaxExtent`  
 Especifica a largura máxima permitida, em unidades lógicas, de cadeia de caracteres formatada.  
  
 `lpnFit`  
 Um ponteiro para um inteiro que recebe uma contagem do número máximo de caracteres que caberá no espaço especificado por `nMaxExtent`. Quando `lpnFit` é **nulo**, `nMaxExtent` será ignorado.  
  
 *alpDx*  
 Um ponteiro para uma matriz de inteiros que recebe as extensões de glifo parcial. Cada elemento na matriz retorna a distância em unidades lógicas, entre o início da matriz de índices de glifo e um dos glifos que caiba no espaço especificado por `nMaxExtent`. Embora essa matriz deve ter pelo menos o mesmo número de elementos como índices de glifo especificados pela `cgi`, a função preenche a matriz com extensões apenas para tantos índices de glifo conforme especificado por `lpnFit`. Se *lpnDx* é **nulo**, a função não calcular larguras de cadeia de caracteres parcial.  
  
 `lpSize`  
 Ponteiro para uma [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura que recebe as dimensões da matriz de índices de glifo, em unidades lógicas. Esse valor não pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade da função [GetTextExtentExPointI](http://msdn.microsoft.com/library/windows/desktop/dd144936), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegettextextentpointia--cdcgettextextentpointi"></a><a name="gettextextentpointi"></a>CDC::GetTextExtentPointI  
 Recupera a largura e altura da matriz especificada de índices de glifo.  
  
```  
BOOL GetTextExtentPointI(
    LPWORD pgiIn,  
    int cgi,  
    LPSIZE lpSize) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pgiIn`  
 Um ponteiro para uma matriz de índices de glifo para o qual as extensões devem ser recuperados.  
  
 `cgi`  
 Especifica o número de glifos na matriz apontada por `pgiIn`.  
  
 `lpSize`  
 Ponteiro para uma [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura que recebe as dimensões da matriz de índices de glifo, em unidades lógicas. Esse valor não pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade da função [GetTextExtentPointI](http://msdn.microsoft.com/library/windows/desktop/dd144939), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegettextfacea--cdcgettextface"></a><a name="gettextface"></a>CDC::GetTextFace  
 Chame essa função de membro para copiar o nome de face da fonte atual em um buffer.  
  
```  
int GetTextFace(
    int nCount,  
    LPTSTR lpszFacename) const;  
  
int GetTextFace(CString& rString) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nCount`  
 Especifica o tamanho do buffer (em bytes). Se o nome de face de tipos é maior que o número de bytes especificado por esse parâmetro, o nome será truncado.  
  
 *lpszFacename*  
 Aponta para o buffer para o nome de face de tipos.  
  
 `rString`  
 Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de bytes copiados para o buffer, não incluindo o caractere de terminação nula. Ele é 0 se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 O nome de face de tipos é copiado como uma cadeia de caracteres terminada em nulo.  
  
##  <a name="a-namegettextmetricsa--cdcgettextmetrics"></a><a name="gettextmetrics"></a>CDC::GetTextMetrics  
 Recupera as métricas para a fonte atual usando o contexto de dispositivo do atributo.  
  
```  
BOOL GetTextMetrics(LPTEXTMETRIC lpMetrics) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpMetrics`  
 Aponta para a [TEXTMETRIC](http://msdn.microsoft.com/library/windows/desktop/dd145132) estrutura que recebe as métricas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
##  <a name="a-namegetviewportexta--cdcgetviewportext"></a><a name="getviewportext"></a>CDC::GetViewportExt  
 Recupera as extensões x e y do visor do contexto do dispositivo.  
  
```  
CSize GetViewportExt() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A x - e y-extensões (em unidades de dispositivo) como um `CSize` objeto.  
  
##  <a name="a-namegetviewportorga--cdcgetviewportorg"></a><a name="getviewportorg"></a>CDC::GetViewportOrg  
 Recupera as coordenadas x e y da origem do visor associado ao contexto de dispositivo.  
  
```  
CPoint GetViewportOrg() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A origem do visor (nas coordenadas do dispositivo) como um `CPoint` objeto.  
  
##  <a name="a-namegetwindowa--cdcgetwindow"></a><a name="getwindow"></a>CDC::GetWindow  
 Retorna a janela associada com o contexto de dispositivo de exibição.  
  
```  
CWnd* GetWindow() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma `CWnd` objeto se bem-sucedido; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Essa é uma função avançada. Por exemplo, essa função de membro não pode retornar a janela de exibição durante a impressão ou na visualização de impressão. Ele sempre retorna a janela associada a saída. Funções de saída que usam determinado DC desenhar nessa janela.  
  
##  <a name="a-namegetwindowexta--cdcgetwindowext"></a><a name="getwindowext"></a>CDC::GetWindowExt  
 Recupera as extensões x e y da janela associada ao contexto de dispositivo.  
  
```  
CSize GetWindowExt() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A x - e y-extensões (em unidades lógicas) como um `CSize` objeto.  
  
##  <a name="a-namegetwindoworga--cdcgetwindoworg"></a><a name="getwindoworg"></a>CDC::GetWindowOrg  
 Recupera as coordenadas x e y da origem da janela associada ao contexto de dispositivo.  
  
```  
CPoint GetWindowOrg() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A origem da janela (em coordenadas lógicas) como um `CPoint` objeto.  
  
##  <a name="a-namegetworldtransforma--cdcgetworldtransform"></a><a name="getworldtransform"></a>CDC::GetWorldTransform  
 Recupera o espaço do mundo atual para transformação de espaço da página.  
  
```  
BOOL GetWorldTransform(XFORM& rXform) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `rXform`  
 Referência a um [XFORM](http://msdn.microsoft.com/library/windows/desktop/dd145228) estrutura que recebe o espaço do mundo atual para transformação de espaço da página.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor diferente de zero em caso de sucesso.  
  
 Retorna 0 em caso de falha.  
  
 Para obter mais informações sobre o erro, chame [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360).  
  
### <a name="remarks"></a>Comentários  
 Esse método encapsula a função Windows GDI [GetWorldTransform](http://msdn.microsoft.com/library/windows/desktop/dd144953).  
  
##  <a name="a-namegradientfilla--cdcgradientfill"></a><a name="gradientfill"></a>CDC::GradientFill  
 Chame essa função de membro para preencher as estruturas de triângulo retângulo com cor desaparece sem problemas de um lado para outro.  
  
```  
BOOL GradientFill(
    TRIVERTEX* pVertices,  
    ULONG nVertices,  
    void* pMesh,  
    ULONG nMeshElements,  
    DWORD dwMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pVertices*  
 Ponteiro para uma matriz de [TRIVERTEX](http://msdn.microsoft.com/library/windows/desktop/dd145142) estruturas que definem um vértice de triângulo.  
  
 *nVertices*  
 O número de vértices.  
  
 `pMesh`  
 Matriz de [GRADIENT_TRIANGLE](http://msdn.microsoft.com/library/windows/desktop/dd144959) no modo de triângulo ou uma matriz de estruturas de [GRADIENT_RECT](http://msdn.microsoft.com/library/windows/desktop/dd144958) estruturas no modo do retângulo.  
  
 *nMeshElements*  
 O número de elementos (triângulos ou retângulos) em `pMesh`.  
  
 `dwMode`  
 Especifica o modo de preenchimento de gradiente. Para obter uma lista dos valores possíveis, consulte [GradientFill](http://msdn.microsoft.com/library/windows/desktop/dd144957) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se bem-sucedido; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte `GradientFill` no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegraystringa--cdcgraystring"></a><a name="graystring"></a>CDC:: graystring  
 Desenha esmaecida texto (cinza) no local especificado por gravar o texto em um bitmap de memória, o bitmap de esmaecimento e, em seguida, copiando o bitmap para a exibição.  
  
```  
virtual BOOL GrayString(
    CBrush* pBrush,  
    BOOL (CALLBACK* lpfnOutput)(
    HDC,
    LPARAM,
    int),  
    LPARAM lpData,  
    int nCount,  
    int x,  
    int y,  
    int nWidth,  
    int nHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pBrush`  
 Identifica o pincel a ser usado para o esmaecimento (esmaecer).  
  
 `lpfnOutput`  
 Especifica o endereço do procedimento instância da função de retorno de chamada fornecido pelo aplicativo que desenhará a cadeia de caracteres. Para obter mais informações, consulte a descrição do Windows **OutputFunc** [função de retorno de chamada](../../mfc/reference/callback-function-for-cdc-graystring.md). Se esse parâmetro for **nulo**, o sistema usa o Windows `TextOut` função para desenhar a cadeia de caracteres, e `lpData` é considerado como um ponteiro longo para a cadeia de caracteres de saída.  
  
 `lpData`  
 Especifica um ponteiro longe para dados a serem passados para a função de saída. Se `lpfnOutput` é **nulo**, `lpData` deve ser um ponteiro longo para a cadeia de caracteres de saída.  
  
 `nCount`  
 Especifica o número de caracteres de saída. Se esse parâmetro for 0, `GrayString` calcula o comprimento da cadeia de caracteres (supondo que `lpData` é um ponteiro para a cadeia de caracteres). Se `nCount` é 1 e a função apontada por `lpfnOutput` retorna 0, a imagem é mostrado, mas não fica esmaecida.  
  
 *x*  
 Especifica a coordenada x lógica da posição inicial do retângulo que inclui a cadeia de caracteres.  
  
 *y*  
 Especifica a coordenada y lógica da posição inicial do retângulo que inclui a cadeia de caracteres.  
  
 `nWidth`  
 Especifica a largura (em unidades lógicas) do retângulo que inclui a cadeia de caracteres. Se `nWidth` é 0, `GrayString` calcula a largura da área, supondo que `lpData` é um ponteiro para a cadeia de caracteres.  
  
 `nHeight`  
 Especifica a altura (em unidades lógicas) do retângulo que inclui a cadeia de caracteres. Se `nHeight` é 0, `GrayString` calcula a altura da área, supondo que `lpData` é um ponteiro para a cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a cadeia de caracteres é desenhada, ou 0 se o `TextOut` função ou a função fornecida pelo aplicativo de saída retornado 0, ou se houver memória suficiente para criar um bitmap de memória de esmaecimento.  
  
### <a name="remarks"></a>Comentários  
 A função esmaece o texto, independentemente do pincel selecionado e o plano de fundo. O `GrayString` função de membro usa a fonte atualmente selecionada. O `MM_TEXT` modo de mapeamento deve ser selecionado antes de usar essa função.  
  
 Um aplicativo pode desenhar esmaecidas cadeias de caracteres (esmaecidas) em dispositivos que oferecem suporte a uma cor cinza sólida sem chamar o `GrayString` função de membro. A cor do sistema **COLOR_GRAYTEXT** é a cor cinza sólida sistema usada para desenhar texto desabilitado. O aplicativo pode chamar o **GetSysColor** função do Windows para recuperar o valor de cor **COLOR_GRAYTEXT**. Se a cor é diferente de 0 (preto), o aplicativo pode chamar o `SetTextColor` a função de membro para definir a cor do texto como o valor de cor e desenhe a cadeia de caracteres diretamente. Se a cor recuperada é preta, o aplicativo deve chamar `GrayString` esmaecer (cinza) o texto.  
  
 Se `lpfnOutput` é **nulo**, GDI usa o Windows [TextOut](http://msdn.microsoft.com/library/windows/desktop/dd145133) função, e `lpData` é considerado como um ponteiro longe para o caractere como saída. Se os caracteres de saída não podem ser tratados pelo `TextOut` função de membro (por exemplo, a cadeia de caracteres é armazenada como um bitmap), o aplicativo deve fornecer sua própria função de saída.  
  
 Observe também que todas as funções de retorno de chamada devem interceptar exceções Microsoft Foundation antes de retornar ao Windows, como exceções não podem ser geradas em limites de retorno de chamada. Para obter mais informações sobre exceções, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
 A função de retorno de chamada passada para `GrayString` deve usar o `__stdcall` convenção de chamada e deve ser exportado com `__declspec`.  
  
 Quando a estrutura estiver no modo de visualização, uma chamada para o `GrayString` função de membro é convertida para um `TextOut` chamada e a função de retorno de chamada não é chamado.  
  
##  <a name="a-namehimetrictodpa--cdchimetrictodp"></a><a name="himetrictodp"></a>CDC::HIMETRICtoDP  
 Use esta função ao converter **HIMETRIC** tamanhos de OLE em pixels.  
  
```  
void HIMETRICtoDP(LPSIZE lpSize) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpSize`  
 Aponta para um [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Se o modo de mapeamento de objeto de contexto de dispositivo for `MM_LOENGLISH`, `MM_HIENGLISH`, `MM_LOMETRIC` ou `MM_HIMETRIC`, em seguida, a conversão é baseada no número de pixels física polegada. Se o modo de mapeamento é um dos outros modos não limitado (por exemplo, `MM_TEXT`), em seguida, a conversão é baseada no número de pixels de polegada lógica.  
  
##  <a name="a-namehimetrictolpa--cdchimetrictolp"></a><a name="himetrictolp"></a>CDC::HIMETRICtoLP  
 Chame essa função para converter **HIMETRIC** unidades em unidades lógicas.  
  
```  
void HIMETRICtoLP(LPSIZE lpSize) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpSize`  
 Aponta para um [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Use esta função ao obter **HIMETRIC** tamanhos de OLE e deseja convertê-los para o modo de mapeamento natural do seu aplicativo.  
  
 A conversão é realizada, convertendo primeiro o **HIMETRIC** unidades em pixels e, em seguida, converter essas unidades em unidades lógicas usando unidades de mapeamento atuais do contexto do dispositivo. Observe que as extensões da janela do dispositivo e o visor afetará o resultado.  
  
##  <a name="a-nameintersectcliprecta--cdcintersectcliprect"></a><a name="intersectcliprect"></a>CDC::IntersectClipRect  
 Cria uma nova região de recorte formando a interseção de região atual e o retângulo especificado por `x1`, `y1`, `x2`, e `y2`.  
  
```  
int IntersectClipRect(
    int x1,  
    int y1,  
    int x2,  
    int y2);  
  
int IntersectClipRect(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `x1`  
 Especifica a coordenada x lógica do canto superior esquerdo do retângulo.  
  
 `y1`  
 Especifica a coordenada y lógica do canto superior esquerdo do retângulo.  
  
 `x2`  
 Especifica a coordenada x lógica do canto inferior direito do retângulo.  
  
 `y2`  
 Especifica a coordenada y lógica do canto inferior direito do retângulo.  
  
 `lpRect`  
 Especifica o retângulo. Você pode passar a uma `CRect` objeto ou um ponteiro para um `RECT` estrutura para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Tipo da nova região de recorte. Ele pode ser qualquer um dos seguintes valores:  
  
- **COMPLEXREGION** nova região de recorte tiver bordas de sobreposição.  
  
- **Erro** o contexto de dispositivo não é válido.  
  
- **NULLREGION** nova região de recorte está vazio.  
  
- **SIMPLEREGION** nova região de recorte tem sem bordas sobrepostas.  
  
### <a name="remarks"></a>Comentários  
 GDI Recorta todas as saídas subsequentes para caber no novo limite. A largura e altura não devem exceder 32.767.  
  
##  <a name="a-nameinvertrecta--cdcinvertrect"></a><a name="invertrect"></a>CDC::InvertRect  
 Inverte o conteúdo do retângulo determinado.  
  
```  
void InvertRect(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para um `RECT` que contém as coordenadas lógicas do retângulo deve ser invertida. Você também pode passar um `CRect` objeto para esse parâmetro.  
  
### <a name="remarks"></a>Comentários  
 Inversão é uma operação lógica não operação e inverte os bits de cada pixel. Em monitores monocromáticos, a função faz pixels brancos de preto e preto branco. Em cor seja exibida, a inversão depende de como as cores são geradas para a exibição. Chamando `InvertRect` duas vezes com o mesmo retângulo restaura a exibição para suas cores anteriores.  
  
 Se o retângulo está vazio, nada é desenhado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#36;](../../mfc/codesnippet/cpp/cdc-class_8.cpp)]  
  
##  <a name="a-nameinvertrgna--cdcinvertrgn"></a><a name="invertrgn"></a>CDC::InvertRgn  
 Inverte as cores na região especificada pelo `pRgn`.  
  
```  
BOOL InvertRgn(CRgn* pRgn);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRgn`  
 Identifica a região deve ser invertida. As coordenadas para a região são especificadas em unidades lógicas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Em monitores monocromáticos, a função faz pixels brancos de preto e preto branco. Em cor seja exibida, a inversão depende de como as cores são geradas para a exibição.  
  
##  <a name="a-nameisprintinga--cdcisprinting"></a><a name="isprinting"></a>CDC::IsPrinting  
 Determina se o contexto do dispositivo está sendo usado para impressão.  
  
```  
BOOL IsPrinting() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o `CDC` objeto for um controlador de domínio; caso contrário, 0.  
  
##  <a name="a-namelinetoa--cdclineto"></a><a name="lineto"></a>CDC::lineTo  
 Desenha uma linha da posição atual até, mas não incluindo, o ponto especificado por *x* e *y* (ou `point`).  
  
```  
BOOL LineTo(
    int x,  
    int y);  
  
BOOL LineTo(POINT point);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica do ponto de extremidade para a linha.  
  
 *y*  
 Especifica a coordenada y lógica do ponto de extremidade da linha.  
  
 `point`  
 Especifica o ponto de extremidade da linha. Você pode passar a uma **ponto** estrutura ou um `CPoint` objeto para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a linha é desenhada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A linha é desenhada com a caneta selecionada. A posição atual está definida como *x*, *y* ou `point`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRect::CenterPoint](../../atl-mfc-shared/reference/crect-class.md#centerpoint).  
  
##  <a name="a-namelptodpa--cdclptodp"></a><a name="lptodp"></a>CDC::LPtoDP  
 Converte unidades lógicas em unidades de dispositivo.  
  
```  
void LPtoDP(
    LPPOINT lpPoints,  
    int nCount = 1) const;  
  
void LPtoDP(LPRECT lpRect) const;
void LPtoDP(LPSIZE lpSize) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPoints`  
 Aponta para uma matriz de pontos. Cada ponto na matriz é um [ponto](../../mfc/reference/point-structure1.md) estrutura ou um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto.  
  
 `nCount`  
 O número de pontos da matriz.  
  
 `lpRect`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto. Esse parâmetro é usado para o caso comum de mapeamento de um retângulo da lógica para unidades do dispositivo.  
  
 `lpSize`  
 Aponta para um [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura ou um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 A função mapeia as coordenadas de cada ponto ou dimensões de tamanho, do sistema de coordenadas lógico da GDI em um sistema de coordenadas do dispositivo. A conversão depende do modo de mapeamento atual e as configurações das origens e extensões de janela e o visor do dispositivo.  
  
 As coordenadas x e y dos pontos são inteiros com sinal de 2 bytes no intervalo de – 32.768 a 32.767. Em casos onde o modo de mapeamento resultar em valores maiores do que esses limites, o sistema define os valores – 32.768 e 32.767, respectivamente.  
  
##  <a name="a-namelptohimetrica--cdclptohimetric"></a><a name="lptohimetric"></a>CDC::LPtoHIMETRIC  
 Chame essa função para converter as unidades lógicas em **HIMETRIC** unidades.  
  
```  
void LPtoHIMETRIC(LPSIZE lpSize) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpSize`  
 Aponta para um **tamanho** estrutura ou um `CSize` objeto.  
  
### <a name="remarks"></a>Comentários  
 Use esta função ao fornecer **HIMETRIC** tamanhos para OLE, convertendo do modo de mapeamento natural do seu aplicativo. Observe que as extensões da janela do dispositivo e o visor afetará o resultado.  
  
 A conversão é realizada pelo primeiro converter as unidades lógicas em pixels usando unidades de mapeamento atuais do contexto de dispositivo e, em seguida, converter essas unidades em **HIMETRIC** unidades.  
  
##  <a name="a-namemhattribdca--cdcmhattribdc"></a><a name="m_hattribdc"></a>CDC::m_hAttribDC  
 O contexto de dispositivo para este atributo `CDC` objeto.  
  
```  
HDC m_hAttribDC;  
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, este contexto de dispositivo é igual a `m_hDC`. Em geral, `CDC` chamadas GDI que solicitam informações do contexto do dispositivo são direcionadas para `m_hAttribDC`. Consulte o [CDC](../../mfc/reference/cdc-class.md) classe descrição para saber mais sobre o uso desses contextos de dois dispositivo.  
  
##  <a name="a-namemhdca--cdcmhdc"></a><a name="m_hdc"></a>CDC::m_hDC  
 O contexto de dispositivo de saída para este `CDC` objeto.  
  
```  
HDC m_hDC;  
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, `m_hDC` é igual a `m_hAttribDC`, o contexto de dispositivo que encapsulado por `CDC`. Em geral, `CDC` chamadas GDI que criar saída acessem o `m_hDC` contexto de dispositivo. Você pode inicializar `m_hDC` e `m_hAttribDC` para apontar para diferentes dispositivos. Consulte o [CDC](../../mfc/reference/cdc-class.md) classe descrição para saber mais sobre o uso desses contextos de dois dispositivo.  
  
##  <a name="a-namemaskblta--cdcmaskblt"></a><a name="maskblt"></a>CDC::MaskBlt  
 Combina os dados de cor para bitmaps de origem e de destino usando a máscara de determinado e a operação de varredura.  
  
```  
BOOL MaskBlt(
    int x,  
    int y,  
    int nWidth,  
    int nHeight,  
    CDC* pSrcDC,  
    int xSrc,  
    int ySrc,  
    CBitmap& maskBitmap,  
    int xMask,  
    int yMask,  
    DWORD dwRop);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica do canto superior esquerdo do retângulo de destino.  
  
 *y*  
 Especifica a coordenada y lógica do canto superior esquerdo do retângulo de destino.  
  
 `nWidth`  
 Especifica a largura, em unidades lógicas, do bitmap retângulo e fonte de destino.  
  
 `nHeight`  
 Especifica a altura, em unidades lógicas, do bitmap retângulo e fonte de destino.  
  
 `pSrcDC`  
 Identifica o contexto de dispositivo do qual o bitmap deve ser copiado. Ele deve ser zero se o *dwRop* parâmetro especifica uma operação de varredura que não inclui uma fonte.  
  
 `xSrc`  
 Especifica a coordenada x lógica do canto superior esquerdo do bitmap de origem.  
  
 `ySrc`  
 Especifica a coordenada y lógica do canto superior esquerdo do bitmap de origem.  
  
 `maskBitmap`  
 Identifica o bitmap monocromático máscara combinado com o bitmap colorido no contexto do dispositivo de origem.  
  
 `xMask`  
 Especifica o deslocamento horizontal de pixel do bitmap máscara especificado pelo `maskBitmap` parâmetro.  
  
 `yMask`  
 Especifica o deslocamento vertical de pixel do bitmap máscara especificado pelo `maskBitmap` parâmetro.  
  
 *dwRop*  
 Especifica o primeiro e segundo plano códigos de operação de varredura Ternário, que usa a função para controlar a combinação de dados de origem e destino. O código de operação de varredura em segundo plano é armazenado no byte mais elevado da palavra alta desse valor; o código de operação de varredura de primeiro plano é armazenado no byte mais inferior da palavra alta desse valor; a palavra inferior desse valor é ignorada e deve ser zero. A macro **MAKEROP4** cria essas combinações de primeiro e segundo plano códigos de operação de varredura. Consulte a seção de comentários para obter uma discussão do primeiro e segundo plano no contexto desta função. Consulte o `BitBlt` a função de membro para obter uma lista de códigos de operação de varredura comuns.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um valor de 1 na máscara especificada por `maskBitmap` indica que o código de operação de varredura de primeiro plano especificado por *dwRop* deve ser aplicada nesse local. Um valor de 0 na máscara indica que o código de operação de varredura em segundo plano especificado por *dwRop* deve ser aplicada nesse local. Se as operações de varredura precisam de uma fonte, o retângulo da máscara deve cobrir o retângulo de origem. Se não existir, a função falhará. Se as operações de varredura não precisam de uma fonte, o retângulo da máscara deve cobrir o retângulo de destino. Se não existir, a função falhará.  
  
 Se uma transformação de rotação ou distorcer está em vigor para o contexto de dispositivo de origem quando essa função é chamada, ocorrerá um erro. No entanto, outros tipos de transformações são permitidos.  
  
 Se os formatos de cor da fonte, padrão e bitmaps de destino forem diferentes, esta função converte o padrão de formato de origem ou ambos, para corresponder ao formato de destino. Se o bitmap de máscara não é um bitmap monocromático, ocorrerá um erro. Quando um metarquivo avançado está sendo gravado, ocorrerá um erro (e a função retornará 0) se o contexto de dispositivo de origem identifica um contexto de dispositivo de metarquivo avançado. Nem todos os dispositivos oferecem suporte à `MaskBlt`. Um aplicativo deve chamar `GetDeviceCaps` para determinar se um dispositivo oferece suporte a essa função. Se nenhum bitmap máscara for fornecido, essa função se comporta exatamente como `BitBlt`, usando o código de operação de varredura de primeiro plano. Desloca o pixel no bitmap máscara mapa para o ponto (0,0) no bitmap do contexto de dispositivo de origem. Isso é útil para casos em que um bitmap de máscara contém um conjunto de máscaras; um aplicativo pode facilmente aplicar qualquer um da uma tarefa de máscara blitting ajustando os deslocamentos de pixel e tamanhos de retângulo enviada para `MaskBlt`.  
  
##  <a name="a-namemodifyworldtransforma--cdcmodifyworldtransform"></a><a name="modifyworldtransform"></a>CDC::ModifyWorldTransform  
 Altera a transformação do mundo para um contexto de dispositivo usando o modo especificado.  
  
```  
BOOL ModifyWorldTransform(
    const XFORM& rXform,  
    DWORD iMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rXform`  
 Referência a um [XFORM](http://msdn.microsoft.com/library/windows/desktop/dd145228) estrutura usada para modificar a transformação world para o contexto determinado dispositivo.  
  
 `iMode`  
 Especifica como os dados de transformação modifica a transformação atual do mundo. Para obter uma lista dos valores que esse parâmetro pode ter, consulte [ModifyWorldTransform](http://msdn.microsoft.com/library/windows/desktop/dd145060).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor diferente de zero em caso de sucesso.  
  
 Retorna 0 em caso de falha.  
  
 Para obter mais informações sobre o erro, chame [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360).  
  
### <a name="remarks"></a>Comentários  
 Esse método encapsula a função Windows GDI [ModifyWorldTransform](http://msdn.microsoft.com/library/windows/desktop/dd145060).  
  
##  <a name="a-namemovetoa--cdcmoveto"></a><a name="moveto"></a>CDC::MoveTo  
 Move a posição atual para o ponto especificado por *x* e *y* (ou `point`).  
  
```  
CPoint MoveTo(
    int x,  
    int y);  
  
CPoint MoveTo(POINT point);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica da nova posição.  
  
 *y*  
 Especifica a coordenada y lógica da nova posição.  
  
 `point`  
 Especifica a nova posição. Você pode passar a uma **ponto** estrutura ou um `CPoint` objeto para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 As coordenadas x e y da posição anterior como um `CPoint` objeto.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRect::CenterPoint](../../atl-mfc-shared/reference/crect-class.md#centerpoint).  
  
##  <a name="a-nameoffsetcliprgna--cdcoffsetcliprgn"></a><a name="offsetcliprgn"></a>CDC::OffsetClipRgn  
 Move a região de recorte do contexto do dispositivo com os deslocamentos especificados.  
  
```  
int OffsetClipRgn(
    int x,  
    int y);  
  
int OffsetClipRgn(SIZE size);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica o número de unidades lógicas para mover para a esquerda ou direita.  
  
 *y*  
 Especifica o número de unidades lógicas para mover para cima ou para baixo.  
  
 `size`  
 Especifica o valor de deslocamento.  
  
### <a name="return-value"></a>Valor de retorno  
 Tipo da nova região. Ele pode ser qualquer um dos seguintes valores:  
  
- **COMPLEXREGION** região de recorte tiver bordas de sobreposição.  
  
- **Erro** o contexto de dispositivo não é válido.  
  
- **NULLREGION** região de recorte está vazio.  
  
- **SIMPLEREGION** região de recorte tiver sem bordas sobrepostas.  
  
### <a name="remarks"></a>Comentários  
 A função move a região *x* unidades no eixo e *y* unidades no eixo y.  
  
##  <a name="a-nameoffsetviewportorga--cdcoffsetviewportorg"></a><a name="offsetviewportorg"></a>CDC::OffsetViewportOrg  
 Modifica as coordenadas da origem visor em relação as coordenadas da origem visor atual.  
  
```  
virtual CPoint OffsetViewportOrg(
    int nWidth,  
    int nHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nWidth`  
 Especifica o número de unidades de dispositivo para adicionar a coordenada x da origem atual.  
  
 `nHeight`  
 Especifica o número de unidades de dispositivo para adicionar a coordenada y da origem atual.  
  
### <a name="return-value"></a>Valor de retorno  
 A origem do visor anterior (nas coordenadas do dispositivo) como um `CPoint` objeto.  
  
##  <a name="a-nameoffsetwindoworga--cdcoffsetwindoworg"></a><a name="offsetwindoworg"></a>CDC::OffsetWindowOrg  
 Modifica as coordenadas da origem da janela em relação as coordenadas da origem da janela atual.  
  
```  
CPoint OffsetWindowOrg(
    int nWidth,  
    int nHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nWidth`  
 Especifica o número de unidades lógicas para adicionar a coordenada x da origem atual.  
  
 `nHeight`  
 Especifica o número de unidades lógicas para adicionar a coordenada y da origem atual.  
  
### <a name="return-value"></a>Valor de retorno  
 A origem de janela anterior (em coordenadas lógicas) como um `CPoint` objeto.  
  
##  <a name="a-nameoperatorhdca--cdcoperator-hdc"></a><a name="operator_hdc"></a>CDC::Operator HDC  
 Usar esse operador para recuperar o identificador de contexto de dispositivo de `CDC` objeto.  
  
```  
operator HDC() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, o identificador de objeto de contexto de dispositivo; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar o identificador para chamar diretamente as APIs do Windows.  
  
##  <a name="a-namepaintrgna--cdcpaintrgn"></a><a name="paintrgn"></a>CDC::PaintRgn  
 Preenche a área especificada pelo `pRgn` usando o pincel atual.  
  
```  
BOOL PaintRgn(CRgn* pRgn);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRgn`  
 Identifica a região a ser preenchido. As coordenadas de determinada região são especificadas em unidades lógicas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
##  <a name="a-namepatblta--cdcpatblt"></a><a name="patblt"></a>CDC::PatBlt  
 Cria um padrão de bit no dispositivo.  
  
```  
BOOL PatBlt(
    int x,  
    int y,  
    int nWidth,  
    int nHeight,  
    DWORD dwRop);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica do canto superior esquerdo do retângulo que receberá o padrão.  
  
 *y*  
 Especifica a coordenada y lógica do canto superior esquerdo do retângulo que receberá o padrão.  
  
 `nWidth`  
 Especifica a largura (em unidades lógicas) do retângulo que receberá o padrão.  
  
 `nHeight`  
 Especifica a altura (em unidades lógicas) do retângulo que receberá o padrão.  
  
 *dwRop*  
 Especifica o código de operação de varredura. Códigos de operação de varredura (ROPs) definem como a GDI combina cores nas operações de saída que envolvem um pincel, um bitmap de origem possíveis e um bitmap de destino. Esse parâmetro pode ser um dos seguintes valores:  
  
- **PATCOPY** padrão de cópias em bitmap de destino.  
  
- **PATINVERT** combina o bitmap de destino com padrão usando o operador XOR booliano.  
  
- **DSTINVERT** inverte o bitmap de destino.  
  
- **ESCURIDÃO** transforma toda a saída preto.  
  
- **WHITENESS** transforma toda a saída branco.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O padrão é uma combinação de pincel selecionado e o padrão já no dispositivo. O código de operação de varredura especificado pelo *dwRop* define como os padrões devem ser combinados. As operações de varredura listadas para essa função são um subconjunto limitado dos códigos de operação de varredura Ternário 256 completo; em particular, um código de operação de varredura refere-se a uma fonte não pode ser usado.  
  
 Nem todos os contextos de dispositivo oferecer suporte a `PatBlt` função. Para determinar se um contexto de dispositivo oferece suporte a `PatBlt`, chamar o `GetDeviceCaps` a função de membro com o **RASTERCAPS** índice e verificar o valor de retorno para o **RC_BITBLT** sinalizador.  
  
##  <a name="a-namepiea--cdcpie"></a><a name="pie"></a>CDC::Pie  
 Desenha uma fatia de pizza em forma desenhando um arco elíptico cujo centro e dois pontos de extremidade são unidos por linhas.  
  
```  
BOOL Pie(
    int x1,  
    int y1,  
    int x2,  
    int y2,  
    int x3,  
    int y3,  
    int x4,  
    int y4);

 
BOOL Pie(
    LPCRECT lpRect,
    POINT ptStart,
    POINT ptEnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `x1`  
 Especifica a coordenada x do canto superior esquerdo do retângulo delimitador (em unidades lógicas).  
  
 `y1`  
 Especifica a coordenada y do canto superior esquerdo do retângulo delimitador (em unidades lógicas).  
  
 `x2`  
 Especifica a coordenada x do canto inferior direito do retângulo delimitador (em unidades lógicas).  
  
 `y2`  
 Especifica a coordenada y do canto inferior direito do retângulo delimitador (em unidades lógicas).  
  
 *X3*  
 Especifica a coordenada x do ponto de partida do arco (em unidades lógicas). Esse ponto não precisa estar exatamente em arco.  
  
 `y3`  
 Especifica a coordenada y do ponto de partida do arco (em unidades lógicas). Esse ponto não precisa estar exatamente em arco.  
  
 `x4`  
 Especifica a coordenada x do ponto de extremidade do arco (em unidades lógicas). Esse ponto não precisa estar exatamente em arco.  
  
 `y4`  
 Especifica a coordenada y do ponto de extremidade do arco (em unidades lógicas). Esse ponto não precisa estar exatamente em arco.  
  
 `lpRect`  
 Especifica o retângulo delimitador. Você pode passar a uma `CRect` objeto ou um ponteiro para um `RECT` estrutura para esse parâmetro.  
  
 `ptStart`  
 Especifica o ponto de partida do arco. Esse ponto não precisa estar exatamente em arco. Você pode passar a uma [ponto](../../mfc/reference/point-structure1.md) estrutura ou um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto para esse parâmetro.  
  
 `ptEnd`  
 Especifica o ponto de extremidade do arco. Esse ponto não precisa estar exatamente em arco. Você pode passar a uma **ponto** estrutura ou um `CPoint` objeto para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O centro do arco é o centro do retângulo delimitador especificado por `x1`, `y1`, `x2`, e `y2` (ou `lpRect`). Pontos do arco a inicial e final são especificados por *x3*, `y3`, `x4`, e `y4` (ou pelo `ptStart` e `ptEnd`).  
  
 O arco é desenhado com a caneta selecionada, movendo no sentido anti-horário. Duas linhas adicionais são desenhadas de cada ponto de extremidade ao centro do arco. A área em forma de pizza é preenchida com o pincel atual. Se *x3* é igual a `x4` e `y3` é igual a `y4`, o resultado é uma elipse com uma única linha do centro da elipse até o ponto ( *x3*, `y3`) ou ( `x4`, `y4`).  
  
 A Figura desenhada por essa função se estende até, mas não inclui as coordenadas da direita e inferior. Isso significa que a altura da figura `y2` – `y1` e a largura da figura é `x2` – `x1`. A largura e a altura do retângulo delimitador devem ser maiores que 2 unidades e inferior a 32.767.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#37;](../../mfc/codesnippet/cpp/cdc-class_9.cpp)]  
  
##  <a name="a-nameplaymetafilea--cdcplaymetafile"></a><a name="playmetafile"></a>CDC::PlayMetaFile  
 Reproduz o conteúdo do metarquivo especificado no contexto do dispositivo.  
  
```  
BOOL PlayMetaFile(HMETAFILE hMF);

 
BOOL PlayMetaFile(
    HENHMETAFILE hEnhMetaFile,  
    LPCRECT lpBounds);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hMF*  
 Identifica o metarquivo a ser executado.  
  
 *hEnhMetaFile*  
 Identifica o metarquivo avançado.  
  
 `lpBounds`  
 Aponta para um `RECT` estrutura ou um `CRect` objeto que contém as coordenadas do retângulo delimitador usado para exibir a imagem. As coordenadas são especificadas em unidades lógicas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O metarquivo pode ser executado várias vezes.  
  
 A segunda versão do `PlayMetaFile` exibe a imagem armazenada em determinado metarquivo aprimorado de formato. Quando um aplicativo chama a segunda versão do `PlayMetaFile`, o Windows usa o quadro de imagem no cabeçalho de metarquivo avançado para mapear a imagem para o retângulo apontada pelo `lpBounds` parâmetro. (Essa imagem pode ser distorcida ou girada, definindo a transformação world no dispositivo de saída antes de chamar `PlayMetaFile`.) Pontos ao longo das bordas do retângulo estão incluídos na imagem. Uma imagem de metarquivo avançado pode ser recortada definindo a região de recorte no dispositivo de saída antes de reproduzir o metarquivo avançado.  
  
 Se um metarquivo avançado contém uma paleta opcional, um aplicativo pode obter cores consistentes, definindo uma paleta de cores do dispositivo de saída antes de chamar a segunda versão do `PlayMetaFile`. Para recuperar a paleta opcional, use o **GetEnhMetaFilePaletteEntries** função do Windows. Um metarquivo avançado pode ser inserido em um metarquivo recém-criado chamando a segunda versão do `PlayMetaFile` e execução de metarquivo aprimorado de origem no contexto de dispositivo para o novo metarquivo avançado.  
  
 Os estados do contexto do dispositivo de saída são preservados por essa função. Qualquer objeto criado, mas não excluída de metarquivo avançado é excluído por essa função. Para interromper a essa função, um aplicativo pode chamar o **CancelDC** função do Windows de outro thread para encerrar a operação. Nesse caso, a função retorna zero.  
  
##  <a name="a-nameplgblta--cdcplgblt"></a><a name="plgblt"></a>CDC::PlgBlt  
 Executa uma transferência de bloco de bits dos bits de dados de cor do retângulo especificado no contexto do dispositivo de origem para paralelogramo especificado no contexto de determinado dispositivo.  
  
```  
BOOL PlgBlt(
    LPPOINT lpPoint,  
    CDC* pSrcDC,  
    int xSrc,  
    int ySrc,  
    int nWidth,  
    int nHeight,  
    CBitmap& maskBitmap,  
    int xMask,  
    int yMask);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPoint`  
 Aponta para uma matriz de três pontos no espaço lógico que identifica três vértices do paralelogramo destino. O canto superior esquerdo do retângulo de origem é mapeado para o primeiro ponto nessa matriz, o canto superior direito e o segundo ponto nessa matriz e o canto inferior esquerdo para o terceiro ponto. O canto inferior direito do retângulo de origem é mapeado para o ponto de quarto implícito em um paralelogramo.  
  
 `pSrcDC`  
 Identifica o contexto de dispositivo de origem.  
  
 `xSrc`  
 Especifica a coordenada x em unidades lógicas, do canto superior esquerdo do retângulo de origem.  
  
 `ySrc`  
 Especifica a coordenada y em unidades lógicas, do canto superior esquerdo do retângulo de origem.  
  
 `nWidth`  
 Especifica a largura, em unidades lógicas, do retângulo de origem.  
  
 `nHeight`  
 Especifica a altura, em unidades lógicas, do retângulo de origem.  
  
 `maskBitmap`  
 Identifica um bitmap monocromático opcional que é usado para mascarar as cores do retângulo de origem.  
  
 `xMask`  
 Especifica a coordenada x do canto superior esquerdo do bitmap monocromático.  
  
 `yMask`  
 Especifica a coordenada y do canto superior esquerdo do bitmap monocromático.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o identificador de bitmask determinado identifica um bitmap monocromático válido, a função usa esse bitmap para mascarar os bits de dados de cor do retângulo de origem.  
  
 O quarto vértice do paralelogramo (D) é definido por tratar os primeiros três pontos (A, B e C) como vetores e computação D = B + C - A.  
  
 Se existir a máscara de bits, um valor de 1 na máscara indica que a cor do pixel de origem deve ser copiada para o destino. Um valor de 0 na máscara indica que a cor do pixel de destino não é devem ser alterados.  
  
 Se o retângulo da máscara é menor do que os retângulos de origem e de destino, a função replica o padrão de máscara.  
  
 Transformações de escala, conversão e reflexão são permitidas no contexto do dispositivo de origem; No entanto, as transformações de rotação e distorção não são. Se o bitmap de máscara não é um bitmap monocromático, ocorrerá um erro. O modo de alongamento para o contexto de dispositivo de destino é usado para determinar como alongar ou compactar os pixels, se for necessário. Quando um metarquivo avançado está sendo gravado, ocorrerá um erro se o contexto de dispositivo de origem identifica um contexto de dispositivo de metarquivo avançado.  
  
 As coordenadas de destino são transformadas de acordo com o contexto do dispositivo de destino; as coordenadas de origem são transformadas de acordo com o contexto do dispositivo de origem. Se a transformação de origem tem uma rotação ou distorcer, um erro será retornado. Se os retângulos de origem e destino não têm o mesmo formato de cor, `PlgBlt` converte o retângulo de origem para coincidir com o retângulo de destino. Nem todos os dispositivos oferecem suporte à `PlgBlt`. Para obter mais informações, consulte a descrição do **RC_BITBLT** recurso varredura o `CDC::GetDeviceCaps` função de membro.  
  
 Se os contextos de dispositivo de origem e destino representam dispositivos incompatíveis, `PlgBlt` retornará um erro.  
  
##  <a name="a-namepolybeziera--cdcpolybezier"></a><a name="polybezier"></a>CDC::PolyBezier  
 Desenha um ou mais splines Bzier.  
  
```  
BOOL PolyBezier(
    const POINT* lpPoints,  
    int nCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPoints`  
 Aponta para uma matriz de [ponto](../../mfc/reference/point-structure1.md) estruturas de dados que contém os pontos de extremidade e pontos do spline(s) de controle.  
  
 `nCount`  
 Especifica o número de pontos de `lpPoints` matriz. Esse valor deve ser um mais de três vezes o número de splines a ser desenhada, porque cada spline Bzier requer dois pontos de controle e um ponto de extremidade e o spline inicial requer um ponto de partida adicional.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função desenha cúbicas splines Bzier usando os pontos de extremidade e pontos de controle especificados pelo `lpPoints` parâmetro. O primeiro spline é desenhado do primeiro ponto o quarto ponto usando os pontos de segundo e terceiro como pontos de controle. Cada spline subsequente na sequência precisa exatamente três pontos mais: o ponto de extremidade da spline anterior é usado como o ponto de partida, os dois pontos na sequência são pontos de controle e o terceiro é o ponto de extremidade.  
  
 A posição atual não é usada nem atualizada pelo `PolyBezier` função. A figura não foi preenchida. Essa função desenha linhas usando a caneta atual.  
  
##  <a name="a-namepolybeziertoa--cdcpolybezierto"></a><a name="polybezierto"></a>CDC::PolyBezierTo  
 Desenha um ou mais splines Bzier.  
  
```  
BOOL PolyBezierTo(
    const POINT* lpPoints,  
    int nCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPoints`  
 Aponta para uma matriz de [ponto](../../mfc/reference/point-structure1.md) pontos de estruturas de dados que contém o controle e os pontos de extremidade.  
  
 `nCount`  
 Especifica o número de pontos de `lpPoints` matriz. Esse valor deve ser três vezes o número de splines a ser desenhada, porque cada spline Bzier requer dois pontos de controle e um ponto final.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função desenha cúbicas splines Bzier usando os pontos de controle especificados pelo `lpPoints` parâmetro. O primeiro spline é desenhado da posição atual para o terceiro ponto usando os dois primeiros pontos como pontos de controle. Para cada spline subsequente, a função precisa exatamente três pontos mais e usa o ponto de extremidade da spline anterior como o ponto de partida para a próxima. `PolyBezierTo`Move a posição atual para o ponto de extremidade da última Bzier spline. A figura não foi preenchida. Essa função desenha linhas usando a caneta atual.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CDC:: beginpath](#beginpath).  
  
##  <a name="a-namepolydrawa--cdcpolydraw"></a><a name="polydraw"></a>CDC::PolyDraw  
 Desenha um conjunto de segmentos de linha e Bzier splines.  
  
```  
BOOL PolyDraw(
    const POINT* lpPoints,  
    const BYTE* lpTypes,  
    int nCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPoints`  
 Aponta para uma matriz de [ponto](../../mfc/reference/point-structure1.md) estruturas de dados que contém os pontos de extremidade para cada linha de segmento e os pontos de extremidade e pontos para cada spline Bzier de controle.  
  
 `lpTypes`  
 Aponta para uma matriz que especifica como cada ponto de `lpPoints` matriz é usada. Valores podem ser um dos seguintes:  
  
- **PT_MOVETO** Especifica que esse ponto inicia uma figura de separação. Esse ponto se tornará a nova posição atual.  
  
- **PT_LINETO** Especifica que uma linha a ser desenhada na posição atual para este ponto, que se torna a nova posição atual.  
  
- **PT_BEZIERTO** Especifica que esse ponto é um ponto de controle ou o ponto final para um spline Bzier.  
  
 **PT_BEZIERTO** tipos sempre ocorrem em conjuntos de três. A posição atual define o ponto de partida para o spline Bzier. Os dois primeiros **PT_BEZIERTO** pontos são os pontos de controle e a terceira **PT_BEZIERTO** ponto é o ponto final. O ponto final se torna a nova posição atual. Se não houver três consecutivas **PT_BEZIERTO** pontos, um erro de resultados.  
  
     A **PT_LINETO** ou **PT_BEZIERTO** tipo pode ser combinado com a constante a seguir usando o operador bit a bit ou indicar que o ponto correspondente é o último ponto em uma figura e a figura fechada:  
  
- **PT_CLOSEFIGURE** Especifica que a figura é fechada automaticamente após o **PT_LINETO** ou **PT_BEZIERTO** o tipo para esse ponto é feito. Uma linha é desenhada a partir deste ponto mais recente **PT_MOVETO** ou `MoveTo` ponto.  
  
     Esse sinalizador é combinado com o **PT_LINETO** tipo para uma linha ou com o **PT_BEZIERTO** tipo de final para um spline Bzier, usando o bit a bit `OR` operador. A posição atual é definida como o ponto final da linha de fechamento.  
  
 `nCount`  
 Especifica o número total de pontos no `lpPoints` de matriz, o mesmo que o número de bytes na `lpTypes` matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função pode ser usada para desenhar figuras separadas em vez de chamadas consecutivas para `CDC::MoveTo`, `CDC::LineTo`, e `CDC::PolyBezierTo` funções de membro. As linhas e splines são desenhados usando a caneta atual e figuras não são preenchidas. Se há um caminho ativo iniciado chamando o `CDC::BeginPath` função de membro `PolyDraw` adiciona ao caminho. Os pontos contidos a `lpPoints` matriz e, em `lpTypes` indicam se cada ponto é parte de um `CDC::MoveTo`, um `CDC::LineTo`, ou um **CDC::BezierTo** operação. Também é possível fechar as figuras. Essa função atualiza a posição atual.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CDC:: beginpath](#beginpath).  
  
##  <a name="a-namepolygona--cdcpolygon"></a><a name="polygon"></a>CDC::Polygon  
 Desenha um polígono consiste em dois ou mais pontos (vértices) conectados por linhas, usando a caneta atual.  
  
```  
BOOL Polygon(
    LPPOINT lpPoints,  
    int nCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPoints`  
 Aponta para uma matriz de pontos que especifica os vértices do polígono. Cada ponto na matriz é um **ponto** estrutura ou um `CPoint` objeto.  
  
 `nCount`  
 Especifica o número de vértices na matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O sistema fecha o polígono automaticamente, se necessário, desenhando uma linha do último vértice ao primeiro.  
  
 O modo de preenchimento de polígono atual pode ser recuperado ou definido usando o `GetPolyFillMode` e `SetPolyFillMode` funções de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&38;](../../mfc/codesnippet/cpp/cdc-class_10.cpp)]  
  
##  <a name="a-namepolylinea--cdcpolyline"></a><a name="polyline"></a>CDC::Polyline  
 Desenha um conjunto de segmentos de linha se conectar os pontos especificado por `lpPoints`.  
  
```  
BOOL Polyline(
    LPPOINT lpPoints,  
    int nCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPoints`  
 Aponta para uma matriz de **ponto** estruturas ou `CPoint` objetos a ser conectado.  
  
 `nCount`  
 Especifica o número de pontos da matriz. Esse valor deve ser pelo menos 2.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 As linhas são desenhadas no primeiro ponto pelos pontos subsequentes usando a caneta atual. Ao contrário do `LineTo` função de membro, o `Polyline` função não usa nem atualiza a posição atual.  
  
 Para obter mais informações, consulte [PolyLine](http://msdn.microsoft.com/library/windows/desktop/dd162815) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namepolylinetoa--cdcpolylineto"></a><a name="polylineto"></a>CDC::PolylineTo  
 Desenha uma ou mais linhas retas.  
  
```  
BOOL PolylineTo(
    const POINT* lpPoints,  
    int nCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPoints`  
 Aponta para uma matriz de [ponto](../../mfc/reference/point-structure1.md) estruturas de dados que contém os vértices da linha.  
  
 `nCount`  
 Especifica o número de pontos da matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Uma linha é desenhada a partir da posição atual até o primeiro ponto especificado pelo `lpPoints` parâmetro usando a caneta atual. Para cada linha adicional, desenha a função do ponto final da linha anterior para o próximo ponto especificado por `lpPoints`. `PolylineTo`Move a posição atual para o ponto final da última linha. Se os segmentos de linha desenhados por essa função formam uma figura fechada, a figura não foi preenchida.  
  
##  <a name="a-namepolypolygona--cdcpolypolygon"></a><a name="polypolygon"></a>CDC::PolyPolygon  
 Cria dois ou mais polígonos que são preenchidos usando o modo de preenchimento de polígono atual.  
  
```  
BOOL PolyPolygon(
    LPPOINT lpPoints,  
    LPINT lpPolyCounts,  
    int nCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPoints`  
 Aponta para uma matriz de **ponto** estruturas ou `CPoint` objetos que definem os vértices dos polígonos.  
  
 `lpPolyCounts`  
 Aponta para uma matriz de inteiros, cada um deles Especifica o número de pontos em um dos polígonos na `lpPoints` matriz.  
  
 `nCount`  
 O número de entradas na `lpPolyCounts` matriz. Esse número Especifica o número de polígonos a ser desenhada. Esse valor deve ser pelo menos 2.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Os polígonos podem ser separado ou sobrepostos.  
  
 Cada polígono especificado em uma chamada para o `PolyPolygon` função deve ser fechada. Ao contrário de polígonos criados pelo **polígono** função de membro, os polígonos criados pelo `PolyPolygon` não são fechados automaticamente.  
  
 A função cria dois ou mais polígonos. Para criar um único polígono, um aplicativo deve usar o **polígono** função de membro.  
  
 O modo de preenchimento de polígono atual pode ser recuperado ou definido usando o `GetPolyFillMode` e `SetPolyFillMode` funções de membro.  
  
##  <a name="a-namepolypolylinea--cdcpolypolyline"></a><a name="polypolyline"></a>CDC::PolyPolyline  
 Desenha várias séries de segmentos de linha conectados.  
  
```  
BOOL PolyPolyline(
    const POINT* lpPoints,  
    const DWORD* lpPolyPoints,  
    int nCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPoints`  
 Aponta para uma matriz de estruturas que contém os vértices das polilinhas. As polilinhas especificadas consecutivas.  
  
 `lpPolyPoints`  
 Aponta para uma matriz de variáveis especificando o número de pontos de `lpPoints` matriz polígono correspondente. Cada entrada deve ser maior ou igual a 2.  
  
 `nCount`  
 Especifica o número total de contagens de na `lpPolyPoints` matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Os segmentos de linha são desenhados usando a caneta atual. As figuras formadas por segmentos não são preenchidas. A posição atual não é usada nem atualizada por essa função.  
  
##  <a name="a-nameptvisiblea--cdcptvisible"></a><a name="ptvisible"></a>CDC::PtVisible  
 Determina se o ponto está dentro da região de recorte do contexto do dispositivo.  
  
```  
virtual BOOL PtVisible(
    int x,  
    int y) const;  
  
BOOL PtVisible(POINT point) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica do ponto.  
  
 *y*  
 Especifica a coordenada y lógica do ponto.  
  
 `point`  
 Especifica o ponto de verificação em coordenadas lógicas. Você pode passar a uma **ponto** estrutura ou um `CPoint` objeto para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o ponto especificado está dentro da região de recorte; Caso contrário, 0.  
  
##  <a name="a-namequeryaborta--cdcqueryabort"></a><a name="queryabort"></a>CDC::QueryAbort  
 Chama a função abort instalada o [SetAbortProc](#setabortproc) função do membro para um aplicativo de impressão e consultas se a impressão deve ser encerrada.  
  
```  
BOOL QueryAbort() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno é diferente de zero se a impressão deve continuar ou se não houver nenhum procedimento de anulação. Ele é 0 se o trabalho de impressão deve ser encerrado. O valor de retorno é fornecido pela função de anulação.  
  
##  <a name="a-namerealizepalettea--cdcrealizepalette"></a><a name="realizepalette"></a>CDC::RealizePalette  
 Mapeia as entradas da paleta lógica atual para a paleta do sistema.  
  
```  
UINT RealizePalette();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Indica o número de entradas na paleta lógico foram mapeado para entradas diferentes na paleta do sistema. Isso representa o número de entradas que essa função remapeada para acomodar alterações na paleta do sistema, pois a paleta lógica última foi realizada.  
  
### <a name="remarks"></a>Comentários  
 Uma paleta de cores lógicas age como um buffer entre aplicativos com uso intensivo de cor e o sistema, permitindo que um aplicativo para usar como conforme necessário sem interferir com seu próprio número de cores exibidas cores ou cores exibidas por outras janelas.  
  
 Quando uma janela tem o foco de entrada e chamadas `RealizePalette`, Windows garante que a janela exibirá todas as cores solicitadas, até o número máximo simultaneamente disponível na tela. O Windows também exibe cores não encontradas na paleta da janela, comparando-as às cores disponíveis.  
  
 Além disso, o Windows corresponde às cores solicitadas pelo windows inativos que chamam a função mais próximo possível para as cores disponíveis. Isso reduz significativamente a alterações indesejadas nas cores exibidas nas janelas inativas.  
  
##  <a name="a-namerectanglea--cdcrectangle"></a><a name="rectangle"></a>CDC::Rectangle  
 Desenha um retângulo usando a caneta atual.  
  
```  
BOOL Rectangle(
    int x1,  
    int y1,  
    int x2,  
    int y2);  
  
BOOL Rectangle(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `x1`  
 Especifica a coordenada x do canto superior esquerdo do retângulo (em unidades lógicas).  
  
 `y1`  
 Especifica a coordenada y do canto superior esquerdo do retângulo (em unidades lógicas).  
  
 `x2`  
 Especifica a coordenada x do canto inferior direito do retângulo (em unidades lógicas).  
  
 `y2`  
 Especifica a coordenada y do canto inferior direito do retângulo (em unidades lógicas).  
  
 `lpRect`  
 Especifica o retângulo em unidades lógicas. Você pode passar a uma `CRect` objeto ou um ponteiro para um `RECT` estrutura para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O interior do retângulo é preenchido usando o pincel atual.  
  
 O retângulo se estende até, mas não inclui as coordenadas da direita e inferior. Isso significa que a altura do retângulo é `y2` – `y1` e a largura do retângulo é `x2` – `x1`. A largura e a altura de um retângulo devem ser maiores que 2 unidades e inferior a 32.767.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#39;](../../mfc/codesnippet/cpp/cdc-class_11.cpp)]  
  
##  <a name="a-namerectvisiblea--cdcrectvisible"></a><a name="rectvisible"></a>CDC::RectVisible  
 Determina se qualquer parte do retângulo especificado está dentro da região de recorte do contexto da exibição.  
  
```  
virtual BOOL RectVisible(LPCRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para um `RECT` estrutura ou um `CRect` objeto que contém as coordenadas lógicas do retângulo especificado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se qualquer parte do retângulo especificado está dentro da região de recorte; Caso contrário, 0.  
  
##  <a name="a-namereleaseattribdca--cdcreleaseattribdc"></a><a name="releaseattribdc"></a>CDC::ReleaseAttribDC  
 Chame essa função de membro para definir `m_hAttribDC` para **nulo**.  
  
```  
virtual void ReleaseAttribDC();
```  
  
### <a name="remarks"></a>Comentários  
 Isso não causa uma **desanexar** ocorra. Somente o contexto de dispositivo de saída está associado a `CDC` objeto e somente ele podem ser desanexado.  
  
##  <a name="a-namereleaseoutputdca--cdcreleaseoutputdc"></a><a name="releaseoutputdc"></a>CDC::ReleaseOutputDC  
 Chame essa função de membro para definir o `m_hDC` membro **nulo**.  
  
```  
virtual void ReleaseOutputDC();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro não pode ser chamada quando o contexto de dispositivo de saída está associado a `CDC` objeto. Use o **desanexar** função de membro para desanexar o contexto de dispositivo de saída.  
  
##  <a name="a-nameresetdca--cdcresetdc"></a><a name="resetdc"></a>CDC::ResetDC  
 Chame essa função de membro para atualizar o contexto de dispositivo encapsulado pelo `CDC` objeto.  
  
```  
BOOL ResetDC(const DEVMODE* lpDevMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpDevMode*  
 Um ponteiro para um Windows `DEVMODE` estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O contexto de dispositivo é atualizado com as informações especificadas no Windows `DEVMODE` estrutura. Essa função de membro apenas redefine o contexto de dispositivo do atributo.  
  
 Um aplicativo normalmente usará o `ResetDC` função de membro quando uma janela processa um `WM_DEVMODECHANGE` mensagem. Você também pode usar essa função de membro para alterar a orientação do papel ou compartimentos de papel ao imprimir um documento.  
  
 Você não pode usar essa função de membro para alterar o nome do driver, o nome do dispositivo ou porta de saída. Quando o usuário altera a conexão de porta ou nome do dispositivo, você deve excluir o contexto de dispositivo original e criar um novo contexto de dispositivo com as novas informações.  
  
 Antes de chamar essa função de membro, você deve garantir que todos os objetos que tiverem sido selecionados no contexto de dispositivo (diferentes de objetos de estoque) foram selecionados horizontalmente.  
  
##  <a name="a-namerestoredca--cdcrestoredc"></a><a name="restoredc"></a>CDC::RestoreDC  
 Restaura o contexto de dispositivo para o estado anterior identificado pelo `nSavedDC`.  
  
```  
virtual BOOL RestoreDC(int nSavedDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSavedDC`  
 Especifica o contexto de dispositivo a ser restaurado. Pode ser um valor retornado pela anterior `SaveDC` chamada de função. Se `nSavedDC` é –&1;, salvo mais recentemente contexto de dispositivo é restaurado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o contexto especificado foi restaurado. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 `RestoreDC`Restaura o contexto de dispositivo, exibir informações de estado de uma pilha criado por chamadas anteriores para o `SaveDC` função de membro.  
  
 A pilha pode conter as informações de estado para vários contextos de dispositivo. Se o contexto especificado por `nSavedDC` não está no topo da pilha, `RestoreDC` exclui todas as informações de estado entre o contexto de dispositivo especificado por `nSavedDC` e a parte superior da pilha. As informações excluídas são perdidas.  
  
##  <a name="a-nameroundrecta--cdcroundrect"></a><a name="roundrect"></a>CDC::RoundRect  
 Desenha um retângulo com cantos arredondados usando a caneta atual.  
  
```  
BOOL RoundRect(
    int x1,  
    int y1,  
    int x2,  
    int y2,  
    int x3,  
    int y3);

 
BOOL RoundRect(
    LPCRECT lpRect,
    POINT point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `x1`  
 Especifica a coordenada x do canto superior esquerdo do retângulo (em unidades lógicas).  
  
 `y1`  
 Especifica a coordenada y do canto superior esquerdo do retângulo (em unidades lógicas).  
  
 `x2`  
 Especifica a coordenada x do canto inferior direito do retângulo (em unidades lógicas).  
  
 `y2`  
 Especifica a coordenada y do canto inferior direito do retângulo (em unidades lógicas).  
  
 *X3*  
 Especifica a largura da elipse usada para desenhar os cantos arredondados (em unidades lógicas).  
  
 `y3`  
 Especifica a altura da elipse usada para desenhar os cantos arredondados (em unidades lógicas).  
  
 `lpRect`  
 Especifica o retângulo delimitador em unidades lógicas. Você pode passar a uma `CRect` objeto ou um ponteiro para um `RECT` estrutura para esse parâmetro.  
  
 `point`  
 A coordenada x do `point` Especifica a largura da elipse para desenhar os cantos arredondados (em unidades lógicas). A coordenada y do `point` Especifica a altura da elipse para desenhar os cantos arredondados (em unidades lógicas). Você pode passar a uma **ponto** estrutura ou um `CPoint` objeto para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O interior do retângulo é preenchido usando o pincel atual.  
  
 A figura a que essa função desenha se estende até, mas não inclui as coordenadas da direita e inferior. Isso significa que a altura da figura `y2` – `y1` e a largura da figura é `x2` – `x1`. A altura e a largura do retângulo delimitador devem ser maiores que 2 unidades e inferior a 32.767.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[40 NVC_MFCDocView](../../mfc/codesnippet/cpp/cdc-class_12.cpp)]  
  
##  <a name="a-namesavedca--cdcsavedc"></a><a name="savedc"></a>CDC::SaveDC  
 Salva o estado atual do contexto do dispositivo, copiando informações de estado (como a região de recorte, objetos selecionados e modo de mapeamento) para uma pilha de contexto mantida pelo Windows.  
  
```  
virtual int SaveDC();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro que identifica o contexto de dispositivo salvo. Ele é 0 se ocorrer um erro. Isso retornará o valor pode ser usado para restaurar o contexto de dispositivo chamando `RestoreDC`.  
  
### <a name="remarks"></a>Comentários  
 O contexto de dispositivo salvo posteriormente pode ser restaurado usando `RestoreDC`.  
  
 `SaveDC`pode ser usado qualquer número de vezes para salvar qualquer número de estados de contexto de dispositivo.  
  
##  <a name="a-namescaleviewportexta--cdcscaleviewportext"></a><a name="scaleviewportext"></a>CDC::ScaleViewportExt  
 Modifica as extensões do visor em relação os valores atuais.  
  
```  
virtual CSize ScaleViewportExt(
    int xNum,  
    int xDenom,  
    int yNum,  
    int yDenom);
```  
  
### <a name="parameters"></a>Parâmetros  
 `xNum`  
 Especifica a quantidade pela qual multiplicar a x-extensão atual.  
  
 `xDenom`  
 Especifica a quantidade pela qual dividir o resultado da multiplicação da extensão de x atual pelo valor da `xNum` parâmetro.  
  
 `yNum`  
 Especifica a quantidade pela qual multiplicar a y-extensão atual.  
  
 `yDenom`  
 Especifica a quantidade pela qual dividir o resultado da multiplicação da extensão de y atual pelo valor da `yNum` parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 As extensões de visor anterior (em unidades de dispositivo) como um `CSize` objeto.  
  
### <a name="remarks"></a>Comentários  
 As fórmulas são escritas da seguinte maneira:  
  
 `xNewVE = ( xOldVE * xNum ) / xDenom`  
  
 `yNewVE = ( yOldVE * yNum ) / yDenom`  
  
 As novas extensões de visor são calculadas pela multiplicação as extensões atuais por determinado numerador e dividindo por determinado denominador.  
  
##  <a name="a-namescalewindowexta--cdcscalewindowext"></a><a name="scalewindowext"></a>CDC::ScaleWindowExt  
 Modifica as extensões de janela em relação os valores atuais.  
  
```  
virtual CSize ScaleWindowExt(
    int xNum,  
    int xDenom,  
    int yNum,  
    int yDenom);
```  
  
### <a name="parameters"></a>Parâmetros  
 `xNum`  
 Especifica a quantidade pela qual multiplicar a x-extensão atual.  
  
 `xDenom`  
 Especifica a quantidade pela qual dividir o resultado da multiplicação da extensão de x atual pelo valor da `xNum` parâmetro.  
  
 `yNum`  
 Especifica a quantidade pela qual multiplicar a y-extensão atual.  
  
 `yDenom`  
 Especifica a quantidade pela qual dividir o resultado da multiplicação da extensão de y atual pelo valor da `yNum` parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 As extensões de janela anterior (em unidades lógicas) como um `CSize` objeto.  
  
### <a name="remarks"></a>Comentários  
 As fórmulas são escritas da seguinte maneira:  
  
 `xNewWE = ( xOldWE * xNum ) / xDenom`  
  
 `yNewWE = ( yOldWE * yNum ) / yDenom`  
  
 As novas extensões de janela são calculadas pela multiplicação as extensões atuais por determinado numerador e dividindo por determinado denominador.  
  
##  <a name="a-namescrolldca--cdcscrolldc"></a><a name="scrolldc"></a>CDC::ScrollDC  
 Rola um retângulo de bits horizontalmente e verticalmente.  
  
```  
BOOL ScrollDC(
    int dx,  
    int dy,  
    LPCRECT lpRectScroll,  
    LPCRECT lpRectClip,  
    CRgn* pRgnUpdate,  
    LPRECT lpRectUpdate);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dx`  
 Especifica o número de unidades de rolagem horizontal.  
  
 *dy*  
 Especifica o número de unidades de rolagem vertical.  
  
 `lpRectScroll`  
 Aponta para a `RECT` estrutura ou `CRect` objeto que contém as coordenadas do retângulo de rolagem.  
  
 `lpRectClip`  
 Aponta para a `RECT` estrutura ou `CRect` objeto que contém as coordenadas do retângulo de recorte. Quando esse retângulo é menor do que o original um apontada por `lpRectScroll`, rolagem ocorre apenas no retângulo menor.  
  
 `pRgnUpdate`  
 Identifica a região revelada pelo processo de rolagem. O `ScrollDC` função define essa região; ele não é necessariamente um retângulo.  
  
 `lpRectUpdate`  
 Aponta para a `RECT` estrutura ou `CRect` objeto que recebe as coordenadas do retângulo que circunda a área de rolagem de atualização. Essa é a maior área retangular que requer repintura. A estrutura ou o objeto quando a função retorna os valores estão nas coordenadas do cliente, independentemente do modo de mapeamento para o contexto determinado dispositivo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a rolagem é executada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se `lpRectUpdate` é **nulo**, Windows não calcula o retângulo de atualização. Se ambos os `pRgnUpdate` e `lpRectUpdate` são **nulo**, Windows não computa a região de atualização. Se `pRgnUpdate` não é **nulo**, o Windows presume que ela contém um ponteiro válido para a região revelado pelo processo de rolagem (definido pelo `ScrollDC` função de membro). A região de atualização retornada em `lpRectUpdate` pode ser passado para `CWnd::InvalidateRgn` se necessário.  
  
 Um aplicativo deve usar o `ScrollWindow` a função de membro da classe `CWnd` quando é necessário rolar toda a área cliente de uma janela. Caso contrário, ele deve usar `ScrollDC`.  
  
##  <a name="a-nameselectclippatha--cdcselectclippath"></a><a name="selectclippath"></a>CDC::SelectClipPath  
 Seleciona o caminho atual como uma região de recorte para o contexto de dispositivo, combinando a nova região com qualquer região de recorte existente usando o modo especificado.  
  
```  
BOOL SelectClipPath(int nMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMode`  
 Especifica a maneira de usar o caminho. Os valores a seguir são permitidos:  
  
- **RGN_AND** a nova região de recorte inclui a interseção (áreas de sobreposição) da região de recorte atual e o caminho atual.  
  
- **RGN_COPY** a nova região de recorte é o caminho atual.  
  
- **RGN_DIFF** a nova região de recorte inclui as áreas da região de recorte atual e do caminho atual serão excluídos.  
  
- **RGN_OR** a nova região de recorte inclui a união (áreas combinadas) da região de recorte atual e o caminho atual.  
  
- **RGN_XOR** a nova região de recorte inclui a união da região de recorte atual e o caminho atual, mas sem as áreas sobrepostas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O contexto de dispositivo identificado deve conter um caminho fechado.  
  
##  <a name="a-nameselectcliprgna--cdcselectcliprgn"></a><a name="selectcliprgn"></a>CDC::SelectClipRgn  
 Seleciona a determinada região como a região de recorte atual para o contexto de dispositivo.  
  
```  
int SelectClipRgn(CRgn* pRgn);

 
int SelectClipRgn(
    CRgn* pRgn,  
    int nMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRgn`  
 Identifica a região a ser selecionado.  
  
-   Para a primeira versão dessa função, se esse valor for **nulo**, toda a área cliente está selecionada e saída ainda será recortada para a janela.  
  
-   Para a segunda versão dessa função, esse identificador pode ser **nulo** somente quando o **RGN_COPY** modo é especificado.  
  
 `nMode`  
 Especifica a operação a ser executada. Ele deve ser um dos seguintes valores:  
  
- **RGN_AND** a nova região de recorte combina as áreas sobrepostas da região de recorte atual e a região identificado por `pRgn`.  
  
- **RGN_COPY** a nova região de recorte é uma cópia da região indicada pelo `pRgn`. Essa é uma funcionalidade é idêntica à primeira versão do `SelectClipRgn`. Se a região identificado por `pRgn` é **nulo**, a região de recorte padrão (uma região nula) se torna a nova região de recorte.  
  
- **RGN_DIFF** a nova região de recorte combina as áreas da região de recorte atual com as áreas excluídas da região indicada pelo `pRgn`.  
  
- **RGN_OR** a nova região de recorte combina a região de recorte atual e a região identificado por `pRgn`.  
  
- **RGN_XOR** a nova região de recorte combina a região de recorte atual e a região identificado por `pRgn` , mas exclui as áreas sobrepostas.  
  
### <a name="return-value"></a>Valor de retorno  
 Tipo da região. Ele pode ser qualquer um dos seguintes valores:  
  
- **COMPLEXREGION** nova região de recorte tiver bordas de sobreposição.  
  
- **Erro** contexto de dispositivo ou a região não é válido.  
  
- **NULLREGION** nova região de recorte está vazio.  
  
- **SIMPLEREGION** nova região de recorte tem sem bordas sobrepostas.  
  
### <a name="remarks"></a>Comentários  
 Apenas uma cópia da região selecionada é usada. A região em si pode ser selecionada para qualquer número de outros contextos de dispositivo, ou ele pode ser excluído.  
  
 A função pressupõe que as coordenadas de determinada região são especificadas em unidades de dispositivo. Alguns dispositivos de impressora oferecer suporte a saída de texto em uma resolução mais alta que a saída de gráficos para manter a precisão necessária para expressar as métricas de texto. Esses dispositivos relatam unidades de dispositivo com a resolução mais alta, ou seja, em unidades de texto. Esses dispositivos, em seguida, dimensionar coordenadas para elementos gráficos para que várias reportadas mapa de unidades de dispositivo para apenas 1 unidade gráfica. Você sempre deve chamar o `SelectClipRgn` função usando unidades de texto.  
  
 Os aplicativos que precisam de dimensionamento de objetos gráficos a GDI podem usar o **GETSCALINGFACTOR** escape de impressora para determinar o fator de escala. O fator de dimensionamento afeta recorte. Se uma região é usada para recortar gráficos, GDI divide as coordenadas pelo fator de dimensionamento. Se a região é usada para recortar texto, GDI não faz nenhum ajuste de escala. Um fator de escala de 1 faz com que as coordenadas seja dividido por 2; um fator de dimensionamento de 2 faz com que as coordenadas seja dividido por 4; e assim por diante.  
  
##  <a name="a-nameselectobjecta--cdcselectobject"></a><a name="selectobject"></a>CDC::SelectObject  
 Seleciona um objeto no contexto de dispositivo.  
  
```  
CPen* SelectObject(CPen* pPen);  
CBrush* SelectObject(CBrush* pBrush);  
virtual CFont* SelectObject(CFont* pFont);  
CBitmap* SelectObject(CBitmap* pBitmap);  
int SelectObject(CRgn* pRgn);  
CGdiObject* SelectObject(CGdiObject* pObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pPen*  
 Um ponteiro para um [CPen](../../mfc/reference/cpen-class.md) o objeto a ser selecionado.  
  
 `pBrush`  
 Um ponteiro para um [CBrush](../../mfc/reference/cbrush-class.md) o objeto a ser selecionado.  
  
 `pFont`  
 Um ponteiro para um [CFont](../../mfc/reference/cfont-class.md) o objeto a ser selecionado.  
  
 `pBitmap`  
 Um ponteiro para um [CBitmap](../../mfc/reference/cbitmap-class.md) o objeto a ser selecionado.  
  
 `pRgn`  
 Um ponteiro para um [CRgn](../../mfc/reference/crgn-class.md) o objeto a ser selecionado.  
  
 `pObject`  
 Um ponteiro para um [CGdiObject](../../mfc/reference/cgdiobject-class.md) o objeto a ser selecionado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o objeto que está sendo substituído. Isso é um ponteiro para um objeto de uma das classes derivadas de `CGdiObject`, como `CPen`, dependendo de qual versão da função é usada. O valor de retorno é **nulo** se houver um erro. Esta função pode retornar um ponteiro para um objeto temporário. Esse objeto temporário só é válido durante o processamento de uma mensagem do Windows. Para obter mais informações, consulte `CGdiObject::FromHandle`.  
  
 A versão da função de membro que leva um parâmetro de região executa a mesma tarefa de `SelectClipRgn` função de membro. O valor de retorno pode ser qualquer um dos seguintes:  
  
- **COMPLEXREGION** nova região de recorte tiver bordas de sobreposição.  
  
- **Erro** contexto de dispositivo ou a região não é válido.  
  
- **NULLREGION** nova região de recorte está vazio.  
  
- **SIMPLEREGION** nova região de recorte tem sem bordas sobrepostas.  
  
### <a name="remarks"></a>Comentários  
 Classe `CDC` fornece cinco versões especializadas para tipos específicos de objetos GDI, incluindo pincéis, canetas, fontes, bitmaps e regiões. O objeto recém-selecionada substitui o objeto anterior do mesmo tipo. Por exemplo, se `pObject` da versão geral do `SelectObject` aponta para uma [CPen](../../mfc/reference/cpen-class.md) do objeto, a função substitui a caneta atual com a caneta especificada por `pObject`.  
  
 Um aplicativo pode selecionar um bitmap em contextos de dispositivo de memória apenas e no contexto do dispositivo de memória de apenas um por vez. O formato do bitmap deve ser monocromático ou compatível com o contexto de dispositivo; Se não estiver, `SelectObject` retornará um erro.  
  
 Para o Windows 3.1 e posterior, o `SelectObject` função retorna o mesmo valor se ela é usada em um metarquivo ou não. Em versões anteriores do Windows, `SelectObject` retornou um valor diferente de zero para êxito e 0 para falha quando ela foi usada em um metarquivo.  
  
##  <a name="a-nameselectpalettea--cdcselectpalette"></a><a name="selectpalette"></a>CDC::SelectPalette  
 Seleciona a paleta lógica especificada pelo `pPalette` como o objeto selecionado paleta do contexto do dispositivo.  
  
```  
CPalette* SelectPalette(
    CPalette* pPalette,  
    BOOL bForceBackground);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPalette`  
 Identifica a paleta lógica a ser selecionado. Essa paleta já deve ter sido criada com o `CPalette` função de membro [CreatePalette](../../mfc/reference/cpalette-class.md#createpalette).  
  
 `bForceBackground`  
 Especifica se a paleta lógica é forçada a ser uma paleta de plano de fundo. Se `bForceBackground` é diferente de zero, a paleta selecionada é sempre uma paleta de plano de fundo, independentemente se a janela tem o foco de entrada. Se `bForceBackground` é 0 e o contexto do dispositivo é anexado a uma janela, a paleta lógica é uma paleta de primeiro plano quando a janela tem o foco de entrada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CPalette` objeto identificando a paleta lógica substituída pela paleta especificada pelo `pPalette`. É **nulo** se houver um erro.  
  
### <a name="remarks"></a>Comentários  
 A nova paleta torna-se o objeto de paleta usado pelo GDI controle cores exibidas no contexto do dispositivo e substitui a paleta anterior.  
  
 Um aplicativo pode selecionar uma paleta lógica em mais de um contexto de dispositivo. No entanto, alterações em uma paleta lógica afetará todos os contextos de dispositivo para o qual ele está selecionado. Se um aplicativo seleciona uma paleta em mais de um contexto de dispositivo, todos os contextos de dispositivo devem pertencer ao mesmo dispositivo físico.  
  
##  <a name="a-nameselectstockobjecta--cdcselectstockobject"></a><a name="selectstockobject"></a>CDC::SelectStockObject  
 Seleciona um [CGdiObject](../../mfc/reference/cgdiobject-class.md) objeto corresponde a uma das fontes, pincéis ou canetas ações predefinidas.  
  
```  
virtual CGdiObject* SelectStockObject(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o tipo de objeto de estoque desejado. Ele pode ser um dos seguintes valores:  
  
- **BLACK_BRUSH** preto pincel.  
  
- **DKGRAY_BRUSH** pincel cinza escuro.  
  
- **GRAY_BRUSH** cinza pincel.  
  
- **HOLLOW_BRUSH** vazado pincel.  
  
- **LTGRAY_BRUSH** claro pincel cinza.  
  
- **NULL_BRUSH** nulo pincel.  
  
- **WHITE_BRUSH** pincel em branco.  
  
- **BLACK_PEN** caneta preta.  
  
- **NULL_PEN** caneta Null.  
  
- **WHITE_PEN** Caneta branca.  
  
- **ANSI_FIXED_FONT** fonte de sistema fixa ANSI.  
  
- **ANSI_VAR_FONT** fonte de sistema variável ANSI.  
  
- **DEVICE_DEFAULT_FONT** fonte dependente do dispositivo.  
  
- **OEM_FIXED_FONT** fixo fonte dependente de OEM.  
  
- **SYSTEM_FONT** a fonte do sistema. Por padrão, o Windows usa a fonte do sistema para desenhar menus, controles de caixa de diálogo e outros textos. No entanto, é melhor, para não contam com SYSTEM_FONT para obter a fonte usada por caixas de diálogo e janelas. Em vez disso, use o `SystemParametersInfo` função com o parâmetro SPI_GETNONCLIENTMETRICS para recuperar a fonte atual. `SystemParametersInfo`leva em conta o tema atual e fornece informações de fonte para legendas, menus e caixas de diálogo de mensagem.  
  
- **SYSTEM_FIXED_FONT** a fonte do sistema de largura fixa usada no Windows antes da versão 3.0. Este objeto está disponível para compatibilidade com versões anteriores do Windows.  
  
- **DEFAULT_PALETTE** paleta de cores padrão. Essa paleta consiste das 20 estáticas cores na paleta do sistema.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `CGdiObject` objeto que foi substituído se a função for bem-sucedida. O objeto real apontado é um [CPen](../../mfc/reference/cpen-class.md), [CBrush](../../mfc/reference/cbrush-class.md), ou [CFont](../../mfc/reference/cfont-class.md) objeto. Se a chamada for bem-sucedida, o valor de retorno é **nulo**.  
  
##  <a name="a-namesetabortproca--cdcsetabortproc"></a><a name="setabortproc"></a>CDC:: SetAbortProc  
 Instala o procedimento abort para o trabalho de impressão.  
  
```  
int SetAbortProc(BOOL (CALLBACK* lpfn)(HDC, int));
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpfn`  
 Um ponteiro para a função abort para instalar como o procedimento de anulação. Para obter mais informações sobre a função de retorno de chamada, consulte [função de retorno de chamada para CDC:: SetAbortProc](../../mfc/reference/callback-function-for-cdc-setabortproc.md).  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o resultado do `SetAbortProc` função. Alguns dos valores a seguir são mais prováveis que outros, mas todas são possíveis.  
  
- **SP_ERROR** erro geral.  
  
- **SP_OUTOFDISK** não há espaço em disco está disponível atualmente para o spool e não há mais espaço se tornará disponível.  
  
- **SP_OUTOFMEMORY** não há memória suficiente está disponível para o spool.  
  
- **SP_USERABORT** usuário terminou o trabalho por meio do Gerenciador de impressão.  
  
### <a name="remarks"></a>Comentários  
 Se um aplicativo permitir que o trabalho de impressão a ser cancelado durante spool, ele deve definir a função abort antes do trabalho de impressão é iniciado com o [StartDoc](#startdoc) função de membro. O Gerenciador de impressão chama a função abort durante spool para permitir que o aplicativo para cancelar o trabalho de impressão ou processar condições de falta de espaço em disco. Se nenhuma função abort for definida, o trabalho de impressão falhará se não houver espaço em disco suficiente para o spool.  
  
 Observe que os recursos do Microsoft Visual C++ simplificam a criação da função de retorno de chamada passada para `SetAbortProc`. O endereço passado para o `EnumObjects` função de membro é um ponteiro para uma função exportada com **dllexport** e com o `__stdcall` convenção de chamada.  
  
 Também não é necessário exportar o nome de função em uma **exportações** declaração no arquivo de definição de módulo do aplicativo. Você pode usar o **exportar** função modificador, como em  
  
 **EXPORTAÇÃO de retorno de chamada BOOL** AFunction ( **HDC**, `int` **);**  
  
 Para fazer com que o compilador emita o registro de exportação adequado para exportação por nome sem alias. Isso funciona para a maioria das necessidades. Em alguns casos especiais, como exportar uma função por ordinal ou alias a exportação, você ainda precisa usar um **exportações** instrução em um arquivo de definição de módulo.  
  
 Interfaces de registro de retorno de chamada agora são fortemente tipadas (você deve transmitir um ponteiro de função que aponta para o tipo correto de função para o retorno de chamada específico).  
  
 Observe também que todas as funções de retorno de chamada devem interceptar exceções Microsoft Foundation antes de retornar ao Windows, como exceções não podem ser geradas em limites de retorno de chamada. Para obter mais informações sobre exceções, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
##  <a name="a-namesetarcdirectiona--cdcsetarcdirection"></a><a name="setarcdirection"></a>CDC::SetArcDirection  
 Define a direção de desenho para ser usado por funções arco e retângulo.  
  
```  
int SetArcDirection(int nArcDirection);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nArcDirection*  
 Especifica a nova direção do arco. Esse parâmetro pode ser qualquer um dos seguintes valores:  
  
- **AD_COUNTERCLOCKWISE** figuras desenhadas no sentido anti-horário.  
  
- **AD_CLOCKWISE** figuras desenhadas no sentido horário.  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica a direção do arco antigo, se for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A direção padrão é no sentido anti-horário. O `SetArcDirection` função especifica a direção na qual as seguintes funções de desenho:  
  
|Arco|Pizza|  
|---------|---------|  
|`ArcTo`|**Retângulo**|  
|`Chord`|`RoundRect`|  
|**Elipse**||  
  
##  <a name="a-namesetattribdca--cdcsetattribdc"></a><a name="setattribdc"></a>CDC::SetAttribDC  
 Chame essa função para definir o contexto de dispositivo do atributo `m_hAttribDC`.  
  
```  
virtual void SetAttribDC(HDC hDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hDC`  
 Um contexto de dispositivo do Windows.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro não anexa o contexto de dispositivo para o `CDC` objeto. Somente o contexto de dispositivo de saída é anexado a um `CDC` objeto.  
  
##  <a name="a-namesetbkcolora--cdcsetbkcolor"></a><a name="setbkcolor"></a>CDC::SetBkColor  
 Define a cor de plano de fundo atual com a cor especificada.  
  
```  
virtual COLORREF SetBkColor(COLORREF crColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 `crColor`  
 Especifica a nova cor do plano de fundo.  
  
### <a name="return-value"></a>Valor de retorno  
 A cor de plano de fundo anterior como um valor de cor RGB. Se ocorrer um erro, o valor de retorno é 0x80000000.  
  
### <a name="remarks"></a>Comentários  
 Se o modo de plano de fundo é **OPACO**, o sistema usa a cor de plano de fundo para preencher as lacunas em linhas com estilo, as lacunas entre linhas tracejadas pincéis e o plano de fundo em células de caractere. O sistema também usa a cor de plano de fundo ao converter bitmaps entre cor e contextos de dispositivo monocromático.  
  
 Se o dispositivo não pode exibir a cor especificada, o sistema define a cor de plano de fundo para a cor física mais próxima.  
  
##  <a name="a-namesetbkmodea--cdcsetbkmode"></a><a name="setbkmode"></a>CDC::SetBkMode  
 Define o modo de plano de fundo.  
  
```  
int SetBkMode(int nBkMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nBkMode*  
 Especifica o modo a ser definido. Esse parâmetro pode ser qualquer um dos seguintes valores:  
  
- **OPACO** em segundo plano é preenchido com a cor de plano de fundo atual antes do texto, o pincel tracejada, ou caneta é desenhada. Este é o modo de plano de fundo padrão.  
  
- **TRANSPARENTE** em segundo plano não é alterado antes do desenho.  
  
### <a name="return-value"></a>Valor de retorno  
 O modo de plano de fundo anterior.  
  
### <a name="remarks"></a>Comentários  
 O modo de plano de fundo define se o sistema remove as cores de plano de fundo existentes na superfície de desenho antes de desenho de texto, pincéis tracejadas ou qualquer estilo de caneta que não seja uma linha sólida.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CWnd::OnCtlColor](../../mfc/reference/cwnd-class.md#onctlcolor).  
  
##  <a name="a-namesetboundsrecta--cdcsetboundsrect"></a><a name="setboundsrect"></a>CDC::SetBoundsRect  
 Controla o acúmulo de informações de retângulo delimitador para o contexto de dispositivo especificado.  
  
```  
UINT SetBoundsRect(
    LPCRECT lpRectBounds,  
    UINT flags);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRectBounds`  
 Aponta para um `RECT` estrutura ou `CRect` objeto que é usado para definir o retângulo delimitador. As dimensões do retângulo são dadas em coordenadas lógicas. Esse parâmetro pode ser **nulo**.  
  
 `flags`  
 Especifica como o novo retângulo será combinado com o retângulo acumulado. Esse parâmetro pode ser uma combinação dos seguintes valores:  
  
- **DCB_ACCUMULATE** adiciona o retângulo especificado por `lpRectBounds` para o retângulo delimitador (usando uma operação de união do retângulo).  
  
- **DCB_DISABLE** desativar o acúmulo de limites.  
  
- **DCB_ENABLE** ativar o acúmulo de limites. (A configuração padrão de acúmulo de limites é desabilitada.)  
  
### <a name="return-value"></a>Valor de retorno  
 O estado atual do retângulo delimitador, se a função for bem-sucedida. Como `flags`, o valor de retorno pode ser uma combinação de **DCB_** valores:  
  
- **DCB_ACCUMULATE** o retângulo delimitador não está vazio. Esse valor sempre será definido.  
  
- **DCB_DISABLE** acúmulo limites está desativado.  
  
- **DCB_ENABLE** é de acumulação de limites em.  
  
### <a name="remarks"></a>Comentários  
 Windows pode manter um retângulo para todas as operações de desenho. Esse retângulo pode ser consultado e redefinir pelo aplicativo. Os limites de desenho são úteis para invalidar os caches de bitmap.  
  
##  <a name="a-namesetbrushorga--cdcsetbrushorg"></a><a name="setbrushorg"></a>CDC::SetBrushOrg  
 Especifica a origem GDI atribuirá ao próximo pincel que seleciona o aplicativo no contexto de dispositivo.  
  
```  
CPoint SetBrushOrg(
    int x,  
    int y);  
  
CPoint SetBrushOrg(POINT point);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x (em unidades de dispositivo) da nova origem. Esse valor deve estar no intervalo de 0 a 7.  
  
 *y*  
 Especifica a coordenada y (em unidades de dispositivo) da nova origem. Esse valor deve estar no intervalo de 0 a 7.  
  
 `point`  
 Especifica as coordenadas x e y da nova origem. Cada valor deve estar no intervalo de 0 a 7. Você pode passar a uma **ponto** estrutura ou um `CPoint` objeto para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 A origem anterior do pincel em unidades de dispositivo.  
  
### <a name="remarks"></a>Comentários  
 Coordena o padrão para a origem do pincel são (0, 0). Para alterar a origem de um pincel, chame o `UnrealizeObject` funcionar para o `CBrush` de objeto, chame `SetBrushOrg`e, em seguida, chame o `SelectObject` a função de membro para selecionar o pincel no contexto de dispositivo.  
  
 Não use `SetBrushOrg` com estoque `CBrush` objetos.  
  
##  <a name="a-namesetcoloradjustmenta--cdcsetcoloradjustment"></a><a name="setcoloradjustment"></a>CDC::SetColorAdjustment  
 Define os valores de ajuste de cor para o contexto de dispositivo usando os valores especificados.  
  
```  
BOOL SetColorAdjustment(const COLORADJUSTMENT* lpColorAdjust);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpColorAdjust`  
 Aponta para um [COLORADJUSTMENT](../../mfc/reference/coloradjustment-structure.md) estrutura de dados que contém os valores de ajuste de cor.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Os valores de ajuste de cor são usados para ajustar a cor de entrada do bitmap de origem das chamadas para o `CDC::StretchBlt` função de membro quando **meio-tom** modo é definido.  
  
##  <a name="a-namesetdcbrushcolora--cdcsetdcbrushcolor"></a><a name="setdcbrushcolor"></a>CDC::SetDCBrushColor  
 Define a cor do pincel de contexto (DC) dispositivo atual como o valor de cor especificada.  
  
```  
COLORREF SetDCBrushColor(COLORREF crColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 `crColor`  
 Especifica a nova cor do pincel.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função obtiver êxito, o valor de retorno Especifica a cor do pincel DC anterior como um `COLORREF` valor.  
  
 Se a função falhar, o valor de retorno é `CLR_INVALID`.  
  
### <a name="remarks"></a>Comentários  
 Esse método emula a funcionalidade da função [SetDCBrushColor](http://msdn.microsoft.com/library/windows/desktop/dd162969), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetdcpencolora--cdcsetdcpencolor"></a><a name="setdcpencolor"></a>CDC::SetDCPenColor  
 Define a cor da caneta (DC) do contexto de dispositivo atual como o valor de cor especificada.  
  
```  
COLORREF SetDCPenColor(COLORREF crColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 `crColor`  
 Especifica a nova cor da caneta.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro utiliza a função Win32 [SetDCPenColor](http://msdn.microsoft.com/library/windows/desktop/dd162970), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetgraphicsmodea--cdcsetgraphicsmode"></a><a name="setgraphicsmode"></a>CDC::SetGraphicsMode  
 Define o modo de gráfico para o contexto de dispositivo especificado.  
  
```  
int SetGraphicsMode(int iMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iMode`  
 Especifica o modo de gráficos. Para obter uma lista dos valores que esse parâmetro pode ter, consulte [SetGraphicsMode](http://msdn.microsoft.com/library/windows/desktop/dd162977).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o modo gráfico antigo com êxito.  
  
 Retorna 0 em caso de falha. Para obter mais informações sobre o erro, chame [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360).  
  
### <a name="remarks"></a>Comentários  
 Esse método encapsula a função Windows GDI [SetGraphicsMode](http://msdn.microsoft.com/library/windows/desktop/dd162977).  
  
##  <a name="a-namesetlayouta--cdcsetlayout"></a><a name="setlayout"></a>CDC::SetLayout  
 Chame essa função de membro para alterar o layout de texto e elementos gráficos para um contexto de dispositivo para a direita para esquerda, o layout padrão para culturas, como árabe e hebraico.  
  
```  
DWORD SetLayout(DWORD dwLayout);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwLayout`  
 Sinalizadores de controle de layout de contexto de dispositivo e de bitmap. Pode ser uma combinação dos valores a seguir.  
  
|Valor|Significado|  
|-----------|-------------|  
|LAYOUT_BITMAPORIENTATIONPRESERVED|Desativa qualquer reflexão para chamadas para [CDC::BitBlt](#bitblt) e [CDC::StretchBlt](#stretchblt).|  
|LAYOUT_RTL|Define o layout horizontal padrão como da direita para a esquerda.|  
|LAYOUT_LTR|Define o layout padrão para ser da esquerda para a direita.|  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, o layout anterior do contexto do dispositivo.  
  
 Se não houver êxito, **GDI_ERROR**. Para obter mais informações sobre o erro, chame [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360).  
  
### <a name="remarks"></a>Comentários  
 Normalmente, você não poderia chamar **SetLayout** para uma janela. Em vez disso, você pode controlar o layout da direita para a esquerda em uma janela, definindo o [janela estilos estendidos](../../mfc/reference/extended-window-styles.md) como **WS_EX_RTLREADING**. Um contexto de dispositivo, como uma impressora ou um metarquivo não herdará esse layout. A única maneira de definir o contexto de dispositivo para um layout da direita para a esquerda é chamando **SetLayout**.  
  
 Se você chamar **SetLayout (LAYOUT_RTL** ), **SetLayout** altera automaticamente o modo de mapeamento para `MM_ISOTROPIC`. Como resultado, uma chamada subsequente para [GetMapMode](#getmapmode) retornará **MM_ISOTROPIC** em vez de `MM_TEXT`.  
  
 Em alguns casos, como com muitos bitmaps, você talvez queira preservar o layout da esquerda para a direita. Nesses casos, processar a imagem chamando `BitBlt` ou `StretchBlt`, em seguida, defina o sinalizador de controle de bitmap para `dwLayout` para **LAYOUT_BITMAPORIENTATIONPRESERVED**.  
  
 Depois que você alterar o layout com o **LAYOUT_RTL** sinalizar os sinalizadores que especificam normalmente direita ou esquerda são revertidas. Para evitar confusão, convém definir nomes alternativos para os sinalizadores padrão. Para obter uma lista de nomes de sinalizador alternativas sugeridas, consulte [SetLayout](http://msdn.microsoft.com/library/windows/desktop/dd162979) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetmapmodea--cdcsetmapmode"></a><a name="setmapmode"></a>CDC::SetMapMode  
 Define o modo de mapeamento.  
  
```  
virtual int SetMapMode(int nMapMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMapMode`  
 Especifica o novo modo de mapeamento. Ele pode ser qualquer um dos seguintes valores:  
  
- `MM_ANISOTROPIC`Unidades lógicas são convertidas em unidades arbitrárias com eixos arbitrariamente dimensionados. Definir o modo de mapeamento para `MM_ANISOTROPIC` não altera as configurações atuais de janela ou o visor. Para alterar as unidades, orientação e dimensionamento, chamam o [SetWindowExt](#setwindowext) e [SetViewportExt](#setviewportext) funções de membro.  
  
- `MM_HIENGLISH`Cada unidade lógica é convertida em 0,001 pol. X positivo é para a direita; é positivo y.  
  
- `MM_HIMETRIC`Cada unidade lógica é convertida em milímetro 0,01. X positivo é para a direita; é positivo y.  
  
- `MM_ISOTROPIC`Unidades lógicas são convertidas em unidades arbitrárias com igualmente os eixos de escala; ou seja, 1 unidade ao longo do eixo x é igual a 1 unidade ao longo do eixo y. Use o `SetWindowExt` e `SetViewportExt` funções de membro para especificar as unidades desejadas e a orientação dos eixos. GDI faz ajustes conforme necessário para garantir que o x e y unidades permanecerem o mesmo tamanho.  
  
- `MM_LOENGLISH`Cada unidade lógica é convertida em 0,01 polegada. X positivo é para a direita; é positivo y.  
  
- `MM_LOMETRIC`Cada unidade lógica é convertida em milímetro 0,1. X positivo é para a direita; é positivo y.  
  
- `MM_TEXT`Cada unidade lógica é convertida em pixel 1 dispositivo. X positivo é para a direita; y positivo está inativo.  
  
- `MM_TWIPS`Cada unidade lógica é convertida em 1/20 de um ponto. (Como um ponto é 1/72 de polegada, um twip é 1/1440 de polegada). X positivo é para a direita; é positivo y.  
  
### <a name="return-value"></a>Valor de retorno  
 O modo de mapeamento anterior.  
  
### <a name="remarks"></a>Comentários  
 O modo de mapeamento define a unidade de medida usada para converter unidades lógicas em unidades de dispositivo; Ele também define a orientação do dispositivo x e y. GDI usa o modo de mapeamento para converter coordenadas lógicas para as coordenadas de dispositivo apropriados. O `MM_TEXT` modo permite que os aplicativos funcionam em pixels do dispositivo, onde 1 unidade é igual a 1 pixel. O tamanho físico de um pixel varia de dispositivo.  
  
 O `MM_HIENGLISH`, `MM_HIMETRIC`, `MM_LOENGLISH`, `MM_LOMETRIC`, e `MM_TWIPS` modos são úteis para aplicativos que devem desenhar em unidades fisicamente significativas (como polegadas ou milímetros). O `MM_ISOTROPIC` modo garante uma proporção de 1:1, que é útil quando é importante preservar a forma exata de uma imagem. O `MM_ANISOTROPIC` modo permite que as coordenadas x e y sejam ajustados de forma independente.  
  
> [!NOTE]
>  Se você chamar [SetLayout](#setlayout) para alterar o controlador de domínio (contexto de dispositivo) para o layout da direita para esquerda, **SetLayout** altera automaticamente o modo de mapeamento para `MM_ISOTROPIC`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CView::OnPrepareDC](../../mfc/reference/cview-class.md#onpreparedc).  
  
##  <a name="a-namesetmapperflagsa--cdcsetmapperflags"></a><a name="setmapperflags"></a>CDC::SetMapperFlags  
 Altera o método usado pelo mapeador de fonte ao converter uma fonte lógica para uma fonte física.  
  
```  
DWORD SetMapperFlags(DWORD dwFlag);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwFlag`  
 Especifica se o mapeador de fonte tenta corresponder a altura de aspecto da fonte e a largura do dispositivo. Quando esse valor é **ASPECT_FILTERING**, o mapeador seleciona apenas fontes cujo aspecto x e y aspecto correspondam exatamente às informações do dispositivo especificado.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor anterior do sinalizador mapeador de fonte.  
  
### <a name="remarks"></a>Comentários  
 Um aplicativo pode usar `SetMapperFlags` para fazer com que o mapeador de fonte tentar escolher apenas uma fonte física que corresponda exatamente à taxa de proporção do dispositivo especificado.  
  
 Um aplicativo que usa apenas as fontes de varredura pode usar o `SetMapperFlags` função para garantir que a fonte selecionada pelo mapeador de fonte é atraente e legível no dispositivo especificado. Aplicativos que usam fontes (TrueType) escalonáveis normalmente não use `SetMapperFlags`.  
  
 Se nenhuma fonte físico tem uma taxa de proporção que corresponda à especificação na fonte lógica, GDI escolhe uma nova taxa de proporção e seleciona uma fonte compatível com essa nova taxa de proporção.  
  
##  <a name="a-namesetmiterlimita--cdcsetmiterlimit"></a><a name="setmiterlimit"></a>CDC::SetMiterLimit  
 Define o limite para o comprimento do mitre associações para o contexto de dispositivo.  
  
```  
BOOL SetMiterLimit(float fMiterLimit);
```  
  
### <a name="parameters"></a>Parâmetros  
 *fMiterLimit*  
 Especifica o novo limite de Malhete para o contexto de dispositivo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O comprimento do mitre é definido como a distância entre a interseção das paredes linha dentro da associação e a interseção das paredes linha na parte externa da junção. O limite de mitre é a taxa máxima permitida do comprimento do mitre à largura da linha. O limite de Malhete padrão é 10.0.  
  
##  <a name="a-namesetoutputdca--cdcsetoutputdc"></a><a name="setoutputdc"></a>CDC::SetOutputDC  
 Chame essa função de membro para definir o contexto de dispositivo de saída, `m_hDC`.  
  
```  
virtual void SetOutputDC(HDC hDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hDC`  
 Um contexto de dispositivo do Windows.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro só pode ser chamada quando um contexto de dispositivo não foi anexado para o `CDC` objeto. Essa função de membro define `m_hDC` mas não anexa o contexto de dispositivo para o `CDC` objeto.  
  
##  <a name="a-namesetpixela--cdcsetpixel"></a><a name="setpixel"></a>CDC::SetPixel  
 Define o pixel no ponto especificado para a aproximação mais próxima da cor especificada pelo `crColor`.  
  
```  
COLORREF SetPixel(
    int x,  
    int y,  
    COLORREF crColor);

 
COLORREF SetPixel(
    POINT point,  
    COLORREF crColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica do ponto a ser definido.  
  
 *y*  
 Especifica a coordenada y lógica do ponto a ser definido.  
  
 `crColor`  
 A **COLORREF** valor RGB que especifica a cor usada para pintar o ponto. Consulte [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma descrição desse valor.  
  
 `point`  
 Especifica a lógica coordenadas x e y-do ponto a ser definido. Você pode passar a uma **ponto** estrutura ou um `CPoint` objeto para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor RGB da cor que o ponto realmente é pintado. Esse valor pode ser diferente do especificado pelo `crColor` se uma aproximação da cor é usada. Se a função falhar (se o ponto está fora da região de recorte), o valor de retorno será –&1;.  
  
### <a name="remarks"></a>Comentários  
 O ponto deve estar na região de recorte. Se o ponto não está na região de recorte, a função não faz nada.  
  
 Nem todos os dispositivos oferecem suporte à função `SetPixel`. Para determinar se um dispositivo oferece suporte a `SetPixel`, chamar o `GetDeviceCaps` a função de membro com o **RASTERCAPS** índice e verificar o valor de retorno para o **RC_BITBLT** sinalizador.  
  
##  <a name="a-namesetpixelva--cdcsetpixelv"></a><a name="setpixelv"></a>CDC::SetPixelV  
 Define o pixel nas coordenadas especificadas para a aproximação mais próxima da cor especificada.  
  
```  
BOOL SetPixelV(
    int x,  
    int y,  
    COLORREF crColor);

 
BOOL SetPixelV(
    POINT point,  
    COLORREF crColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x em unidades lógicas, do ponto a ser definido.  
  
 *y*  
 Especifica a coordenada y em unidades lógicas, do ponto a ser definido.  
  
 `crColor`  
 Especifica a cor a ser usado para pintar o ponto.  
  
 `point`  
 Especifica a lógica coordenadas x e y-do ponto a ser definido. Você pode passar a uma [ponto](../../mfc/reference/point-structure1.md) estrutura de dados ou um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O ponto deve estar na região de recorte e a parte visível da superfície do dispositivo. Nem todos os dispositivos oferecem suporte a função de membro. Para obter mais informações, consulte o **RC_BITBLT** funcionalidade de `CDC::GetDeviceCaps` função de membro. `SetPixelV`é mais rápido que `SetPixel` porque ele não precisa retornar o valor de cor do ponto realmente pintado.  
  
##  <a name="a-namesetpolyfillmodea--cdcsetpolyfillmode"></a><a name="setpolyfillmode"></a>CDC::SetPolyFillMode  
 Define o modo de preenchimento de polígono.  
  
```  
int SetPolyFillMode(int nPolyFillMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPolyFillMode`  
 Especifica o novo modo de preenchimento. Esse valor pode ser **alternativo** ou **ENROLAMENTO**. O modo padrão definido no Windows é **alternativo**.  
  
### <a name="return-value"></a>Valor de retorno  
 O modo de preenchimento anterior, se for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Quando o modo de preenchimento de polígono é **alternativo**, o sistema preenche a área entre os lados do polígono ímpares e pares em cada linha de verificação. Ou seja, o sistema preenche a área entre o primeiro e o segundo lado, entre o terceiro e quarto lado e assim por diante. Esse modo é o padrão.  
  
 Quando o modo de preenchimento de polígono é **ENROLAMENTO**, o sistema usa a direção na qual uma figura foi desenhada para determinar se deve preencher uma área. Cada segmento de linha em um polígono é desenhado em um sentido horário ou sentido anti-horário. Sempre que uma linha imaginária desenhada a partir de uma área fechada para fora de uma figura que passa por um segmento de linha no sentido horário, uma contagem é incrementada. Quando a linha passa por um segmento de linha no sentido anti-horário, a contagem é diminuída. A área é preenchida se a contagem for diferente de zero quando a linha alcança a parte externa da figura.  
  
##  <a name="a-namesetrop2a--cdcsetrop2"></a><a name="setrop2"></a>CDC::SetROP2  
 Define o modo de desenho atual.  
  
```  
int SetROP2(int nDrawMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nDrawMode`  
 Especifica o novo modo de desenho. Ele pode ser qualquer um dos seguintes valores:  
  
- **R2_BLACK** Pixel sempre é preto.  
  
- **R2_WHITE** Pixel é sempre branca.  
  
- **R2_NOP** Pixel permanece inalterado.  
  
- **R2_NOT** Pixel é o inverso da cor da tela.  
  
- **R2_COPYPEN** Pixel é a cor da caneta.  
  
- **R2_NOTCOPYPEN** Pixel é o inverso da cor da caneta.  
  
- **R2_MERGEPENNOT** Pixel é uma combinação da cor da caneta e o inverso da cor da tela (final do pixel = (não pixels da tela) ou caneta).  
  
- **R2_MASKPENNOT** Pixel é uma combinação das cores comuns para a caneta e o inverso da tela (final do pixel = (não pixels da tela) e caneta).  
  
- **R2_MERGENOTPEN** Pixel é uma combinação da cor da tela e o inverso da cor da caneta (final do pixel = (não caneta) ou tela pixel).  
  
- **R2_MASKNOTPEN** Pixel é uma combinação das cores comuns para a tela e o inverso da caneta (final do pixel = (não caneta) e tela pixel).  
  
- **R2_MERGEPEN** Pixel é uma combinação da cor da caneta e a cor da tela (final do pixel = pixel de tela ou caneta).  
  
- **R2_NOTMERGEPEN** Pixel é o inverso do **R2_MERGEPEN** cor (final do pixel = não (pixel de tela ou caneta)).  
  
- **R2_MASKPEN** Pixel é uma combinação das cores comuns à caneta e a tela (final do pixel = pixel da tela e caneta).  
  
- **R2_NOTMASKPEN** Pixel é o inverso de **R2_MASKPEN** cor (final do pixel = não (pixel da tela e da caneta)).  
  
- **R2_XORPEN** Pixel é uma combinação das cores da caneta na tela, mas não em ambos (final do pixel = pixel de tela XOR de caneta).  
  
- **R2_NOTXORPEN** Pixel é o inverso de **R2_XORPEN** cor (final do pixel = não (pixel de tela XOR de caneta)).  
  
### <a name="return-value"></a>Valor de retorno  
 O modo de desenho anterior.  
  
 Pode ser qualquer um dos valores fornecidos na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 O modo de desenho Especifica como as cores da caneta e o interior do objetos preenchidos são combinados com a cor já na superfície de exibição.  
  
 O modo de desenho é para dispositivos de varredura. ele não se aplica a dispositivos de vetor. Modos de desenho são códigos de operação de varredura binário que representa todas as combinações possíveis de Boolianas de duas variáveis, usando os operadores binários AND, OR e XOR (ou exclusivo) e operação unária não.  
  
##  <a name="a-namesetstretchbltmodea--cdcsetstretchbltmode"></a><a name="setstretchbltmode"></a>CDC::SetStretchBltMode  
 Define o modo de alongamento de bitmap para a `StretchBlt` função de membro.  
  
```  
int SetStretchBltMode(int nStretchMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nStretchMode*  
 Especifica o modo de alongamento. Ele pode ser qualquer um dos seguintes valores:  
  
|Valor|Descrição|  
|-----------|-----------------|  
|**BLACKONWHITE**|Executa uma operação booleana e usando os valores de cor para os pixels serão eliminados e existentes. Se o bitmap for um bitmap monocromático, esse modo preserva pixels pretos às custas de pixels brancos.|  
|**COLORONCOLOR**|Exclui os pixels. Esse modo exclui eliminadas todas as linhas de pixels sem tentar preservar suas informações.|  
|**MEIO-TOM**|Mapeia os pixels do retângulo de origem em blocos de pixels no retângulo de destino. A cor média sobre o bloco de destino de pixels aproxima a cor dos pixels de origem.|  
||Depois de definir o **meio-tom** alongando modo, um aplicativo deve chamar a função Win32 [SetBrushOrgEx](http://msdn.microsoft.com/library/windows/desktop/dd162967) para definir a origem do pincel. Se ele não fizer isso, ocorrerá desalinhamento de pincel.|  
|**STRETCH_ANDSCANS**|**Windows 95/98**: igual **BLACKONWHITE**|  
|**STRETCH_DELETESCANS**|**Windows 95/98**: igual **COLORONCOLOR**|  
|**STRETCH_HALFTONE**|**Windows 95/98**: igual **meio-tom**.|  
|**STRETCH_ORSCANS**|**Windows 95/98**: igual **WHITEONBLACK**|  
|**WHITEONBLACK**|Executa uma operação booleana ou usando os valores de cor para os pixels serão eliminados e existentes. Se o bitmap for um bitmap monocromático, esse modo preserva brancos às custas de pixels pretos.|  
  
### <a name="return-value"></a>Valor de retorno  
 O modo de alongamento anterior. Ele pode ser **STRETCH_ANDSCANS**, **STRETCH_DELETESCANS**, ou **STRETCH_ORSCANS**.  
  
### <a name="remarks"></a>Comentários  
 O modo de alongamento bitmap define como as informações são removidas do bitmaps que são compactadas usando a função.  
  
 O **BLACKONWHITE** ( **STRETCH_ANDSCANS**) e **WHITEONBLACK** ( **STRETCH_ORSCANS**) modos normalmente são usados para preservar os pixels do primeiro plano em bitmaps monocromático. O **COLORONCOLOR** ( **STRETCH_DELETESCANS**) modo é normalmente usado para preservar a cor em bitmaps de cor.  
  
 O **meio-tom** modo requer mais processamento da imagem de origem que os outros três modos; é menor do que os outros, mas produz imagens em melhor qualidade. Observe também que **SetBrushOrgEx** deve ser chamado depois de definir o **meio-tom** modo para evitar desalinhamento de pincel.  
  
 Modos de alongamento adicionais também podem estar disponíveis dependendo dos recursos do driver de dispositivo.  
  
##  <a name="a-namesettextaligna--cdcsettextalign"></a><a name="settextalign"></a>CDC::SetTextAlign  
 Define os sinalizadores de alinhamento de texto.  
  
```  
UINT SetTextAlign(UINT nFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nFlags`  
 Especifica os sinalizadores de alinhamento de texto. Os sinalizadores de especificam a relação entre um ponto e um retângulo que circunda o texto. O ponto pode ser coordenadas especificadas por uma função de saída de texto ou a posição atual. O retângulo que circunda o texto é definido pelas células adjacentes caractere na cadeia de texto. O `nFlags` parâmetro pode ser um ou mais sinalizadores de três categorias a seguir. Escolha apenas um sinalizador de cada categoria. A primeira categoria afeta o alinhamento do texto na direção x:  
  
- **TA_CENTER** alinha o ponto com o centro horizontal do retângulo delimitador.  
  
- **TA_LEFT** alinha o ponto com o lado esquerdo do retângulo delimitador. Essa é a configuração padrão.  
  
- **TA_RIGHT** alinha o ponto ao lado direito do retângulo delimitador.  
  
 A segunda categoria afeta o alinhamento do texto na direção y:  
  
- **TA_BASELINE** alinha o ponto na linha de base da fonte escolhida.  
  
- **TA_BOTTOM** alinha o ponto na parte inferior do retângulo delimitador.  
  
- **TA_TOP** alinha o ponto na parte superior do retângulo delimitador. Essa é a configuração padrão.  
  
 A terceira categoria determina se a posição atual é atualizada quando o texto é escrito:  
  
- **TA_NOUPDATECP** não atualizar a posição atual após cada chamada para uma função de saída de texto. Essa é a configuração padrão.  
  
- **TA_UPDATECP** atualiza a posição x atual após cada chamada para uma função de saída de texto. A nova posição é à direita do retângulo delimitador do texto. Quando esse sinalizador estiver definido, as coordenadas especificadas em chamadas para o `TextOut` função de membro são ignorados.  
  
### <a name="return-value"></a>Valor de retorno  
 A alinhamento do texto configuração anterior, se for bem-sucedido. O byte de ordem inferior contém a configuração horizontal e o byte de ordem superior contém a definição vertical; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `TextOut` e `ExtTextOut` funções de membro usem esses sinalizadores ao posicionar uma cadeia de caracteres de texto em um dispositivo ou exibição. Os sinalizadores de especificam a relação entre um ponto específico e um retângulo que circunda o texto. As coordenadas desse ponto são passadas como parâmetros para o `TextOut` função de membro. O retângulo que circunda o texto é formado pelas células adjacentes caractere na cadeia de texto.  
  
##  <a name="a-namesettextcharacterextraa--cdcsettextcharacterextra"></a><a name="settextcharacterextra"></a>CDC::SetTextCharacterExtra  
 Define a quantidade de espaçamento intercharacter.  
  
```  
int SetTextCharacterExtra(int nCharExtra);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nCharExtra`  
 Especifica a quantidade de espaço extra (em unidades lógicas) para ser adicionado a cada caractere. Se o modo de mapeamento atual não for `MM_TEXT`, `nCharExtra` é transformada e arredondado para o pixel mais próximo.  
  
### <a name="return-value"></a>Valor de retorno  
 A quantidade de espaço intercharacter anterior.  
  
### <a name="remarks"></a>Comentários  
 GDI adiciona esse espaçamento para cada caractere, incluindo caracteres de quebra, quando ele grava uma linha de texto para o contexto do dispositivo. O valor padrão para a quantidade de espaçamento intercharacter é 0.  
  
##  <a name="a-namesettextcolora--cdcsettextcolor"></a><a name="settextcolor"></a>CDC::SetTextColor  
 Define a cor do texto com a cor especificada.  
  
```  
virtual COLORREF SetTextColor(COLORREF crColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 `crColor`  
 Especifica a cor do texto como um valor de cor RGB.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor RGB da cor de texto anterior.  
  
### <a name="remarks"></a>Comentários  
 O sistema usará a cor de texto ao gravar texto nesse contexto de dispositivo e também quando bitmaps converter entre cores e contextos de dispositivo monocromático.  
  
 Se o dispositivo não pode representar a cor especificada, o sistema define a cor do texto para a cor física mais próxima. A cor de plano de fundo para um caractere for especificada o `SetBkColor` e `SetBkMode` funções de membro.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CWnd::OnCtlColor](../../mfc/reference/cwnd-class.md#onctlcolor).  
  
##  <a name="a-namesettextjustificationa--cdcsettextjustification"></a><a name="settextjustification"></a>CDC::SetTextJustification  
 Adiciona espaço para os caracteres de quebra em uma cadeia de caracteres.  
  
```  
int SetTextJustification(
    int nBreakExtra,  
    int nBreakCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBreakExtra`  
 Especifica o total de espaço extra a ser adicionado à linha de texto (em unidades lógicas). Se o modo de mapeamento atual não for `MM_TEXT`, o valor fornecido por esse parâmetro é convertido para o modo de mapeamento atual e arredondado para a unidade mais próxima do dispositivo.  
  
 *nBreakCount*  
 Especifica o número de caracteres de quebra na linha.  
  
### <a name="return-value"></a>Valor de retorno  
 1 se a função for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um aplicativo pode usar o `GetTextMetrics` caractere de quebra de funções de membro para recuperar uma fonte.  
  
 Após o `SetTextJustification` função de membro é chamado, uma chamada para uma função de saída de texto (como `TextOut`) distribui o espaço extra especificado uniformemente entre o número especificado de caracteres de quebra. O caractere de quebra geralmente é o caractere de espaço (ASCII 32), mas pode ser definido por uma fonte como qualquer outro caractere.  
  
 A função de membro `GetTextExtent` normalmente é usado com `SetTextJustification`. `GetTextExtent`calcula a largura de uma determinada linha antes de alinhamento. Um aplicativo pode determinar a quantidade de espaço para especificar no `nBreakExtra` parâmetro subtraindo o valor retornado por `GetTextExtent` da largura da cadeia de caracteres depois de alinhamento.  
  
 O `SetTextJustification` função pode ser usada para alinhar uma linha que contém a execução de várias fontes diferentes. Nesse caso, a linha deve ser criada por etapas alinhando e escrever cada execução separadamente.  
  
 Como erros de arredondamento podem ocorrer durante o alinhamento, o sistema mantém um termo de erro em execução que define o erro atual. Quando uma linha que contém várias execuções, o alinhamento `GetTextExtent` usa automaticamente esse termo de erro quando ele calcula a extensão da próxima execução. Isso permite que a função de saída de texto para o erro são mescladas com a nova execução.  
  
 Depois de cada linha tem sido alinhada, este termo de erro deve ser limpo para impedir que ele seja incorporado a próxima linha. O termo pode ser desmarcado chamando `SetTextJustification` com `nBreakExtra` definido como 0.  
  
##  <a name="a-namesetviewportexta--cdcsetviewportext"></a><a name="setviewportext"></a>CDC::SetViewportExt  
 Define as extensões x e y do visor do contexto do dispositivo.  
  
```  
virtual CSize SetViewportExt(
    int cx,  
    int cy);  
  
CSize SetViewportExt(SIZE size);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cx`  
 Especifica a extensão de x do visor (em unidades de dispositivo).  
  
 `cy`  
 Especifica a extensão de y do visor (em unidades de dispositivo).  
  
 `size`  
 Especifica as extensões x e y do visor (em unidades de dispositivo).  
  
### <a name="return-value"></a>Valor de retorno  
 As extensões anteriores do visor como um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto. Quando ocorre um erro, as coordenadas x e y do retornado `CSize` objeto são definidos como 0.  
  
### <a name="remarks"></a>Comentários  
 O visor, juntamente com a janela de contexto de dispositivo, define como GDI mapeia pontos no sistema de coordenadas lógico de pontos no sistema de coordenadas do dispositivo real. Em outras palavras, elas definem como GDI converte coordenadas lógicas em coordenadas do dispositivo.  
  
 Quando os seguintes modos de mapeamento são definidos, chamadas para `SetWindowExt` e `SetViewportExt` são ignorados:  
  
|MM_HIENGLISH|MM_LOMETRIC|  
|-------------------|------------------|  
|`MM_HIMETRIC`|`MM_TEXT`|  
|`MM_LOENGLISH`|`MM_TWIPS`|  
  
 Quando `MM_ISOTROPIC` modo é definido, um aplicativo deve chamar o `SetWindowExt` função de membro antes de chamar `SetViewportExt`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CView::OnPrepareDC](../../mfc/reference/cview-class.md#onpreparedc).  
  
##  <a name="a-namesetviewportorga--cdcsetviewportorg"></a><a name="setviewportorg"></a>CDC::SetViewportOrg  
 Define a origem do visor do contexto do dispositivo.  
  
```  
virtual CPoint SetViewportOrg(
    int x,  
    int y);  
  
CPoint SetViewportOrg(POINT point);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x (em unidades de dispositivo) da origem do visor. O valor deve ser dentro do intervalo de sistema de coordenadas do dispositivo.  
  
 *y*  
 Especifica a coordenada y (em unidades de dispositivo) da origem do visor. O valor deve ser dentro do intervalo de sistema de coordenadas do dispositivo.  
  
 `point`  
 Especifica a origem do visor. Os valores devem estar dentro do intervalo do sistema de coordenadas do dispositivo. Você pode passar a uma **ponto** estrutura ou um `CPoint` objeto para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 A origem anterior do visor (nas coordenadas do dispositivo) como um `CPoint` objeto.  
  
### <a name="remarks"></a>Comentários  
 O visor, juntamente com a janela de contexto de dispositivo, define como GDI mapeia pontos no sistema de coordenadas lógico de pontos no sistema de coordenadas do dispositivo real. Em outras palavras, elas definem como GDI converte coordenadas lógicas em coordenadas do dispositivo.  
  
 A origem do visor marca o ponto no sistema de coordenadas de dispositivo para a qual GDI mapeia a origem da janela, um ponto no sistema de coordenadas lógico especificado pelo **SetWindowOrg** função de membro. GDI mapeia todos os outros pontos, seguindo o mesmo processo necessário para mapear a origem da janela para a origem do visor. Por exemplo, todos os pontos em um círculo em torno do ponto de origem da janela será em um círculo em torno do ponto de origem do visor. Da mesma forma, todos os pontos em uma linha que passa pela origem janela estará em uma linha que passa pela origem do visor.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CView::OnPrepareDC](../../mfc/reference/cview-class.md#onpreparedc).  
  
##  <a name="a-namesetwindowexta--cdcsetwindowext"></a><a name="setwindowext"></a>CDC::SetWindowExt  
 Define as extensões x e y da janela associada ao contexto de dispositivo.  
  
```  
virtual CSize SetWindowExt(
    int cx,  
    int cy);  
  
CSize SetWindowExt(SIZE size);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cx`  
 Especifica a extensão x (em unidades lógicas) da janela.  
  
 `cy`  
 Especifica a extensão y (em unidades lógicas) da janela.  
  
 `size`  
 Especifica a x - e y-extensões (em unidades lógicas) da janela.  
  
### <a name="return-value"></a>Valor de retorno  
 As extensões anteriores da janela (em unidades lógicas) como um `CSize` objeto. Se ocorrer um erro, as coordenadas x e y do retornado `CSize` objeto são definidos como 0.  
  
### <a name="remarks"></a>Comentários  
 A janela, juntamente com o contexto de dispositivo visor, define como GDI mapeia pontos no sistema de coordenadas lógico de pontos no sistema de coordenadas de dispositivo.  
  
 Quando os seguintes modos de mapeamento são definidos, chamadas para `SetWindowExt` e `SetViewportExt` funções são ignoradas:  
  
- `MM_HIENGLISH`  
  
- `MM_HIMETRIC`  
  
- `MM_LOENGLISH`  
  
- `MM_LOMETRIC`  
  
- `MM_TEXT`  
  
- `MM_TWIPS`  
  
 Quando `MM_ISOTROPIC` modo é definido, um aplicativo deve chamar o `SetWindowExt` a função de membro antes de chamar `SetViewportExt`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CView::OnPrepareDC](../../mfc/reference/cview-class.md#onpreparedc).  
  
##  <a name="a-namesetwindoworga--cdcsetwindoworg"></a><a name="setwindoworg"></a>CDC::SetWindowOrg  
 Define a origem da janela do contexto do dispositivo.  
  
```  
CPoint SetWindowOrg(
    int x,  
    int y);  
  
CPoint SetWindowOrg(POINT point);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica da nova origem da janela.  
  
 *y*  
 Especifica a coordenada y lógica da nova origem da janela.  
  
 `point`  
 Especifica as coordenadas lógicas da nova origem da janela. Você pode passar a uma **ponto** estrutura ou um `CPoint` objeto para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 A origem anterior da janela como um `CPoint` objeto.  
  
### <a name="remarks"></a>Comentários  
 A janela, juntamente com o contexto de dispositivo visor, define como GDI mapeia pontos no sistema de coordenadas lógico de pontos no sistema de coordenadas de dispositivo.  
  
 A origem da janela marca o ponto no sistema de coordenadas lógico da qual GDI mapeia a origem do visor, um ponto no sistema de coordenadas de dispositivo especificado pelo **SetWindowOrg** função. GDI mapeia todos os outros pontos, seguindo o mesmo processo necessário para mapear a origem da janela para a origem do visor. Por exemplo, todos os pontos em um círculo em torno do ponto de origem da janela será em um círculo em torno do ponto de origem do visor. Da mesma forma, todos os pontos em uma linha que passa pela origem janela estará em uma linha que passa pela origem do visor.  
  
##  <a name="a-namesetworldtransforma--cdcsetworldtransform"></a><a name="setworldtransform"></a>CDC::SetWorldTransform  
 Define uma transformação linear bidimensional entre o espaço do mundo e página para o contexto de dispositivo especificado. Essa transformação pode ser usada para dimensionar, girar, distorcer ou converter a saída de gráficos.  
  
```  
BOOL SetWorldTransform(const XFORM& rXform);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rXform`  
 Referência a um [XFORM](http://msdn.microsoft.com/library/windows/desktop/dd145228) estrutura que contém os dados de transformação.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor diferente de zero em caso de sucesso.  
  
 Retorna 0 em caso de falha.  
  
 Para obter mais informações sobre o erro, chame [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360).  
  
### <a name="remarks"></a>Comentários  
 Esse método encapsula a função Windows GDI [SetWorldTransform](http://msdn.microsoft.com/library/windows/desktop/dd145104).  
  
##  <a name="a-namestartdoca--cdcstartdoc"></a><a name="startdoc"></a>CDC::StartDoc  
 Informa o driver de dispositivo que está iniciando um novo trabalho de impressão e que todas as demais `StartPage` e `EndPage` chamadas devem estar no spool sob o mesmo trabalho até um `EndDoc` chamada ocorre.  
  
```  
int StartDoc(LPDOCINFO lpDocInfo);  
int StartDoc(LPCTSTR lpszDocName);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpDocInfo*  
 Aponta para um [DOCINFO](http://msdn.microsoft.com/library/windows/desktop/dd183574) estrutura que contém o nome do arquivo de documento e o nome do arquivo de saída.  
  
 *lpszDocName*  
 Ponteiro para uma cadeia de caracteres que contém o nome do arquivo de documento.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função obtiver êxito, o valor de retorno é maior que zero. Esse valor é o identificador do trabalho de impressão para o documento.  
  
 Se a função falhar, o valor de retorno é menor ou igual a zero.  
  
### <a name="remarks"></a>Comentários  
 Isso garante que mais de uma página de documentos não serão ser intercalados com outros trabalhos.  
  
 Para Windows versões 3.1 e posteriores, essa função substitui a **STARTDOC** escape de impressora. Usando essa função garante que os documentos que contêm mais de uma página não são intercalados com outros trabalhos de impressão.  
  
 `StartDoc`não deve ser usado dentro de metarquivos.  
  
### <a name="example"></a>Exemplo  
 Este fragmento de código obtém a impressora padrão, abre um trabalho de impressão e coloca uma página com "Hello, World!" sobre ele. Como o texto impresso por este código não é dimensionado em unidades lógicas da impressora, o texto de saída pode ser em tais letras que o resultado é ilegível. O CDC dimensionamento funções, como `SetMapMode`, `SetViewportOrg`, e `SetWindowExt`, pode ser usado para corrigir o dimensionamento.  
  
 [!code-cpp[41 NVC_MFCDocView](../../mfc/codesnippet/cpp/cdc-class_13.cpp)]  
  
##  <a name="a-namestartpagea--cdcstartpage"></a><a name="startpage"></a>CDC::StartPage  
 Chame essa função de membro para preparar o driver de impressora para receber dados.  
  
```  
int StartPage();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Maior que ou igual a 0 se a função for bem-sucedida, ou um valor negativo se ocorreu um erro.  
  
### <a name="remarks"></a>Comentários  
 `StartPage`substitui o **NEWFRAME** e **BANDINFO** ignora.  
  
 Para obter uma visão geral da sequência de chamadas de impressão, consulte o [StartDoc](#startdoc) função de membro.  
  
 O sistema desativa o `ResetDC` a função de membro entre as chamadas para `StartPage` e `EndPage`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CDC::StartDoc](#startdoc).  
  
##  <a name="a-namestretchblta--cdcstretchblt"></a><a name="stretchblt"></a>CDC::StretchBlt  
 Copia um bitmap de um retângulo de origem em um retângulo de destino, alongando-o ou compactando-o, se necessário, para ajustá-lo às dimensões do retângulo de destino.  
  
```  
BOOL StretchBlt(
    int x,  
    int y,  
    int nWidth,  
    int nHeight,  
    CDC* pSrcDC,  
    int xSrc,  
    int ySrc,  
    int nSrcWidth,  
    int nSrcHeight,  
    DWORD dwRop);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x (em unidades lógicas) do canto esquerdo superior do retângulo de destino.  
  
 *y*  
 Especifica a coordenada y (em unidades lógicas) do canto esquerdo superior do retângulo de destino.  
  
 `nWidth`  
 Especifica a largura (em unidades lógicas) do retângulo de destino.  
  
 `nHeight`  
 Especifica a altura (em unidades lógicas) do retângulo de destino.  
  
 `pSrcDC`  
 Especifica o contexto do dispositivo de origem.  
  
 `xSrc`  
 Especifica a coordenada x (em unidades lógicas) do canto esquerdo superior do retângulo de origem.  
  
 `ySrc`  
 Especifica a coordenada y (em unidades lógicas) do canto esquerdo superior do retângulo de origem.  
  
 `nSrcWidth`  
 Especifica a largura (em unidades lógicas) do retângulo de origem.  
  
 `nSrcHeight`  
 Especifica a altura (em unidades lógicas) do retângulo de origem.  
  
 *dwRop*  
 Especifica a operação de varredura a ser executada. Os códigos da operação de varredura definem como a GDI combina cores nas operações de saída que envolvem um pincel, um possível bitmap de origem e um bitmap de destino. Esse parâmetro pode ser um dos seguintes valores:  
  
- **ESCURIDÃO** transforma toda a saída preto.  
  
- **DSTINVERT** inverte o bitmap de destino.  
  
- **MERGECOPY** combina o padrão e o bitmap de origem usando o operador booleano AND.  
  
- **MERGEPAINT** combina o bitmap de origem invertido com o bitmap de destino usando o operador OR booliano.  
  
- **NOTSRCCOPY** copia o bitmap de origem invertido no destino.  
  
- **NOTSRCERASE** inverte o resultado da combinação de bitmaps de origem e destino usando o operador OR booliano.  
  
- **PATCOPY** copia o padrão para o bitmap de destino.  
  
- **PATINVERT** combina o bitmap de destino com o padrão usando o operador XOR booliano.  
  
- **PATPAINT** combina o bitmap de origem invertido com o padrão usando o operador OR booliano. Combina o resultado dessa operação com o bitmap de destino usando o operador OR booliano.  
  
- **SRCAND** combina os pixels dos bitmaps de destino e origem usando o operador booleano AND.  
  
- **SRCCOPY** copia o bitmap de origem para o bitmap de destino.  
  
- **SRCERASE** inverte o bitmap de destino e combina o resultado com o bitmap de origem usando o operador booleano AND.  
  
- **SRCINVERT** combina os pixels dos bitmaps de origem e destino usando o operador XOR booliano.  
  
- **SRCPAINT** combina os pixels dos bitmaps de origem e destino usando o operador OR booliano.  
  
- **WHITENESS** transforma toda a saída branco.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o bitmap for desenhado; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A função usa o modo de alongamento do contexto do dispositivo de destino (definido por `SetStretchBltMode`) para determinar como alongar ou compactar o bitmap.  
  
 A função `StretchBlt` move o bitmap do dispositivo de origem fornecido por `pSrcDC` para o dispositivo de destino representado pelo objeto de contexto de dispositivo, cuja função membro está sendo chamada. Os parâmetros `xSrc`, `ySrc`, `nSrcWidth` e `nSrcHeight` definem o canto superior esquerdo e as dimensões do retângulo de origem. O *x*, *y*, `nWidth`, e `nHeight` parâmetros fornecem o canto superior esquerdo e as dimensões do retângulo de destino. A operação de varredura especificada por *dwRop* define como o bitmap de origem e os bits já no dispositivo de destino são combinados.  
  
 A função `StretchBlt` criará uma imagem espelhada de um bitmap se os sinais dos parâmetros `nSrcWidth` e `nWidth` ou `nSrcHeight` e `nHeight` forem diferentes. Se `nSrcWidth` e `nWidth` tiverem sinais diferentes, a função criará uma imagem espelhada do bitmap ao longo do eixo x. Se `nSrcHeight` e `nHeight` tiverem sinais diferentes, a função criará uma imagem espelhada do bitmap ao longo do eixo y.  
  
 A função `StretchBlt` alonga ou compacta o bitmap de origem na memória e copia o resultado no destino. Se um padrão deve ser mesclado com o resultado, ele não será mesclado até que o bitmap de origem alongado seja copiado no destino. Se um pincel for usado, é o pincel selecionado no contexto do dispositivo de destino. As coordenadas de destino são transformadas de acordo com o contexto do dispositivo de destino; as coordenadas de origem são transformadas de acordo com o contexto do dispositivo de origem.  
  
 Se os bitmaps de destino, origem e padrão não tiverem o mesmo formato de cor, `StretchBlt` converterá os bitmaps de origem e padrão para correspondência com os bitmaps de destino. As cores do primeiro plano e do plano de fundo do contexto do dispositivo de destino são usadas na conversão.  
  
 Se `StretchBlt` precisar converter um bitmap monocromático em colorido, ele definirá bits brancos (1) para a cor do plano de fundo e bits pretos (0) para a cor do primeiro plano. Para converter o colorido em monocromático, ele define pixels que correspondam à cor do plano de fundo para branco (1) e define todos os outros pixels para preto (0). As cores do primeiro plano e do plano de fundo do contexto do dispositivo com cor são usadas.  
  
 Nem todos os dispositivos oferecem suporte à função `StretchBlt`. Para determinar se um dispositivo oferece suporte a `StretchBlt`, chamar o `GetDeviceCaps` a função de membro com o **RASTERCAPS** índice e verificar o valor de retorno para o **RC_STRETCHBLT** sinalizador.  
  
##  <a name="a-namestrokeandfillpatha--cdcstrokeandfillpath"></a><a name="strokeandfillpath"></a>CDC::StrokeAndFillPath  
 Fecha qualquer figuras abertas em um caminho, traçados o contorno do caminho usando a caneta atual e preenche o interior usando o pincel atual.  
  
```  
BOOL StrokeAndFillPath();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O contexto do dispositivo deve conter um caminho fechado. O `StrokeAndFillPath` função de membro tem o mesmo efeito que fechar todas as figuras abertas no caminho e traçar e preenchendo o caminho separadamente, exceto que a região de preenchimento não se sobrepõem do mesmo se região traçadas a caneta é grande.  
  
##  <a name="a-namestrokepatha--cdcstrokepath"></a><a name="strokepath"></a>CDC::StrokePath  
 Renderiza o caminho especificado usando a caneta atual.  
  
```  
BOOL StrokePath();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O contexto do dispositivo deve conter um caminho fechado.  
  
##  <a name="a-nametabbedtextouta--cdctabbedtextout"></a><a name="tabbedtextout"></a>CDC::TabbedTextOut  
 Chame essa função de membro para gravar uma cadeia de caracteres no local especificado, expandindo o guias com os valores especificados na matriz de posições de parada de tabulação.  
  
```  
virtual CSize TabbedTextOut(
    int x,  
    int y,  
    LPCTSTR lpszString,  
    int nCount,  
    int nTabPositions,  
    LPINT lpnTabStopPositions,  
    int nTabOrigin);

 
CSize TabbedTextOut(
    int x,  
    int y,  
    const CString& str,  
    int nTabPositions,  
    LPINT lpnTabStopPositions,  
    int nTabOrigin);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica do ponto inicial da cadeia de caracteres.  
  
 *y*  
 Especifica a coordenada y lógica do ponto inicial da cadeia de caracteres.  
  
 `lpszString`  
 Aponta para a cadeia de caracteres para desenhar. Você pode passar um ponteiro para uma matriz de caracteres ou um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto para esse parâmetro.  
  
 `nCount`  
 Especifica o número de caracteres na cadeia de caracteres. Se `nCount` é –&1;, o comprimento será calculado.  
  
 `nTabPositions`  
 Especifica o número de valores na matriz de posições de parada de tabulação.  
  
 `lpnTabStopPositions`  
 Aponta para uma matriz que contém as posições de tabulação (em unidades lógicas). As paradas de tabulação devem ser classificadas em ordem; crescente o menor valor de x deve ser o primeiro item na matriz.  
  
 `nTabOrigin`  
 Especifica a coordenada x da posição inicial da qual as guias são expandidas (em unidades lógicas).  
  
 `str`  
 Um `CString` objeto que contém os caracteres especificados.  
  
### <a name="return-value"></a>Valor de retorno  
 As dimensões da cadeia de caracteres (em unidades lógicas) como um `CSize` objeto.  
  
### <a name="remarks"></a>Comentários  
 O texto é escrito na fonte atualmente selecionada. Se `nTabPositions` é 0 e `lpnTabStopPositions` é **nulo**, guias são expandidas para oito vezes a largura de caractere médio.  
  
 Se `nTabPositions` é 1, a guia paradas são separadas pela distância especificada pelo valor na primeira a `lpnTabStopPositions` matriz. Se o `lpnTabStopPositions` matriz contém mais de um valor, uma parada de tabulação é definida para cada valor na matriz, até o número especificado por `nTabPositions`. O `nTabOrigin` parâmetro permite que um aplicativo chamar o `TabbedTextOut` função várias vezes para uma única linha. Se o aplicativo chama a função mais de uma vez com o `nTabOrigin` definido como o mesmo valor de cada vez, a função expande todas as guias em relação a posição especificada pelo `nTabOrigin`.  
  
 Por padrão, a posição atual não é usada nem atualizada pela função. Se um aplicativo precisar atualizar a posição atual quando ele chama a função, o aplicativo pode chamar o [SetTextAlign](#settextalign) a função de membro com `nFlags` definida como **TA_UPDATECP**. Quando esse sinalizador estiver definido, o Windows ignora o *x* e *y* parâmetros em chamadas subsequentes para `TabbedTextOut`, usando a posição atual em vez disso.  
  
##  <a name="a-nametextouta--cdctextout"></a><a name="textout"></a>CDC::TextOut  
 Grava uma cadeia de caracteres no local especificado usando a fonte selecionada no momento.  
  
```  
virtual BOOL TextOut(
    int x,  
    int y,  
    LPCTSTR lpszString,  
    int nCount);

 
BOOL TextOut(
    int x,
    int y,
    const CString& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x lógica do ponto de partida do texto.  
  
 *y*  
 Especifica a coordenada y lógica do ponto de partida do texto.  
  
 `lpszString`  
 Aponta para a cadeia de caracteres a ser desenhada.  
  
 `nCount`  
 Especifica o número de caracteres na cadeia de caracteres.  
  
 `str`  
 Um objeto `CString` que contém os caracteres a serem desenhados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 As origens do caractere estão no canto superior esquerdo da célula do caractere. Por padrão, a posição atual não é usada nem atualizada pela função.  
  
 Se um aplicativo precisar atualizar a posição atual quando ele chama `TextOut`, o aplicativo pode chamar o `SetTextAlign` a função de membro com `nFlags` definida como **TA_UPDATECP**. Quando esse sinalizador estiver definido, o Windows ignora o *x* e *y* parâmetros em chamadas subsequentes para `TextOut`, usando a posição atual em vez disso.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CDC:: beginpath](#beginpath).  
  
##  <a name="a-nametransparentblta--cdctransparentblt"></a><a name="transparentblt"></a>CDC::TransparentBlt  
 Chame essa função de membro para transferir um bloco de bits dos dados de cor, que corresponde a um retângulo de pixels do contexto do dispositivo de origem especificada em um contexto de dispositivo de destino.  
  
```  
BOOL TransparentBlt(
    int xDest,  
    int yDest,
    int nDestWidth,
    int nDestHeight,  
    CDC* pSrcDC,  
    int xSrc,  
    int ySrc,  
    int nSrcWidth,  
    int nSrcHeight,  
    UINT clrTransparent);
```  
  
### <a name="parameters"></a>Parâmetros  
 `xDest`  
 Especifica a coordenada x em unidades lógicas, do canto superior esquerdo do retângulo de destino.  
  
 `yDest`  
 Especifica a coordenada y em unidades lógicas, do canto superior esquerdo do retângulo de destino.  
  
 `nDestWidth`  
 Especifica a largura, em unidades lógicas, do retângulo de destino.  
  
 `nDestHeight`  
 Especifica a altura, em unidades lógicas, do retângulo de destino.  
  
 `pSrcDC`  
 Ponteiro para o contexto de dispositivo de origem.  
  
 `xSrc`  
 Especifica a coordenada x em unidades lógicas, do retângulo de origem.  
  
 `ySrc`  
 Especifica a coordenada y em unidades lógicas, do retângulo de origem.  
  
 `nSrcWidth`  
 Especifica a largura, em unidades lógicas, do retângulo de origem.  
  
 `nSrcHeight`  
 Especifica a altura, em unidades lógicas, do retângulo de origem.  
  
 `clrTransparent`  
 A cor RGB no bitmap de origem a ser tratada como transparente.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se bem-sucedido; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 `TransparentBlt`permite a transparência. ou seja, a cor RGB indicado por `clrTransparent` é renderizado transparente para a transferência.  
  
 Para obter mais informações, consulte [TransparentBlt](http://msdn.microsoft.com/library/windows/desktop/dd145141) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameupdatecolorsa--cdcupdatecolors"></a><a name="updatecolors"></a>CDC::UpdateColors  
 Atualizações de cores a área do cliente do contexto do dispositivo por meio da correspondência atual na área do cliente na paleta do sistema em uma base por pixels.  
  
```  
void UpdateColors();
```  
  
### <a name="remarks"></a>Comentários  
 Uma janela inativa com uma paleta lógica realizada pode chamar `UpdateColors` como uma alternativa para redesenhar sua área cliente quando a paleta do sistema for alterada.  
  
 Para obter mais informações sobre como usar paletas de cores, consulte [UpdateColors](http://msdn.microsoft.com/library/windows/desktop/dd145166) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 O `UpdateColors` função de membro normalmente atualiza uma área de cliente mais rápido do que o redesenho da área. No entanto, como a função executa a conversão de cor com base na cor de cada pixel antes de alterar a paleta do sistema, cada chamada para essa função resulta na perda de alguns precisão de cores.  
  
##  <a name="a-namewidenpatha--cdcwidenpath"></a><a name="widenpath"></a>CDC::WidenPath  
 Redefine o caminho atual como a área que deve ser pintada se o caminho foram traçado usando a caneta atualmente selecionada no contexto de dispositivo.  
  
```  
BOOL WidenPath();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função é bem-sucedido somente se a caneta atual for uma caneta geométrica criada pela segunda versão de `CreatePen` função de membro, ou se a caneta é criada com a primeira versão do `CreatePen` e tem uma largura, em unidades de dispositivo, de maior que 1. O contexto do dispositivo deve conter um caminho fechado. Qualquer curvas Bzier no caminho são convertidas em sequências de linhas retas aproximar as curvas largo. Como tal, nenhuma curvas Bzier permanecem no caminho após `WidenPath` é chamado.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CPaintDC](../../mfc/reference/cpaintdc-class.md)   
 [Classe CWindowDC](../../mfc/reference/cwindowdc-class.md)   
 [Classe CClientDC](../../mfc/reference/cclientdc-class.md)   
 [Classe CMetaFileDC](../../mfc/reference/cmetafiledc-class.md)

