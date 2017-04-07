---
title: Classe CBrush | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CBrush
- AFXWIN/CBrush
- AFXWIN/CBrush::CBrush
- AFXWIN/CBrush::CreateBrushIndirect
- AFXWIN/CBrush::CreateDIBPatternBrush
- AFXWIN/CBrush::CreateHatchBrush
- AFXWIN/CBrush::CreatePatternBrush
- AFXWIN/CBrush::CreateSolidBrush
- AFXWIN/CBrush::CreateSysColorBrush
- AFXWIN/CBrush::FromHandle
- AFXWIN/CBrush::GetLogBrush
dev_langs:
- C++
helpviewer_keywords:
- brushes, CBrush class
- CBrush class
ms.assetid: e5ef2c62-dd95-4973-9090-f52f605900e1
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
ms.openlocfilehash: efcbe2757de3a7e4621e2b20c88726ead111cf8c
ms.lasthandoff: 02/25/2017

---
# <a name="cbrush-class"></a>Classe CBrush
Encapsula um pincel GDI (interface) do dispositivo de gráficos Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CBrush : public CGdiObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBrush::CBrush](#cbrush)|Constrói um objeto `CBrush`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBrush::CreateBrushIndirect](#createbrushindirect)|Inicializa um pincel com o estilo, cor e padrão especificado em uma [LOGBRUSH](http://msdn.microsoft.com/library/windows/desktop/dd145035) estrutura.|  
|[CBrush::CreateDIBPatternBrush](#createdibpatternbrush)|Inicializa um pincel com um padrão especificado por um bitmap independente de dispositivo (DIB).|  
|[CBrush::CreateHatchBrush](#createhatchbrush)|Inicializa um pincel com o padrão hachurado especificado e a cor.|  
|[CBrush::CreatePatternBrush](#createpatternbrush)|Inicializa um pincel com um padrão especificado por um bitmap.|  
|[CBrush::CreateSolidBrush](#createsolidbrush)|Inicializa um pincel de cor sólida especificada.|  
|[CBrush::CreateSysColorBrush](#createsyscolorbrush)|Cria um pincel de cor padrão do sistema.|  
|[CBrush::FromHandle](#fromhandle)|Retorna um ponteiro para um `CBrush` objeto quando recebe um identificador para um Windows `HBRUSH` objeto.|  
|[CBrush::GetLogBrush](#getlogbrush)|Obtém um [LOGBRUSH](http://msdn.microsoft.com/library/windows/desktop/dd145035) estrutura.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBrush::operator HBRUSH](#operator_hbrush)|Retorna o identificador anexado ao `CBrush` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Para usar um `CBrush` de objeto, construir um `CBrush` de objeto e passá-lo para qualquer `CDC` função de membro que requer um pincel.  
  
 Pincéis podem ser sólidos, hatched ou padronizado.  
  
 Para obter mais informações sobre `CBrush`, consulte [objetos gráficos](../../mfc/graphic-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CGdiObject](../../mfc/reference/cgdiobject-class.md)  
  
 `CBrush`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="cbrush"></a>CBrush::CBrush  
 Constrói um objeto `CBrush`.  
  
```  
CBrush(); 
CBrush(COLORREF crColor); 
CBrush(int nIndex, COLORREF crColor); 
explicit CBrush(CBitmap* pBitmap);
```  
  
### <a name="parameters"></a>Parâmetros  
 `crColor`  
 Especifica a cor de primeiro plano do pincel como uma cor RGB. Se o pincel for hatched, esse parâmetro especifica a cor de hachura.  
  
 `nIndex`  
 Especifica o estilo de hachura do pincel. Ele pode ser qualquer um dos seguintes valores:  
  
- `HS_BDIAGONAL`Hachura descendente (da esquerda para a direita) em 45 graus  
  
- `HS_CROSS`Hachura horizontal e vertical  
  
- `HS_DIAGCROSS`Hachura a 45 graus  
  
- `HS_FDIAGONAL`Hachura para cima (da esquerda para a direita) em 45 graus  
  
- `HS_HORIZONTAL`Hachura horizontal  
  
- `HS_VERTICAL`Hachura vertical  
  
 `pBitmap`  
 Aponta para um `CBitmap` objeto que especifica um bitmap com o qual o pincel pinta.  
  
### <a name="remarks"></a>Comentários  
 `CBrush`tem quatro sobrecarregado construtores. O construtor sem argumentos constrói uma inicializado `CBrush` objeto deve ser inicializado antes de ser usada.  
  
 Se você usar o construtor sem argumentos, você deve inicializar resultante `CBrush` o objeto com [CreateSolidBrush](#createsolidbrush), [CreateHatchBrush](#createhatchbrush), [CreateBrushIndirect](#createbrushindirect), [CreatePatternBrush](#createpatternbrush), ou [CreateDIBPatternBrush](#createdibpatternbrush). Se você usar um dos construtores que leva argumentos, em seguida, nenhuma inicialização será necessária. Os construtores com argumentos podem lançar uma exceção se forem encontrados erros, enquanto o construtor sem argumentos sempre terá êxito.  
  
 O construtor com um único [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) parâmetro constrói um pincel sólido com a cor especificada. A cor Especifica um valor RGB e pode ser construída com o `RGB` macro no WINDOWS. H.  
  
 O construtor com dois parâmetros constrói um pincel de hachura. O `nIndex` parâmetro especifica o índice de um padrão de tracejada. O `crColor` parâmetro especifica a cor.  
  
 O construtor com um `CBitmap` parâmetro constrói um pincel padronizado. O parâmetro identifica um bitmap. O bitmap é considerado tenha sido criado usando [CBitmap::CreateBitmap](../../mfc/reference/cbitmap-class.md#createbitmap), [CBitmap::CreateBitmapIndirect](../../mfc/reference/cbitmap-class.md#createbitmapindirect), [CBitmap::LoadBitmap](../../mfc/reference/cbitmap-class.md#loadbitmap), ou [CBitmap::CreateCompatibleBitmap](../../mfc/reference/cbitmap-class.md#createcompatiblebitmap). O tamanho mínimo para um bitmap a ser usado em um padrão de preenchimento é 8 pixels por 8.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#21;](../../mfc/codesnippet/cpp/cbrush-class_1.cpp)]  
  
##  <a name="createbrushindirect"></a>CBrush::CreateBrushIndirect  
 Inicializa um pincel com um estilo, cor e padrão especificado em uma [LOGBRUSH](http://msdn.microsoft.com/library/windows/desktop/dd145035) estrutura.  
  
```  
BOOL CreateBrushIndirect(const LOGBRUSH* lpLogBrush);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpLogBrush*  
 Aponta para um [LOGBRUSH](http://msdn.microsoft.com/library/windows/desktop/dd145035) estrutura que contém informações sobre o pincel.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O pincel posteriormente pode ser selecionado como o pincel atual para qualquer contexto de dispositivo.  
  
 Um pincel criado usando um bitmap monocromático (plano 1, 1 bit por pixel) é desenhado com as cores de plano de fundo e texto atuais. Pixels representados por um bit definido como 0 serão desenhados com a cor do texto. Pixels representados por um bit definido como 1 serão desenhados com a cor de plano de fundo atual.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#22;](../../mfc/codesnippet/cpp/cbrush-class_2.cpp)]  
  
##  <a name="createdibpatternbrush"></a>CBrush::CreateDIBPatternBrush  
 Inicializa um pincel com o padrão especificado por um bitmap independente de dispositivo (DIB).  
  
```  
BOOL CreateDIBPatternBrush(
    HGLOBAL hPackedDIB,  
    UINT nUsage);

 
BOOL CreateDIBPatternBrush(
    const void* lpPackedDIB,  
    UINT nUsage);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hPackedDIB*  
 Identifica um objeto de memória global que contém um pacote independente de dispositivo DIB (bitmap).  
  
 *nUsage*  
 Especifica se o **[bmiColors]** campos de [BITMAPINFO](../../mfc/reference/bitmapinfo-structure.md) estrutura de dados (parte do "empacotados DIB") contêm valores RGB ou índices explícita na paleta de lógica realizada no momento. O parâmetro deve ser um dos seguintes valores:  
  
- **DIB_PAL_COLORS** a tabela de cores consiste em uma matriz de índices de 16 bits.  
  
- **DIB_RGB_COLORS** a tabela de cores contém valores literais de RGB.  
  
 *lpPackedDIB*  
 Aponta para DIB compactada consiste em uma `BITMAPINFO` estrutura seguida imediatamente por uma matriz de bytes definindo os pixels do bitmap.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O pincel posteriormente pode ser selecionado para qualquer contexto de dispositivo que oferece suporte a operações de varredura.  
  
 As duas versões diferem no modo como tratam o DIB:  
  
-   Na primeira versão, para obter um identificador para o DIB você chamar o Windows **GlobalAlloc** função para alocar um bloco de memória global e, em seguida, preencha a memória com o DIB compactado.  
  
-   Na segunda versão, não é necessário chamar **GlobalAlloc** ao alocar memória para o DIB compactado.  
  
 Consiste em um pacote DIB um `BITMAPINFO` estrutura de dados seguida imediatamente a matriz de bytes que define os pixels do bitmap. Bitmaps usados como padrões de preenchimento deve ser 8 pixels por 8. Se o bitmap for maior, o Windows cria um padrão de preenchimento usando apenas os bits correspondentes para as primeiros 8 linhas e 8 colunas de pixels no canto superior esquerdo do bitmap.  
  
 Quando um aplicativo seleciona um pincel de padrão DIB duas cores em um contexto de dispositivo monocromático, o Windows ignora as cores especificadas no DIB e exibe em vez disso, o pincel padrão usando as cores de plano de fundo e texto atuais do contexto do dispositivo. Pixels mapeados para a primeira cor (no deslocamento 0 na tabela de cores DIB) do DIB são exibidos usando a cor do texto. Pixels mapeadas para a cor de segundo (no deslocamento 1 na tabela de cores) são exibidos usando a cor de plano de fundo.  
  
 Para obter informações sobre como usar as seguintes funções do Windows, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]:  
  
- [CreateDIBPatternBrush](http://msdn.microsoft.com/library/windows/desktop/dd183492) (esta função é fornecida somente para compatibilidade com aplicativos escritos para versões do Windows anteriores ao 3.0; use o **CreateDIBPatternBrushPt** função.)  
  
- [CreateDIBPatternBrushPt](http://msdn.microsoft.com/library/windows/desktop/dd183493) (essa função deve ser usada para aplicativos baseados no Win32.)  
  
- [GlobalAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366574)  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#23;](../../mfc/codesnippet/cpp/cbrush-class_3.cpp)]  
  
##  <a name="createhatchbrush"></a>CBrush::CreateHatchBrush  
 Inicializa um pincel com o padrão hachurado especificado e a cor.  
  
```  
BOOL CreateHatchBrush(
    int nIndex,  
    COLORREF crColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o estilo de hachura do pincel. Ele pode ser qualquer um dos seguintes valores:  
  
- `HS_BDIAGONAL`Hachura descendente (da esquerda para a direita) em 45 graus  
  
- `HS_CROSS`Hachura horizontal e vertical  
  
- `HS_DIAGCROSS`Hachura a 45 graus  
  
- `HS_FDIAGONAL`Hachura para cima (da esquerda para a direita) em 45 graus  
  
- `HS_HORIZONTAL`Hachura horizontal  
  
- `HS_VERTICAL`Hachura vertical  
  
 `crColor`  
 Especifica a cor de primeiro plano do pincel como uma cor RGB (a cor as hachuras). Consulte [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O pincel posteriormente pode ser selecionado como o pincel atual para qualquer contexto de dispositivo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#24;](../../mfc/codesnippet/cpp/cbrush-class_4.cpp)]  
  
##  <a name="createpatternbrush"></a>CBrush::CreatePatternBrush  
 Inicializa um pincel com um padrão especificado por um bitmap.  
  
```  
BOOL CreatePatternBrush(CBitmap* pBitmap);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pBitmap`  
 Identifica um bitmap.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O pincel posteriormente pode ser selecionado para qualquer contexto de dispositivo que oferece suporte a operações de varredura. O bitmap identificado por `pBitmap` normalmente é inicializado usando o [CBitmap::CreateBitmap](../../mfc/reference/cbitmap-class.md#createbitmap), [CBitmap::CreateBitmapIndirect](../../mfc/reference/cbitmap-class.md#createbitmapindirect), [CBitmap::LoadBitmap](../../mfc/reference/cbitmap-class.md#loadbitmap), ou [CBitmap::CreateCompatibleBitmap](../../mfc/reference/cbitmap-class.md#createcompatiblebitmap) função.  
  
 Bitmaps usados como padrões de preenchimento deve ser 8 pixels por 8. Se o bitmap for maior, o Windows usará apenas os bits correspondentes para os primeiros 8 linhas e colunas de pixels no canto superior esquerdo do bitmap.  
  
 Um pincel de padrão pode ser excluído sem afetar o bitmap associados. Isso significa que o bitmap pode ser usado para criar qualquer número de pincéis de padrão.  
  
 Um pincel criado usando um bitmap monocromático (plano de 1 cor, 1 bit por pixel) é desenhado com as cores de plano de fundo e texto atuais. Representado por um bit definido como 0 de pixels são desenhados com a cor do texto. Representado por um bit definido como 1 de pixels são desenhados com a cor de plano de fundo atual.  
  
 Para obter informações sobre como usar o [CreatePatternBrush](http://msdn.microsoft.com/library/windows/desktop/dd183508), uma função do Windows, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[25 NVC_MFCDocView](../../mfc/codesnippet/cpp/cbrush-class_5.cpp)]  
  
##  <a name="createsolidbrush"></a>CBrush::CreateSolidBrush  
 Inicializa um pincel com uma cor sólida especificada.  
  
```  
BOOL CreateSolidBrush(COLORREF crColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 `crColor`  
 A [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) estrutura que especifica a cor do pincel. A cor Especifica um valor RGB e pode ser construída com o `RGB` macro no WINDOWS. H.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O pincel posteriormente pode ser selecionado como o pincel atual para qualquer contexto de dispositivo.  
  
 Quando um aplicativo tiver terminado de usar o pincel criado pelo `CreateSolidBrush`, ela deve selecionar o pincel fora do contexto de dispositivo.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CBrush::CBrush](#cbrush).  
  
##  <a name="createsyscolorbrush"></a>CBrush::CreateSysColorBrush  
 Inicializa uma cor do pincel.  
  
```  
BOOL CreateSysColorBrush(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica um índice de cor. Esse valor corresponde à cor usada para pintar um dos elementos de 21 janela. Consulte [GetSysColor](http://msdn.microsoft.com/library/windows/desktop/ms724371) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma lista de valores.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O pincel posteriormente pode ser selecionado como o pincel atual para qualquer contexto de dispositivo.  
  
 Quando um aplicativo tiver terminado de usar o pincel criado pelo `CreateSysColorBrush`, ela deve selecionar o pincel fora do contexto de dispositivo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#26;](../../mfc/codesnippet/cpp/cbrush-class_6.cpp)]  
  
##  <a name="fromhandle"></a>CBrush::FromHandle  
 Retorna um ponteiro para um `CBrush` objeto quando recebe um identificador para um Windows [HBRUSH](#operator_hbrush) objeto.  
  
```  
static CBrush* PASCAL FromHandle(HBRUSH hBrush);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hBrush`  
 `HANDLE`como um pincel de GDI do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CBrush` objeto se bem-sucedido; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Se um `CBrush` objeto já não está anexado ao identificador, um temporário `CBrush` objeto é criado e anexado. Esse temporário `CBrush` objeto é válido apenas até a próxima vez que o aplicativo tem tempo ocioso em seu loop de evento. Neste momento, todos os objetos gráficos temporários são excluídos. Em outras palavras, o objeto temporário é válido somente durante o processamento da mensagem de uma janela.  
  
 Para obter mais informações sobre como usar objetos gráficos, consulte [objetos de gráfico](http://msdn.microsoft.com/library/windows/desktop/dd144962) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CBrush::CBrush](#cbrush).  
  
##  <a name="getlogbrush"></a>CBrush::GetLogBrush  
 Chame essa função de membro para recuperar o `LOGBRUSH` estrutura.  
  
```  
int GetLogBrush(LOGBRUSH* pLogBrush);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pLogBrush`  
 Aponta para um [LOGBRUSH](http://msdn.microsoft.com/library/windows/desktop/dd145035) estrutura que contém informações sobre o pincel.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função obtiver êxito, e `pLogBrush` é um ponteiro válido, o valor de retorno é o número de bytes armazenados em buffer.  
  
 Se a função obtiver êxito, e `pLogBrush` é **nulo**, o valor de retorno é o número de bytes necessários para armazenar as informações de função seria armazenar em buffer.  
  
 Se a função falhar, o valor de retorno será 0.  
  
### <a name="remarks"></a>Comentários  
 O `LOGBRUSH` estrutura define o estilo, cor e padrão de um pincel.  
  
 Por exemplo, chamar `GetLogBrush` para corresponder a cor específica ou um padrão de um bitmap.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#27;](../../mfc/codesnippet/cpp/cbrush-class_7.cpp)]  
  
##  <a name="operator_hbrush"></a>CBrush::operator HBRUSH  
 Usar esse operador para obter o identificador do Windows GDI anexado do `CBrush` objeto.  
  
```  
operator HBRUSH() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um identificador para o objeto Windows GDI representado pelo `CBrush` objeto; caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Este operador é um operador de conversão, que oferece suporte ao uso direto de um `HBRUSH` objeto.  
  
 Para obter mais informações sobre como usar objetos gráficos, consulte [objetos de gráfico](http://msdn.microsoft.com/library/windows/desktop/dd144962) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#28;](../../mfc/codesnippet/cpp/cbrush-class_8.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC PROPDLG](../../visual-cpp-samples.md)   
 [Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CBitmap](../../mfc/reference/cbitmap-class.md)   
 [Classe CDC](../../mfc/reference/cdc-class.md)

