---
title: Classe CGdiObject | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CGdiObject
- AFXWIN/CGdiObject
- AFXWIN/CGdiObject::CGdiObject
- AFXWIN/CGdiObject::Attach
- AFXWIN/CGdiObject::CreateStockObject
- AFXWIN/CGdiObject::DeleteObject
- AFXWIN/CGdiObject::DeleteTempMap
- AFXWIN/CGdiObject::Detach
- AFXWIN/CGdiObject::FromHandle
- AFXWIN/CGdiObject::GetObject
- AFXWIN/CGdiObject::GetObjectType
- AFXWIN/CGdiObject::GetSafeHandle
- AFXWIN/CGdiObject::UnrealizeObject
- AFXWIN/CGdiObject::m_hObject
dev_langs:
- C++
helpviewer_keywords:
- CGdiObject [MFC], CGdiObject
- CGdiObject [MFC], Attach
- CGdiObject [MFC], CreateStockObject
- CGdiObject [MFC], DeleteObject
- CGdiObject [MFC], DeleteTempMap
- CGdiObject [MFC], Detach
- CGdiObject [MFC], FromHandle
- CGdiObject [MFC], GetObject
- CGdiObject [MFC], GetObjectType
- CGdiObject [MFC], GetSafeHandle
- CGdiObject [MFC], UnrealizeObject
- CGdiObject [MFC], m_hObject
ms.assetid: 1cba3ba5-3d49-4e43-8293-209299f2f6f4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6749c62a5d8de0bd1da3a5d619a85a0ec874a21a
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37338412"
---
# <a name="cgdiobject-class"></a>Classe CGdiObject
Fornece uma classe base para vários tipos de gráficos do Windows em objetos de interface (GDI) do dispositivo, como bitmaps, regiões, pincéis, canetas, paletas e fontes.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CGdiObject : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CGdiObject::CGdiObject](#cgdiobject)|Constrói um objeto `CGdiObject`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CGdiObject::Attach](#attach)|Anexa um objeto de GDI do Windows para um `CGdiObject` objeto.|  
|[CGdiObject::CreateStockObject](#createstockobject)|Recupera um identificador para um do pincéis, canetas de ações predefinidas do Windows ou fontes.|  
|[CGdiObject::DeleteObject](#deleteobject)|Exclui o objeto de GDI do Windows associado a `CGdiObject` objeto da memória ao liberar todo o armazenamento de sistema associado ao objeto.|  
|[CGdiObject::DeleteTempMap](#deletetempmap)|Exclui qualquer temporário `CGdiObject` objetos criados pelo `FromHandle`.|  
|[CGdiObject::Detach](#detach)|Desanexa um objeto de GDI do Windows de um `CGdiObject` de objeto e retorna um identificador para o objeto Windows GDI.|  
|[CGdiObject::FromHandle](#fromhandle)|Retorna um ponteiro para um `CGdiObject` objeto dado um identificador para um objeto de GDI do Windows.|  
|[CGdiObject::GetObject](#getobject)|Preenche um buffer com dados que descreve o objeto Windows GDI anexado ao `CGdiObject` objeto.|  
|[CGdiObject::GetObjectType](#getobjecttype)|Recupera o tipo do objeto GDI.|  
|[CGdiObject::GetSafeHandle](#getsafehandle)|Retorna `m_hObject` , a menos que **isso** for NULL, em que o case NULL será retornado.|  
|[CGdiObject::UnrealizeObject](#unrealizeobject)|Redefine a origem de um pincel ou redefine uma paleta lógica.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CGdiObject::operator! =](#operator_neq)|Determina se dois objetos GDI logicamente não são iguais.|  
|[CGdiObject::operator = =](#operator_eq_eq)|Determina se dois objetos GDI são logicamente iguais.|  
|[CGdiObject::operator HGDIOBJ](#operator_hgdiobj)|Recupera um identificador para o objeto Windows GDI anexado.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CGdiObject::m_hObject](#m_hobject)|Um identificador que contém o HBITMAP, HPALETTE, HRGN, HBRUSH, HPEN ou HFONT anexado a este objeto.|  
  
## <a name="remarks"></a>Comentários  
 Você nunca criará um `CGdiObject` diretamente. Em vez disso, você cria um objeto de uma de suas classes derivadas, tais como `CPen` ou `CBrush`.  
  
 Para obter mais informações sobre `CGdiObject`, consulte [objetos gráficos](../../mfc/graphic-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CGdiObject`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="attach"></a>  CGdiObject::Attach  
 Anexa um objeto de GDI do Windows para um `CGdiObject` objeto.  
  
```  
BOOL Attach(HGDIOBJ hObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hObject*  
 Um identificador para um objeto do Windows GDI (por exemplo, HPEN ou HBRUSH).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o anexo for bem-sucedida; Caso contrário, 0.  
  
##  <a name="cgdiobject"></a>  CGdiObject::CGdiObject  
 Constrói um objeto `CGdiObject`.  
  
```  
CGdiObject();
```  
  
### <a name="remarks"></a>Comentários  
 Você nunca criará um `CGdiObject` diretamente. Em vez disso, você cria um objeto de uma de suas classes derivadas, tais como `CPen` ou `Cbrush`.  
  
##  <a name="createstockobject"></a>  CGdiObject::CreateStockObject  
 Recupera um identificador para uma das canetas de Windows GDI ações predefinidas, pincéis ou fontes e anexa o objeto GDI para o `CGdiObject` objeto.  
  
```  
BOOL CreateStockObject(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIndex*  
 Uma constante especificando o tipo de objeto de estoque desejado. Consulte o parâmetro *fnObject* para [GetStockObject](http://msdn.microsoft.com/library/windows/desktop/dd144925) no SDK do Windows para obter uma descrição dos valores apropriados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chamada para essa função com um dos derivados de classes que corresponde ao tipo de objeto GDI do Windows, como `CPen` para uma caneta de estoque.  
  
##  <a name="deleteobject"></a>  CGdiObject::DeleteObject  
 Exclui o objeto Windows GDI anexado da memória ao liberar todo o armazenamento de sistema associado ao objeto Windows GDI.  
  
```  
BOOL DeleteObject();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto GDI foi excluído com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O armazenamento associado a `CGdiObject` objeto não é afetado por essa chamada. Um aplicativo não deve chamar `DeleteObject` em um `CGdiObject` objeto atualmente selecionado em um contexto de dispositivo.  
  
 Quando um pincel de padrão é excluído, o bitmap associado com o pincel não é excluído. O bitmap deve ser excluído de forma independente.  
  
##  <a name="deletetempmap"></a>  CGdiObject::DeleteTempMap  
 Chamado automaticamente pelo `CWinApp` manipulador de tempo ocioso `DeleteTempMap` exclui qualquer temporário `CGdiObject` objetos criados pelo `FromHandle`.  
  
```  
static void PASCAL DeleteTempMap();
```  
  
### <a name="remarks"></a>Comentários  
 `DeleteTempMap` desanexa o objeto de GDI Windows anexado a um temporário `CGdiObject` objeto antes de excluir o `CGdiObject` objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#175](../../mfc/codesnippet/cpp/cgdiobject-class_1.cpp)]  
  
##  <a name="detach"></a>  CGdiObject::Detach  
 Desanexa um objeto de GDI do Windows de um `CGdiObject` de objeto e retorna um identificador para o objeto Windows GDI.  
  
```  
HGDIOBJ Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `HANDLE` para o Windows GDI objeto desanexado; caso contrário, nulo se nenhum objeto GDI estiver anexado.  
  
##  <a name="fromhandle"></a>  CGdiObject::FromHandle  
 Retorna um ponteiro para um `CGdiObject` objeto dado um identificador para um objeto de GDI do Windows.  
  
```  
static CGdiObject* PASCAL FromHandle(HGDIOBJ hObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hObject*  
 Um identificador para um objeto de GDI do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CGdiObject` que pode ser temporário ou permanente.  
  
### <a name="remarks"></a>Comentários  
 Se um `CGdiObject` objeto já não está anexado ao objeto GDI do Windows, um temporário `CGdiObject` objeto é criado e anexado.  
  
 Esse temporário `CGdiObject` objeto só é válido até a próxima vez que o aplicativo tem tempo ocioso em seu loop de eventos, momento em que todos os objetos gráficos temporários serão excluídos. Outra maneira de dizer isso é que o objeto temporário só é válido durante o processamento de mensagem em uma janela.  
  
##  <a name="getobject"></a>  CGdiObject::GetObject  
 Preenche um buffer com dados que define um objeto especificado.  
  
```  
int GetObject(
    int nCount,  
    LPVOID lpObject) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nCount*  
 Especifica o número de bytes a serem copiados para o *lpObject* buffer.  
  
 *lpObject*  
 Aponta para um buffer fornecido pelo usuário que receberá as informações.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de bytes recuperado. Caso contrário, 0 se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 A função recupera uma estrutura de dados cujo tipo depende do tipo de objeto de gráfico, como mostra a lista a seguir:  
  
|Objeto|Tipo de buffer|  
|------------|-----------------|  
|`CPen`|[LOGPEN](../../mfc/reference/logpen-structure.md)|  
|`CBrush`|[LOGBRUSH](../../mfc/reference/logbrush-structure.md)|  
|`CFont`|[LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037)|  
|`CBitmap`|[BITMAP](../../mfc/reference/bitmap-structure.md)|  
|`CPalette`|WORD|  
|`CRgn`|Sem suporte|  
  
 Se o objeto for um `CBitmap` objeto, `GetObject` retorna apenas a largura, altura e informações de formato de cor do bitmap. Os bits reais podem ser recuperados por meio [CBitmap::GetBitmapBits](../../mfc/reference/cbitmap-class.md#getbitmapbits).  
  
 Se o objeto for um `CPalette` objeto, `GetObject` recupera uma palavra que especifica o número de entradas da paleta. A função não recupera o [LOGPALETTE](http://msdn.microsoft.com/library/windows/desktop/dd145040) estrutura que define a paleta. Um aplicativo pode obter informações sobre as entradas da paleta chamando [CPalette::GetPaletteEntries](../../mfc/reference/cpalette-class.md#getpaletteentries).  
  
##  <a name="getobjecttype"></a>  CGdiObject::GetObjectType  
 Recupera o tipo do objeto GDI.  
  
```  
UINT GetObjectType() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tipo de objeto, se for bem-sucedido; Caso contrário, 0. O valor pode ser um dos seguintes:  
  
- Bitmap OBJ_BITMAP  
  
- Pincel OBJ_BRUSH  
  
- Fonte OBJ_FONT  
  
- Paleta OBJ_PAL  
  
- Caneta OBJ_PEN  
  
- Caneta OBJ_EXTPEN estendido  
  
- Região OBJ_REGION  
  
- Contexto de dispositivo OBJ_DC  
  
- Contexto de dispositivo de memória OBJ_MEMDC  
  
- Metarquivo OBJ_METAFILE  
  
- Contexto de dispositivo de metarquivo OBJ_METADC  
  
- Metarquivo avançado do OBJ_ENHMETAFILE  
  
- Contexto de dispositivo de metarquivo avançado OBJ_ENHMETADC  
  
##  <a name="getsafehandle"></a>  CGdiObject::GetSafeHandle  
 Retorna `m_hObject` , a menos que **isso** for NULL, em que o case NULL será retornado.  
  
```  
HGDIOBJ GetSafeHandle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o objeto de GDI Windows anexado; Caso contrário, nulo se nenhum objeto está anexado.  
  
### <a name="remarks"></a>Comentários  
 Isso faz parte do paradigma de interface de identificador geral e é útil quando NULL é um valor válido ou especial para um identificador.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CWnd::IsWindowEnabled](../../mfc/reference/cwnd-class.md#iswindowenabled).  
  
##  <a name="m_hobject"></a>  CGdiObject::m_hObject  
 Um identificador que contém o HBITMAP, HRGN, HBRUSH, HPEN, HPALETTE ou HFONT anexado a este objeto.  
  
```  
HGDIOBJ m_hObject;  
```  
  
##  <a name="operator_neq"></a>  CGdiObject::operator! =  
 Determina se dois objetos GDI logicamente não são iguais.  
  
```  
BOOL operator!=(const CGdiObject& obj) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *obj*  
 Um ponteiro para um existente `CGdiObject`.  
  
### <a name="remarks"></a>Comentários  
 Determina se um objeto GDI no lado esquerdo não é igual ao objeto GDI no lado direito.  
  
##  <a name="operator_eq_eq"></a>  CGdiObject::operator = =  
 Determina se dois objetos GDI são logicamente iguais.  
  
```  
BOOL operator==(const CGdiObject& obj) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *obj*  
 Uma referência a um existente `CGdiObject`.  
  
### <a name="remarks"></a>Comentários  
 Determina se um objeto GDI no lado esquerdo é igual ao objeto GDI no lado direito.  
  
##  <a name="operator_hgdiobj"></a>  CGdiObject::operator HGDIOBJ  
 Recupera um identificador para o objeto de GDI Windows anexado; Caso contrário, nulo se nenhum objeto está anexado.  
  
```  
operator HGDIOBJ() const;  
```  
  
##  <a name="unrealizeobject"></a>  CGdiObject::UnrealizeObject  
 Redefine a origem de um pincel ou redefine uma paleta lógica.  
  
```  
BOOL UnrealizeObject();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Embora `UnrealizeObject` é uma função de membro do `CGdiObject` classe, ele deve ser invocado somente em `CBrush` ou `CPalette` objetos.  
  
 Para `CBrush` objetos, `UnrealizeObject` direciona o sistema para redefinir a origem do pincel determinado na próxima vez que ele é selecionado em um contexto de dispositivo. Se o objeto for um `CPalette` objeto, `UnrealizeObject` direciona o sistema perceber a paleta, como se ele anteriormente não tinha sido percebido. Na próxima vez que o aplicativo chama o [CDC::RealizePalette](../../mfc/reference/cdc-class.md#realizepalette) função para a paleta especificada, o sistema completamente remapeia a paleta lógica a paleta do sistema.  
  
 O `UnrealizeObject` função não deve ser usada com objetos de estoque. O `UnrealizeObject` função deve ser chamada sempre que uma nova origem do pincel é definida (por meio das [CDC::SetBrushOrg](../../mfc/reference/cdc-class.md#setbrushorg) função). O `UnrealizeObject` função não deve ser chamada para o pincel selecionado atualmente ou paleta selecionada no momento de qualquer contexto de exibição.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CBitmap](../../mfc/reference/cbitmap-class.md)   
 [Classe CBrush](../../mfc/reference/cbrush-class.md)   
 [Classe CFont](../../mfc/reference/cfont-class.md)   
 [Classe CPalette](../../mfc/reference/cpalette-class.md)   
 [Classe CPen](../../mfc/reference/cpen-class.md)   
 [Classe CRgn](../../mfc/reference/crgn-class.md)
