---
title: "Páginas de propriedade (MFC) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.mfc.macros
dev_langs: C++
helpviewer_keywords:
- property page data transfer functions in MFC
- property pages [MFC], global MFC functions
ms.assetid: 734f88bc-c776-4136-9b0e-f45c761a45c1
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e53260457470ef75ac706779cea323aa5b73da2a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="property-pages-mfc"></a>Páginas de propriedade (MFC)
Páginas de propriedade exibem os valores atuais das propriedades de controle OLE específicos em uma interface gráfica personalizável para exibição e edição, dando suporte a um mecanismo de mapeamento de dados com base na troca de dados de caixa de diálogo (DDX).  
  
 Esse mecanismo de mapeamento de dados mapeia os controles da página de propriedade para as propriedades individuais do controle OLE. O valor da propriedade de controle reflete o status ou o conteúdo do controle de página de propriedades. O mapeamento entre as propriedades e os controles da página de propriedade é especificado pelo **DDP _** chamadas de função na página de propriedades `DoDataExchange` função de membro. A seguir está uma lista de **DDP _** funções que trocam dados inseridos usando a página de propriedades do controle:  
  
### <a name="property-page-data-transfer"></a>Transferência de dados da página de propriedade  
  
|||  
|-|-|  
|[DDP_CBIndex](#ddp_cbindex)|Vincula o índice selecionado da cadeia de caracteres em uma caixa de combinação com a propriedade do controle.|  
|[DDP_CBString](#ddp_cbstring)|Vincula a cadeia de caracteres selecionada em uma caixa de combinação com a propriedade do controle. A cadeia de caracteres selecionada pode começar com as mesmas letras de como o valor da propriedade, mas não precisa correspondê-la completamente.|  
|[DDP_CBStringExact](#ddp_cbstringexact)|Vincula a cadeia de caracteres selecionada em uma caixa de combinação com a propriedade do controle. A cadeia de caracteres selecionada e o valor de cadeia de caracteres da propriedade devem corresponder exatamente.|  
|[DDP_Check](#ddp_check)|Vincula uma caixa de seleção na página de propriedades do controle com a propriedade do controle.|  
|[DDP_LBIndex](#ddp_lbindex)|Vincula o índice selecionado da cadeia de caracteres em uma caixa de listagem com a propriedade do controle.|  
|[DDP_LBString](#ddp_lbstring)|Vincula a cadeia de caracteres selecionada em uma caixa de listagem com a propriedade do controle. A cadeia de caracteres selecionada pode começar com as mesmas letras de como o valor da propriedade, mas não precisa coincidi-la completamente.|  
|[DDP_LBStringExact](#ddp_lbstringexact)|Vincula a cadeia de caracteres selecionada em uma caixa de listagem com a propriedade do controle. A cadeia de caracteres selecionada e o valor de cadeia de caracteres da propriedade devem corresponder exatamente.|  
|[DDP_PostProcessing](#ddp_postprocessing)|Conclui a transferência de valores de propriedade de seu controle.|  
|[DDP_Radio](#ddp_radio)|Links de um grupo de botões de opção na página de propriedades do controle com a propriedade do controle.|  
|[DDP_Text](#ddp_text)|Vincula um controle na página de propriedades do controle com a propriedade do controle. Esta função controla vários tipos diferentes de propriedades, como **duplo**, **curto**, `BSTR`, e **longo**.|  
  
 Para obter mais informações sobre o `DoDataExchange` páginas de propriedade e de função, consulte o artigo [controles ActiveX: páginas de propriedade](../../mfc/mfc-activex-controls-property-pages.md).  
  
 A seguir está uma lista de macros usado para criar e gerenciar páginas de propriedades de um controle OLE:  
  
### <a name="property-pages"></a>Páginas de propriedade  
  
|||  
|-|-|  
|[BEGIN_PROPPAGEIDS](#begin_proppageids)|Começa a lista de IDs de página de propriedade.|  
|[END_PROPPAGEIDS](#end_proppageids)|Termina a lista de IDs de página de propriedade.|  
|[PROPPAGEID](#proppageid)|Declara uma página de propriedades da classe de controle.|  
  
##  <a name="ddp_cbindex"></a>DDP_CBIndex  
 Chamar essa função em sua página de propriedades `DoDataExchange` função para sincronizar o valor de uma propriedade de inteiro com o índice da seleção atual em uma caixa de combinação na página de propriedades.  
  
```   
void AFXAPI DDP_CBIndex(
    CDataExchange* pDX,  
    int id,  
    int& member,  
    LPCTSTR pszPropName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Ponteiro para uma `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `id`  
 A ID de recurso de caixa de combinação de caixa controle associado com a propriedade do controle especificada pelo `pszPropName`.  
  
 `member`  
 A variável de membro associada ao controle de página de propriedade especificado por `id` e a propriedade especificada pelo `pszPropName`.  
  
 `pszPropName`  
 O nome da propriedade da propriedade controle sejam trocadas com o controle de caixa de combinação especificado pelo `id`.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser chamada antes do correspondente `DDX_CBIndex` chamada de função.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl. h  
  
##  <a name="ddp_cbstring"></a>DDP_CBString  
 Chamar essa função em sua página de propriedades `DoDataExchange` função para sincronizar o valor de uma propriedade de cadeia de caracteres com a seleção atual em uma caixa de combinação na página de propriedades.  
  
```  
void AFXAPI DDP_CBString(
    CDataExchange* pDX,  
    int id,  
    CString& member,  
    LPCTSTR pszPropName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Ponteiro para uma `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `id`  
 A ID de recurso de caixa de combinação de caixa controle associado com a propriedade do controle especificada pelo `pszPropName`.  
  
 `member`  
 A variável de membro associada ao controle de página de propriedade especificado por `id` e a propriedade especificada pelo `pszPropName`.  
  
 `pszPropName`  
 O nome da propriedade da propriedade a ser trocado com a cadeia de caracteres de caixa de combinação especificada pelo controle `id`.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser chamada antes do correspondente `DDX_CBString` chamada de função.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl. h  
  
##  <a name="ddp_cbstringexact"></a>DDP_CBStringExact  
 Chamar essa função em sua página de propriedades `DoDataExchange` função para sincronizar o valor de uma propriedade de cadeia de caracteres que corresponda exatamente a seleção atual em uma caixa de combinação na página de propriedades.  
  
```  
void AFXAPI DDP_CBStringExact(
    CDataExchange* pDX,  
    int id,  
    CString& member,  
    LPCTSTR pszPropName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Ponteiro para uma `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `id`  
 A ID de recurso de caixa de combinação de caixa controle associado com a propriedade do controle especificada pelo `pszPropName`.  
  
 `member`  
 A variável de membro associada ao controle de página de propriedade especificado por `id` e a propriedade especificada pelo `pszPropName`.  
  
 `pszPropName`  
 O nome da propriedade da propriedade a ser trocado com a cadeia de caracteres de caixa de combinação especificada pelo controle `id`.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser chamada antes do correspondente `DDX_CBStringExact` chamada de função.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl. h  
  
##  <a name="ddp_check"></a>DDP_Check  
 Chamar essa função em sua página de propriedades `DoDataExchange` função para sincronizar o valor da propriedade com o controle de caixa de seleção de página de propriedade associada.  
  
```   
void AFXAPI DDP_Check(
    CDataExchange* pDX,  
    int id,  
    int & member,  
    LPCSTR pszPropName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Ponteiro para uma `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `id`  
 A ID de controle da caixa de seleção de recursos associados com a propriedade do controle especificada pelo `pszPropName`.  
  
 `member`  
 A variável de membro associada ao controle de página de propriedade especificado por `id` e a propriedade especificada pelo `pszPropName`.  
  
 `pszPropName`  
 O nome da propriedade da propriedade controle sejam trocados com o controle de caixa de seleção especificado pelo `id`.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser chamada antes do correspondente `DDX_Check` chamada de função.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl. h  
  
##  <a name="ddp_lbindex"></a>DDP_LBIndex  
 Chamar essa função em sua página de propriedades `DoDataExchange` função para sincronizar o valor de uma propriedade de inteiro com o índice da seleção atual em uma caixa de lista na página de propriedades.  
  
```   
void AFXAPI DDP_LBIndex(
    CDataExchange* pDX,  
    int id,  
    int& member,  
    LPCTSTR pszPropName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Ponteiro para uma `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `id`  
 A ID de recurso da lista de caixa controle associado com a propriedade do controle especificada pelo `pszPropName`.  
  
 `member`  
 A variável de membro associada ao controle de página de propriedade especificado por `id` e a propriedade especificada pelo `pszPropName`.  
  
 `pszPropName`  
 O nome da propriedade da propriedade a ser trocado com a cadeia de caracteres de caixa de lista especificada pelo controle `id`.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser chamada antes do correspondente `DDX_LBIndex` chamada de função.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl. h  
  
##  <a name="ddp_lbstring"></a>DDP_LBString  
 Chamar essa função em sua página de propriedades `DoDataExchange` função para sincronizar o valor de uma propriedade de cadeia de caracteres com a seleção atual em uma caixa de lista na página de propriedades.  
  
```   
void AFXAPI DDP_LBString(
    CDataExchange* pDX,  
    int id,  
    CString& member,  
    LPCTSTR pszPropName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Ponteiro para uma `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `id`  
 A ID de recurso da lista de caixa controle associado com a propriedade do controle especificada pelo `pszPropName`.  
  
 `member`  
 A variável de membro associada ao controle de página de propriedade especificado por `id` e a propriedade especificada pelo `pszPropName`.  
  
 `pszPropName`  
 O nome da propriedade da propriedade a ser trocado com a cadeia de caracteres de caixa de lista especificada pelo controle `id`.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser chamada antes do correspondente `DDX_LBString` chamada de função.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl. h  
  
##  <a name="ddp_lbstringexact"></a>DDP_LBStringExact  
 Chamar essa função em sua página de propriedades `DoDataExchange` função para sincronizar o valor de uma propriedade de cadeia de caracteres que corresponda exatamente a seleção atual em uma caixa de lista na página de propriedades.  
  
```   
void AFXAPI DDP_LBStringExact(
    CDataExchange* pDX,  
    int id,  
    CString& member,  
    LPCTSTR pszPropName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Ponteiro para uma `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `id`  
 A ID de recurso da lista de caixa controle associado com a propriedade do controle especificada pelo `pszPropName`.  
  
 `member`  
 A variável de membro associada ao controle de página de propriedade especificado por `id` e a propriedade especificada pelo `pszPropName`.  
  
 `pszPropName`  
 O nome da propriedade da propriedade a ser trocado com a cadeia de caracteres de caixa de lista especificada pelo controle `id`.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser chamada antes do correspondente `DDX_LBStringExact` chamada de função.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl. h  
  
##  <a name="ddp_postprocessing"></a>DDP_PostProcessing  
 Chamar essa função em sua página de propriedades `DoDataExchange` função, para concluir a transferência de valores de propriedade da página de propriedade para o controle quando valores de propriedade estão sendo salvas.  
  
```   
void AFXAPI DDP_PostProcessing(CDataExchange * pDX);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Ponteiro para uma `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser chamada depois de concluir todas as funções de troca de dados. Por exemplo:  
  
 [!code-cpp[NVC_MFCAxCtl#15](../../mfc/reference/codesnippet/cpp/property-pages-mfc_1.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl. h  
  
##  <a name="ddp_radio"></a>DDP_Radio  
 Chamar essa função em seu controle `DoPropExchange` função para sincronizar o valor da propriedade com o controle de botão de opção de página de propriedade associada.  
  
```   
void AFXAPI DDP_Radio(
    CDataExchange* pDX,  
    int id,  
    int & member,  
    LPCTSTR pszPropName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Ponteiro para uma `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `id`  
 A ID de recurso do rádio botão controle associado com a propriedade do controle especificada pelo `pszPropName`.  
  
 `member`  
 A variável de membro associada ao controle de página de propriedade especificado por `id` e a propriedade especificada pelo `pszPropName`.  
  
 `pszPropName`  
 O nome da propriedade da propriedade controle sejam trocadas com o controle de botão de opção especificado pelo `id`.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser chamada antes do correspondente `DDX_Radio` chamada de função.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl. h  
  
##  <a name="ddp_text"></a>DDP_Text  
 Chamar essa função em seu controle `DoDataExchange` função para sincronizar o valor da propriedade com o controle de página de propriedade associada.  
  
```   
void AFXAPI DDP_Text(
    CDataExchange* pDX,  
    int id,  
    BYTE & member,  
    LPCTSTR pszPropName);

void AFXAPI DDP_Text(
    CDataExchange* pDX,  
    int id,  
    int & member,  
    LPCTSTR pszPropName);

void AFXAPI DDP_Text(
    CDataExchange* pDX,  
    int id,  
    UINT & member,  
    LPCTSTR pszPropName);

void AFXAPI DDP_Text(
    CDataExchange* pDX,  
    int id,  
    long & member,  
    LPCTSTR pszPropName);

void AFXAPI DDP_Text(
    CDataExchange* pDX,  
    int id,  
    DWORD & member,  
    LPCTSTR pszPropName);

void AFXAPI DDP_Text(
    CDataExchange* pDX,  
    int id,  
    float & member,  
    LPCTSTR pszPropName);

void AFXAPI DDP_Text(
    CDataExchange* pDX,  
    int id,  
    double & member,  
    LPCTSTR pszPropName);

void AFXAPI DDP_Text(
    CDataExchange* pDX,  
    int id,  
    CString & member,  
    LPCTSTR pszPropName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Ponteiro para uma `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `id`  
 A ID de recurso do controle associado com a propriedade do controle especificada pelo `pszPropName`.  
  
 `member`  
 A variável de membro associada ao controle de página de propriedade especificado por `id` e a propriedade especificada pelo `pszPropName`.  
  
 `pszPropName`  
 O nome da propriedade da propriedade controle sejam trocados com o controle especificado pelo `id`.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser chamada antes do correspondente `DDX_Text` chamada de função.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl. h  
  
##  <a name="begin_proppageids"></a>BEGIN_PROPPAGEIDS  
 Começa a definição da lista de controle de IDs de página de propriedade.  
  
```   
BEGIN_PROPPAGEIDS(class_name,  count)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome da classe de controle para o qual propriedade páginas estão sendo especificadas.  
  
 *count*  
 O número de páginas de propriedades usado pela classe de controle.  
  
### <a name="remarks"></a>Comentários  
 No arquivo de implementação (. cpp) que define as funções de membro para a sua classe, iniciar a lista de páginas de propriedade com o `BEGIN_PROPPAGEIDS` macro, em seguida, adicionar entradas de macro para cada uma das suas páginas de propriedades e concluir a lista de páginas de propriedade com o `END_PROPPAGEIDS` macro.  
  
 Para obter mais informações sobre páginas de propriedades, consulte o artigo [controles ActiveX: páginas de propriedade](../../mfc/mfc-activex-controls-property-pages.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl. h  
  
##  <a name="end_proppageids"></a>END_PROPPAGEIDS  
 Finaliza a definição de sua lista de ID de página de propriedades.  
  
```   
END_PROPPAGEIDS(class_name)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome da classe de controle que possui a página de propriedades.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl. h  
  
##  <a name="proppageid"></a>PROPPAGEID  
 Adiciona uma página de propriedades para uso de controle OLE.  
  
```   
PROPPAGEID(clsid)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `clsid`  
 A ID de classe exclusivo de uma página de propriedades.  
  
### <a name="remarks"></a>Comentários  
 Todos os `PROPPAGEID` macros devem ser colocadas entre o `BEGIN_PROPPAGEIDS` e `END_PROPPAGEIDS` macros no arquivo de implementação do controle.  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl. h  
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
