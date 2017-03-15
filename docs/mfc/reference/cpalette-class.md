---
title: Classe CPalette | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CPalette
- HPALETTE
dev_langs:
- C++
helpviewer_keywords:
- CPalette class
- HPALETTE
- color palettes, MFC
ms.assetid: 8cd95498-53ed-4852-85e1-70e522541114
caps.latest.revision: 23
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
ms.openlocfilehash: 6ccd389eaf765993c59311cc1041893f2cf9fbfa
ms.lasthandoff: 02/25/2017

---
# <a name="cpalette-class"></a>Classe CPalette
Encapsula uma paleta de cores do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPalette : public CGdiObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPalette::CPalette](#cpalette)|Constrói uma `CPalette` objeto com nenhuma paleta Windows anexado. Você deve inicializar o `CPalette` objeto com uma das funções de membro de inicialização antes de ser usada.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPalette::AnimatePalette](#animatepalette)|Substitui as entradas na paleta lógica identificado pelo `CPalette` objeto. O aplicativo não precisa atualizar sua área de cliente, como Windows mapeia as novas entradas na paleta de sistema imediatamente.|  
|[CPalette::CreateHalftonePalette](#createhalftonepalette)|Cria uma paleta de meio-tom para o contexto de dispositivo e anexa-o para o `CPalette` objeto.|  
|[CPalette::CreatePalette](#createpalette)|Cria uma paleta de cores do Windows e anexa-o para o `CPalette` objeto.|  
|[CPalette::FromHandle](#fromhandle)|Retorna um ponteiro para um `CPalette` objeto quando recebe um identificador para um objeto de paleta do Windows.|  
|[CPalette::GetEntryCount](#getentrycount)|Recupera o número de entradas de paleta em uma paleta lógica.|  
|[CPalette::GetNearestPaletteIndex](#getnearestpaletteindex)|Retorna o índice da entrada na paleta de lógica mais parecido com um valor de cor.|  
|[CPalette::GetPaletteEntries](#getpaletteentries)|Recupera um intervalo de entradas de paleta em uma paleta lógica.|  
|[CPalette::ResizePalette](#resizepalette)|Altera o tamanho da paleta lógica especificada pelo `CPalette` objeto para o número especificado de entradas.|  
|[CPalette::SetPaletteEntries](#setpaletteentries)|Define valores de cores RGB e sinalizadores em um intervalo de entradas em uma paleta lógica.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPalette::operator HPALETTE](#operator_hpalette)|Retorna o `HPALETTE` anexado para o `CPalette`.|  
  
## <a name="remarks"></a>Comentários  
 Uma paleta fornece uma interface entre um aplicativo e um dispositivo de saída de cor (como um dispositivo de exibição). A interface permite que o aplicativo aproveitar ao máximo os recursos de cor do dispositivo de saída sem interferir seriamente as cores exibidas por outros aplicativos. O Windows usa a paleta lógica do aplicativo (uma lista de cores necessárias) e a paleta do sistema (que define as cores disponíveis) para determinar as cores usadas.  
  
 Um `CPalette` objeto fornece funções de membro para manipulação de paleta chamado pelo objeto. Construir um `CPalette` e usa as funções de membro para criar a paleta real, um objeto GDI (interface) do dispositivo de gráficos e manipular suas entradas e outras propriedades.  
  
 Para obter mais informações sobre como usar o `CPalette`, consulte [objetos gráficos](../../mfc/graphic-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CGdiObject](../../mfc/reference/cgdiobject-class.md)  
  
 `CPalette`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="a-nameanimatepalettea--cpaletteanimatepalette"></a><a name="animatepalette"></a>CPalette::AnimatePalette  
 Substitui as entradas na paleta lógica anexado para o `CPalette` objeto.  
  
```  
void AnimatePalette(
    UINT nStartIndex,  
    UINT nNumEntries,  
    LPPALETTEENTRY lpPaletteColors);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nStartIndex`  
 Especifica a primeira entrada na paleta seja animado.  
  
 `nNumEntries`  
 Especifica o número de entradas na paleta seja animado.  
  
 `lpPaletteColors`  
 Aponta para o primeiro membro de uma matriz de [PALETTEENTRY](http://msdn.microsoft.com/library/windows/desktop/dd162769) estruturas para substituir as entradas de paleta identificadas por `nStartIndex` e `nNumEntries`.  
  
### <a name="remarks"></a>Comentários  
 Quando um aplicativo chama `AnimatePalette`, ele não precisa atualizar sua área de cliente, como Windows mapeia as novas entradas na paleta de sistema imediatamente.  
  
 O `AnimatePalette` função alterará apenas entradas com o **PC_RESERVED** o sinalizador será definido no correspondente **palPaletteEntry** membro do [LOGPALETTE](http://msdn.microsoft.com/library/windows/desktop/dd145040) estrutura que está associada a `CPalette` objeto. Consulte **LOGPALETTE** no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações sobre essa estrutura.  
  
##  <a name="a-namecpalettea--cpalettecpalette"></a><a name="cpalette"></a>CPalette::CPalette  
 Constrói um objeto `CPalette`.  
  
```  
CPalette();
```  
  
### <a name="remarks"></a>Comentários  
 O objeto não tem nenhuma paleta anexada até que você chame `CreatePalette` para anexar uma.  
  
##  <a name="a-namecreatehalftonepalettea--cpalettecreatehalftonepalette"></a><a name="createhalftonepalette"></a>CPalette::CreateHalftonePalette  
 Cria uma paleta de meio-tom para o contexto de dispositivo.  
  
```  
BOOL CreateHalftonePalette(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Identifica o contexto do dispositivo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um aplicativo deve criar uma paleta de meio-tom quando o modo de alongamento de um contexto de dispositivo é definido como **meio-tom**. A paleta de meio-tom lógico retornada pelo [CreateHalftonePalette](http://msdn.microsoft.com/library/windows/desktop/dd183503) função de membro deve ser selecionada e realizada no contexto de dispositivo antes do [CDC::StretchBlt](../../mfc/reference/cdc-class.md#stretchblt) ou [StretchDIBits](http://msdn.microsoft.com/library/windows/desktop/dd145121) função é chamada.  
  
 Consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações sobre `CreateHalftonePalette` e **StretchDIBits**.  
  
##  <a name="a-namecreatepalettea--cpalettecreatepalette"></a><a name="createpalette"></a>CPalette::CreatePalette  
 Inicializa uma `CPalette` objeto criando uma paleta de cores lógicas do Windows e anexá-lo para o `CPalette` objeto.  
  
```  
BOOL CreatePalette(LPLOGPALETTE lpLogPalette);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpLogPalette`  
 Aponta para um [LOGPALETTE](http://msdn.microsoft.com/library/windows/desktop/dd145040) estrutura que contém informações sobre as cores na paleta de lógica.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações sobre o **LOGPALETTE** estrutura.  
  
##  <a name="a-namefromhandlea--cpalettefromhandle"></a><a name="fromhandle"></a>CPalette::FromHandle  
 Retorna um ponteiro para um `CPalette` objeto quando recebe um identificador para um objeto de paleta do Windows.  
  
```  
static CPalette* PASCAL FromHandle(HPALETTE hPalette);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hPalette`  
 Um identificador para uma paleta de cores do Windows GDI.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CPalette` objeto se bem-sucedido; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Se um `CPalette` objeto já não está anexado a paleta do Windows, um temporário `CPalette` objeto é criado e anexado. Esse temporário `CPalette` objeto é válido somente até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de evento, em que ponto gráfico temporário todos os objetos são excluídos. Em outras palavras, o objeto temporário é válido somente durante o processamento da mensagem de uma janela.  
  
##  <a name="a-namegetentrycounta--cpalettegetentrycount"></a><a name="getentrycount"></a>CPalette::GetEntryCount  
 Chame essa função de membro para recuperar o número de entradas em uma determinada paleta lógica.  
  
```  
int GetEntryCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Número de entradas em uma paleta lógica.  
  
##  <a name="a-namegetnearestpaletteindexa--cpalettegetnearestpaletteindex"></a><a name="getnearestpaletteindex"></a>CPalette::GetNearestPaletteIndex  
 Retorna o índice da entrada na paleta de lógica mais parecido com o valor de cor especificada.  
  
```  
UINT GetNearestPaletteIndex(COLORREF crColor) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `crColor`  
 Especifica a cor a ser correspondido.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de uma entrada em uma paleta lógica. A entrada contém a cor que mais se aproxima a cor especificada.  
  
##  <a name="a-namegetpaletteentriesa--cpalettegetpaletteentries"></a><a name="getpaletteentries"></a>CPalette::GetPaletteEntries  
 Recupera um intervalo de entradas de paleta em uma paleta lógica.  
  
```  
UINT GetPaletteEntries(
    UINT nStartIndex,  
    UINT nNumEntries,  
    LPPALETTEENTRY lpPaletteColors) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nStartIndex`  
 Especifica a primeira entrada na paleta lógica a ser recuperado.  
  
 `nNumEntries`  
 Especifica o número de entradas na paleta lógica a ser recuperado.  
  
 `lpPaletteColors`  
 Aponta para uma matriz de [PALETTEENTRY](http://msdn.microsoft.com/library/windows/desktop/dd162769) estruturas de dados para receber as entradas da paleta. A matriz deve conter pelo menos o mesmo número de estruturas de dados conforme especificado por `nNumEntries`.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de entradas recuperados da paleta lógica; 0 se a função falhou.  
  
##  <a name="a-nameoperatorhpalettea--cpaletteoperator-hpalette"></a><a name="operator_hpalette"></a>CPalette::operator HPALETTE  
 Usar esse operador para obter o identificador do Windows GDI anexado do `CPalette` objeto.  
  
```  
operator HPALETTE() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um identificador para o objeto Windows GDI representado pelo `CPalette` objeto; caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Este operador é um operador de conversão, que oferece suporte ao uso direto de um `HPALETTE` objeto.  
  
 Para obter mais informações sobre como usar objetos gráficos, consulte o artigo [objetos de gráfico](http://msdn.microsoft.com/library/windows/desktop/dd144962) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameresizepalettea--cpaletteresizepalette"></a><a name="resizepalette"></a>CPalette::ResizePalette  
 Altera o tamanho da paleta lógico anexado para o `CPalette` o número de entradas especificado pelo objeto `nNumEntries`.  
  
```  
BOOL ResizePalette(UINT nNumEntries);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nNumEntries`  
 Especifica o número de entradas na paleta depois que ele for redimensionado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a paleta foi redimensionada com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se um aplicativo chamar `ResizePalette` para reduzir o tamanho da paleta, as entradas restantes na paleta redimensionada permanecem inalteradas. Se o aplicativo chama `ResizePalette` para aumentar a paleta, as entradas de paleta adicionais são definidas para preto (os valores de vermelhos, verde e azuis são todos 0) e os sinalizadores de todas as entradas adicionais são definidos como 0.  
  
 Para obter mais informações sobre a API do Windows `ResizePalette`, consulte [ResizePalette](http://msdn.microsoft.com/library/windows/desktop/dd162928) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetpaletteentriesa--cpalettesetpaletteentries"></a><a name="setpaletteentries"></a>CPalette::SetPaletteEntries  
 Define valores de cores RGB e sinalizadores em um intervalo de entradas em uma paleta lógica.  
  
```  
UINT SetPaletteEntries(
    UINT nStartIndex,  
    UINT nNumEntries,  
    LPPALETTEENTRY lpPaletteColors);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nStartIndex`  
 Especifica a primeira entrada na paleta lógica a ser definido.  
  
 `nNumEntries`  
 Especifica o número de entradas na paleta lógica a ser definido.  
  
 `lpPaletteColors`  
 Aponta para uma matriz de [PALETTEENTRY](http://msdn.microsoft.com/library/windows/desktop/dd162769) estruturas de dados para receber as entradas da paleta. A matriz deve conter pelo menos o mesmo número de estruturas de dados conforme especificado por `nNumEntries`.  
  
### <a name="return-value"></a>Valor de retorno  
 Definir o número de entradas na paleta de lógica; 0 se a função falhou.  
  
### <a name="remarks"></a>Comentários  
 Se a paleta lógica é selecionada em um contexto de dispositivo quando o aplicativo chama `SetPaletteEntries`, as alterações não terão efeito até que o aplicativo chame [CDC::RealizePalette](../../mfc/reference/cdc-class.md#realizepalette).  
  
 Para obter mais informações sobre a estrutura do Windows **PALETTEENTRY**, consulte [PALETTEENTRY](http://msdn.microsoft.com/library/windows/desktop/dd162769) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC DIBLOOK](../../visual-cpp-samples.md)   
 [Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [CPalette::GetPaletteEntries](#getpaletteentries)   
 [CPalette::SetPaletteEntries](#setpaletteentries)




