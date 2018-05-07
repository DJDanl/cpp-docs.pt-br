---
title: Classe CBrush | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
- CBrush [MFC], CBrush
- CBrush [MFC], CreateBrushIndirect
- CBrush [MFC], CreateDIBPatternBrush
- CBrush [MFC], CreateHatchBrush
- CBrush [MFC], CreatePatternBrush
- CBrush [MFC], CreateSolidBrush
- CBrush [MFC], CreateSysColorBrush
- CBrush [MFC], FromHandle
- CBrush [MFC], GetLogBrush
ms.assetid: e5ef2c62-dd95-4973-9090-f52f605900e1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 39c5167c81d6c44fa62f9bff87c6c04f73f9f6d5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cbrush-class"></a>Classe CBrush
Encapsula um pincel GDI (interface) do dispositivo de gráficos Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CBrush : public CGdiObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBrush::CBrush](#cbrush)|Constrói um objeto `CBrush`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBrush::CreateBrushIndirect](#createbrushindirect)|Inicializa um pincel com o estilo, cor e padrão especificado em um [LOGBRUSH](http://msdn.microsoft.com/library/windows/desktop/dd145035) estrutura.|  
|[CBrush::CreateDIBPatternBrush](#createdibpatternbrush)|Inicializa um pincel com um padrão especificado por um bitmap independente de dispositivo (DIB).|  
|[CBrush::CreateHatchBrush](#createhatchbrush)|Inicializa um pincel com o padrão de hachurado especificado e a cor.|  
|[CBrush::CreatePatternBrush](#createpatternbrush)|Inicializa um pincel com um padrão especificado por um bitmap.|  
|[CBrush::CreateSolidBrush](#createsolidbrush)|Inicializa um pincel de cor sólida especificada.|  
|[CBrush::CreateSysColorBrush](#createsyscolorbrush)|Cria um pincel que é a cor padrão do sistema.|  
|[CBrush::FromHandle](#fromhandle)|Retorna um ponteiro para um `CBrush` quando é fornecido um identificador para uma janela de objeto `HBRUSH` objeto.|  
|[CBrush::GetLogBrush](#getlogbrush)|Obtém um [LOGBRUSH](http://msdn.microsoft.com/library/windows/desktop/dd145035) estrutura.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBrush::operator HBRUSH](#operator_hbrush)|Retorna o identificador anexado para o `CBrush` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Para usar um `CBrush` do objeto, construa um `CBrush` do objeto e passá-lo para qualquer `CDC` função de membro que requer um pincel.  
  
 Pincéis podem ser sólidos, hatched ou padronizado.  
  
 Para obter mais informações sobre `CBrush`, consulte [objetos gráficos](../../mfc/graphic-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CGdiObject](../../mfc/reference/cgdiobject-class.md)  
  
 `CBrush`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="cbrush"></a>  CBrush::CBrush  
 Constrói um objeto `CBrush`.  
  
```  
CBrush(); 
CBrush(COLORREF crColor); 
CBrush(int nIndex, COLORREF crColor); 
explicit CBrush(CBitmap* pBitmap);
```  
  
### <a name="parameters"></a>Parâmetros  
 `crColor`  
 Especifica a cor de primeiro plano do pincel como uma cor RGB. Se o pincel é hatched, esse parâmetro especifica a cor da hachura.  
  
 `nIndex`  
 Especifica o estilo de hachura do pincel. Ele pode ser qualquer um dos seguintes valores:  
  
- `HS_BDIAGONAL` Hachura descendente (da esquerda para a direita) em 45 graus  
  
- `HS_CROSS` Hachura horizontal e vertical  
  
- `HS_DIAGCROSS` Hachura a 45 graus  
  
- `HS_FDIAGONAL` Hachura para cima (da esquerda para a direita) em 45 graus  
  
- `HS_HORIZONTAL` Hachura horizontal  
  
- `HS_VERTICAL` Hachura vertical  
  
 `pBitmap`  
 Aponta para um `CBitmap` objeto que especifica um bitmap com a qual o pincel pinta.  
  
### <a name="remarks"></a>Comentários  
 `CBrush` tem quatro construtores de sobrecarregado. O construtor sem argumentos constrói um não inicializada `CBrush` objeto deve ser inicializado antes de ser usada.  
  
 Se você usar o construtor sem argumentos, você deverá inicializar resultante `CBrush` do objeto com [CreateSolidBrush](#createsolidbrush), [CreateHatchBrush](#createhatchbrush), [CreateBrushIndirect](#createbrushindirect), [CreatePatternBrush](#createpatternbrush), ou [CreateDIBPatternBrush](#createdibpatternbrush). Se você usar um dos construtores que obtém argumentos, em seguida, nenhuma outra inicialização será necessária. Os construtores com argumentos podem lançar uma exceção se forem encontrados erros, enquanto o construtor sem argumentos sempre terá êxito.  
  
 O construtor com um único [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) parâmetro constrói um pincel sólido com a cor especificada. A cor Especifica um valor de RGB e pode ser construída com o `RGB` macro no WINDOWS. H.  
  
 O construtor com dois parâmetros constrói um pincel de hachura. O `nIndex` parâmetro especifica o índice de um padrão de tracejada. O `crColor` parâmetro especifica a cor.  
  
 O construtor com um `CBitmap` parâmetro constrói um pincel padronizado. O parâmetro identifica um bitmap. O bitmap é assumido como foram criados usando [CBitmap::CreateBitmap](../../mfc/reference/cbitmap-class.md#createbitmap), [CBitmap::CreateBitmapIndirect](../../mfc/reference/cbitmap-class.md#createbitmapindirect), [CBitmap::LoadBitmap](../../mfc/reference/cbitmap-class.md#loadbitmap), ou [ CBitmap::CreateCompatibleBitmap](../../mfc/reference/cbitmap-class.md#createcompatiblebitmap). O tamanho mínimo para um bitmap a ser usado em um padrão de preenchimento é 8 pixels por 8.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#21](../../mfc/codesnippet/cpp/cbrush-class_1.cpp)]  
  
##  <a name="createbrushindirect"></a>  CBrush::CreateBrushIndirect  
 Inicializa um pincel com um estilo, cor e padrão especificado em um [LOGBRUSH](http://msdn.microsoft.com/library/windows/desktop/dd145035) estrutura.  
  
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
  
 Um pincel criado usando um bitmap monocromático (plano 1, 1 bit por pixel) é desenhado usando as cores de plano de fundo e texto atuais. Pixels representados por um bit definido como 0 serão desenhados com a cor do texto. Pixels representados por um bit definido como 1 serão desenhados com a cor de plano de fundo atual.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#22](../../mfc/codesnippet/cpp/cbrush-class_2.cpp)]  
  
##  <a name="createdibpatternbrush"></a>  CBrush::CreateDIBPatternBrush  
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
 Especifica se o **[bmiColors]** campos do [BITMAPINFO](../../mfc/reference/bitmapinfo-structure.md) a estrutura de dados (uma parte da "empacotadas DIB") contêm explícita valores RGB ou índices para a paleta lógica realizada no momento. O parâmetro deve ser um dos seguintes valores:  
  
- **DIB_PAL_COLORS** a tabela de cores consiste em uma matriz de índices de 16 bits.  
  
- **DIB_RGB_COLORS** a tabela de cores contém valores literais de RGB.  
  
 *lpPackedDIB*  
 Aponta para o pacote DIB consiste em um `BITMAPINFO` estrutura seguida imediatamente por uma matriz de bytes definindo os pixels do bitmap.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O pincel posteriormente pode ser selecionado para qualquer contexto de dispositivo que dá suporte a operações de varredura.  
  
 A maneira como você manipula o DIB diferem as duas versões:  
  
-   Na primeira versão, para obter um identificador para o DIB você chamar o Windows **GlobalAlloc** função para alocar um bloco de memória global e, em seguida, preencha a memória com o DIB compactado.  
  
-   Na segunda versão, não é necessário chamar **GlobalAlloc** alocar memória para o DIB compactado.  
  
 DIB compactado consiste em um `BITMAPINFO` estrutura de dados seguida imediatamente a matriz de bytes que define os pixels do bitmap. Bitmaps usados como padrões de preenchimento deve ser 8 pixels por 8. Se o bitmap for maior, o Windows cria um padrão de preenchimento usando apenas os bits correspondentes para as 8 primeiras linhas e 8 colunas de pixels no canto superior esquerdo do bitmap.  
  
 Quando um aplicativo seleciona um pincel de padrão DIB duas cores em um contexto de dispositivo monocromática, o Windows ignora as cores especificadas em de DIB e em vez disso, exibe o pincel padrão usando as cores de plano de fundo e texto atuais do contexto do dispositivo. Pixels mapeados para a primeira cor (no deslocamento de 0 na tabela de cores DIB) de DIB são exibidos usando a cor do texto. Pixels mapeados para a segunda cor (no deslocamento 1 da tabela de cores) são exibidos usando a cor do plano de fundo.  
  
 Para obter informações sobre como usar as seguintes funções do Windows, consulte o SDK do Windows:  
  
- [CreateDIBPatternBrush](http://msdn.microsoft.com/library/windows/desktop/dd183492) (esta função é fornecida somente para compatibilidade com aplicativos escritos para versões do Windows anteriores ao 3.0; use o **CreateDIBPatternBrushPt** função.)  
  
- [CreateDIBPatternBrushPt](http://msdn.microsoft.com/library/windows/desktop/dd183493) (esta função deve ser usada para aplicativos Win32.)  
  
- [GlobalAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366574)  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#23](../../mfc/codesnippet/cpp/cbrush-class_3.cpp)]  
  
##  <a name="createhatchbrush"></a>  CBrush::CreateHatchBrush  
 Inicializa um pincel com o padrão de hachurado especificado e a cor.  
  
```  
BOOL CreateHatchBrush(
    int nIndex,  
    COLORREF crColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o estilo de hachura do pincel. Ele pode ser qualquer um dos seguintes valores:  
  
- `HS_BDIAGONAL` Hachura descendente (da esquerda para a direita) em 45 graus  
  
- `HS_CROSS` Hachura horizontal e vertical  
  
- `HS_DIAGCROSS` Hachura a 45 graus  
  
- `HS_FDIAGONAL` Hachura para cima (da esquerda para a direita) em 45 graus  
  
- `HS_HORIZONTAL` Hachura horizontal  
  
- `HS_VERTICAL` Hachura vertical  
  
 `crColor`  
 Especifica a cor de primeiro plano do pincel como uma cor RGB (a cor das hachuras). Consulte [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) no SDK do Windows para obter mais informações.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O pincel posteriormente pode ser selecionado como o pincel atual para qualquer contexto de dispositivo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#24](../../mfc/codesnippet/cpp/cbrush-class_4.cpp)]  
  
##  <a name="createpatternbrush"></a>  CBrush::CreatePatternBrush  
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
 O pincel posteriormente pode ser selecionado para qualquer contexto de dispositivo que dá suporte a operações de varredura. O bitmap identificado por `pBitmap` seja geralmente inicializada usando o [CBitmap::CreateBitmap](../../mfc/reference/cbitmap-class.md#createbitmap), [CBitmap::CreateBitmapIndirect](../../mfc/reference/cbitmap-class.md#createbitmapindirect), [CBitmap::LoadBitmap](../../mfc/reference/cbitmap-class.md#loadbitmap), ou [CBitmap::CreateCompatibleBitmap](../../mfc/reference/cbitmap-class.md#createcompatiblebitmap) função.  
  
 Bitmaps usados como padrões de preenchimento deve ser 8 pixels por 8. Se o bitmap for maior, o Windows usará apenas os bits correspondentes para as 8 primeiras linhas e colunas de pixels no canto superior esquerdo do bitmap.  
  
 Um pincel de padrão pode ser excluído sem afetar o bitmap associado. Isso significa que o bitmap pode ser usado para criar qualquer número de pincéis de padrão.  
  
 Um pincel criado usando um bitmap monocromático (plano de 1 cor, 1 bit por pixel) é desenhado usando as cores de plano de fundo e texto atuais. Pixels representados por um bit definido como 0 são desenhadas com a cor do texto. Pixels representados por um bit definido como 1 são desenhadas com a cor de plano de fundo atual.  
  
 Para obter informações sobre como usar [CreatePatternBrush](http://msdn.microsoft.com/library/windows/desktop/dd183508), uma janela de função, consulte o SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#25](../../mfc/codesnippet/cpp/cbrush-class_5.cpp)]  
  
##  <a name="createsolidbrush"></a>  CBrush::CreateSolidBrush  
 Inicializa um pincel com uma cor sólida especificado.  
  
```  
BOOL CreateSolidBrush(COLORREF crColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 `crColor`  
 Um [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) estrutura que especifica a cor do pincel. A cor Especifica um valor de RGB e pode ser construída com o `RGB` macro no WINDOWS. H.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O pincel posteriormente pode ser selecionado como o pincel atual para qualquer contexto de dispositivo.  
  
 Quando um aplicativo terminar de usar o pincel criado pelo `CreateSolidBrush`, ele deve selecionar o pincel fora do contexto do dispositivo.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CBrush::CBrush](#cbrush).  
  
##  <a name="createsyscolorbrush"></a>  CBrush::CreateSysColorBrush  
 Inicializa uma cor do pincel.  
  
```  
BOOL CreateSysColorBrush(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica um índice de cor. Esse valor corresponde à cor usada para pintar um dos elementos de 21 janela. Consulte [GetSysColor](http://msdn.microsoft.com/library/windows/desktop/ms724371) no SDK do Windows para obter uma lista de valores.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O pincel posteriormente pode ser selecionado como o pincel atual para qualquer contexto de dispositivo.  
  
 Quando um aplicativo terminar de usar o pincel criado pelo `CreateSysColorBrush`, ele deve selecionar o pincel fora do contexto do dispositivo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#26](../../mfc/codesnippet/cpp/cbrush-class_6.cpp)]  
  
##  <a name="fromhandle"></a>  CBrush::FromHandle  
 Retorna um ponteiro para um `CBrush` quando é fornecido um identificador para uma janela de objeto [HBRUSH](#operator_hbrush) objeto.  
  
```  
static CBrush* PASCAL FromHandle(HBRUSH hBrush);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hBrush`  
 `HANDLE` para um pincel de Windows GDI.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CBrush` objeto se for bem-sucedida; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Se um `CBrush` objeto já não está anexado para o identificador de um temporário `CBrush` objeto é criado e anexado. Este temporário `CBrush` objeto é válido somente até a próxima vez em que o aplicativo tem tempo ocioso em seu loop de eventos. Neste momento, todos os objetos gráficos temporários são excluídos. Em outras palavras, o objeto temporário é válido somente durante o processamento da mensagem de uma janela.  
  
 Para obter mais informações sobre como usar objetos gráficos, consulte [objetos de gráfico](http://msdn.microsoft.com/library/windows/desktop/dd144962) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CBrush::CBrush](#cbrush).  
  
##  <a name="getlogbrush"></a>  CBrush::GetLogBrush  
 Chamar essa função de membro para recuperar o `LOGBRUSH` estrutura.  
  
```  
int GetLogBrush(LOGBRUSH* pLogBrush);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pLogBrush`  
 Aponta para um [LOGBRUSH](http://msdn.microsoft.com/library/windows/desktop/dd145035) estrutura que contém informações sobre o pincel.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função tiver êxito, e `pLogBrush` é um ponteiro válido, o valor de retorno é o número de bytes armazenados no buffer.  
  
 Se a função tiver êxito, e `pLogBrush` é **nulo**, o valor de retorno é o número de bytes necessários para armazenar as informações de função deve ser armazenados no buffer.  
  
 Se a função falhar, o valor de retorno será 0.  
  
### <a name="remarks"></a>Comentários  
 O `LOGBRUSH` estrutura define o estilo, cor e padrão de um pincel.  
  
 Por exemplo, chamar `GetLogBrush` para corresponder a determinada cor ou o padrão de um bitmap.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#27](../../mfc/codesnippet/cpp/cbrush-class_7.cpp)]  
  
##  <a name="operator_hbrush"></a>  CBrush::operator HBRUSH  
 Use este operador para obter o identificador de Windows GDI anexado do `CBrush` objeto.  
  
```  
operator HBRUSH() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um identificador para o objeto Windows GDI representado pelo `CBrush` objeto; caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Esse operador é um operador de conversão, que dá suporte ao uso direto de um `HBRUSH` objeto.  
  
 Para obter mais informações sobre como usar objetos gráficos, consulte [objetos de gráfico](http://msdn.microsoft.com/library/windows/desktop/dd144962) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#28](../../mfc/codesnippet/cpp/cbrush-class_8.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC PROPDLG](../../visual-cpp-samples.md)   
 [Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CBitmap](../../mfc/reference/cbitmap-class.md)   
 [Classe CDC](../../mfc/reference/cdc-class.md)
