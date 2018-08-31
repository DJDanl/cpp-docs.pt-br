---
title: Classe COleChangeIconDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleChangeIconDialog
- AFXODLGS/COleChangeIconDialog
- AFXODLGS/COleChangeIconDialog::COleChangeIconDialog
- AFXODLGS/COleChangeIconDialog::DoChangeIcon
- AFXODLGS/COleChangeIconDialog::DoModal
- AFXODLGS/COleChangeIconDialog::GetIconicMetafile
- AFXODLGS/COleChangeIconDialog::m_ci
dev_langs:
- C++
helpviewer_keywords:
- COleChangeIconDialog [MFC], COleChangeIconDialog
- COleChangeIconDialog [MFC], DoChangeIcon
- COleChangeIconDialog [MFC], DoModal
- COleChangeIconDialog [MFC], GetIconicMetafile
- COleChangeIconDialog [MFC], m_ci
ms.assetid: 8d6e131b-ddbb-4dff-a432-f239efda8e3d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 089fe435c86b524acc41ba528452d93032d1b1a4
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43214487"
---
# <a name="colechangeicondialog-class"></a>Classe COleChangeIconDialog
Usado para a caixa de diálogo Alterar ícone do OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleChangeIconDialog : public COleDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleChangeIconDialog::COleChangeIconDialog](#colechangeicondialog)|Constrói um objeto `COleChangeIconDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleChangeIconDialog::DoChangeIcon](#dochangeicon)|Executa a alteração especificada na caixa de diálogo.|  
|[COleChangeIconDialog::DoModal](#domodal)|Exibe a caixa de diálogo OLE 2 alterar ícone.|  
|[COleChangeIconDialog::GetIconicMetafile](#geticonicmetafile)|Obtém um identificador para o metarquivo associado ao formulário icônico deste item.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleChangeIconDialog::m_ci](#m_ci)|Uma estrutura que controla o comportamento da caixa de diálogo.|  
  
## <a name="remarks"></a>Comentários  
 Criar um objeto da classe `COleChangeIconDialog` quando você deseja chamar essa caixa de diálogo. Depois de um `COleChangeIconDialog` objeto foi construído, você pode usar o [m_ci](#m_ci) estrutura para inicializar os valores ou os estados dos controles na caixa de diálogo. O `m_ci` estrutura é do tipo OLEUICHANGEICON. Para obter mais informações sobre como usar essa classe de caixa de diálogo, consulte a [DoModal](#domodal) função de membro.  
  
 Para obter mais informações, consulte o [OLEUICHANGEICON](/windows/desktop/api/oledlg/ns-oledlg-tagoleuichangeicona) estrutura no SDK do Windows.  
  
 Para obter mais informações sobre caixas de diálogo OLE específico, consulte o artigo [caixas de diálogo em OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 [COleDialog](../../mfc/reference/coledialog-class.md)  
  
 `COleChangeIconDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
##  <a name="colechangeicondialog"></a>  COleChangeIconDialog::COleChangeIconDialog  
 Essa função só constrói um `COleChangeIconDialog` objeto.  
  
```  
explicit COleChangeIconDialog(
    COleClientItem* pItem,  
    DWORD dwFlags = CIF_SELECTCURRENT,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pItem*  
 Aponta para o item a ser convertido.  
  
 *dwFlags*  
 Sinalizador de criação, que contém qualquer número de valores a seguir combinadas que usam o bit a bit- ou operador:  
  
- CIF_SELECTCURRENT Especifica que o botão de opção atual será inicialmente selecionado quando a caixa de diálogo é chamada. Esse é o padrão.  
  
- CIF_SELECTDEFAULT Especifica que o botão de rádio padrão será inicialmente selecionado quando a caixa de diálogo é chamada.  
  
- CIF_SELECTFROMFILE Especifica que o botão de opção de arquivo serão selecionadas inicialmente quando a caixa de diálogo é chamada.  
  
- CIF_SHOWHELP Especifica que o botão de Ajuda será exibido quando a caixa de diálogo é chamada.  
  
- CIF_USEICONEXE Especifica que o ícone deve ser extraído do executável especificado na `szIconExe` campo de [m_ci](#m_ci) em vez de recuperada do tipo. Isso é útil para incorporação ou vinculação de arquivos não são OLE.  
  
 *pParentWnd*  
 Aponta para o objeto de janela pai ou proprietária (do tipo `CWnd`) ao qual pertence o objeto de caixa de diálogo. Se for NULL, a janela pai da caixa de diálogo será definida para a janela principal do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Para exibir a caixa de diálogo, chame o [DoModal](#domodal) função.  
  
 Para obter mais informações, consulte o [OLEUICHANGEICON](/windows/desktop/api/oledlg/ns-oledlg-tagoleuichangeicona) estrutura no SDK do Windows.  
  
##  <a name="dochangeicon"></a>  COleChangeIconDialog::DoChangeIcon  
 Chame essa função para alterar o ícone que representa o item para aquele selecionado na caixa de diálogo após [DoModal](#domodal) retorna IDOK.  
  
```  
BOOL DoChangeIcon(COleClientItem* pItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pItem*  
 Aponta para o item cujo ícone está mudando.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a alteração for bem-sucedida; Caso contrário, 0.  
  
##  <a name="domodal"></a>  COleChangeIconDialog::DoModal  
 Chame essa função para exibir a caixa de diálogo Alterar ícone do OLE.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Status de conclusão para a caixa de diálogo. Um dos seguintes valores:  
  
- IDOK se a caixa de diálogo foi exibida com êxito.  
  
- IDCANCEL se o usuário cancelou a caixa de diálogo.  
  
- IDABORT se ocorreu um erro. Se IDABORT for retornado, chame o `COleDialog::GetLastError` a função de membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte o [OleUIChangeIcon](/windows/desktop/api/oledlg/nf-oledlg-oleuichangeicona) função no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar os vários controles de caixa de diálogo definindo membros do [m_ci](#m_ci) estrutura, você deve fazer isso antes de chamar `DoModal`, mas depois que o objeto de caixa de diálogo é construído.  
  
 Se `DoModal` retorna IDOK, você pode chamar outro membro funções para recuperar as configurações ou informações que era inseridas pelo usuário na caixa de diálogo.  
  
##  <a name="geticonicmetafile"></a>  COleChangeIconDialog::GetIconicMetafile  
 Chame essa função para obter um identificador para o metarquivo que contém o aspecto icônico do item selecionado.  
  
```  
HGLOBAL GetIconicMetafile() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador para o metarquivo que contém o aspecto icônico do novo ícone, se a caixa de diálogo foi ignorada, escolhendo **Okey**; caso contrário, o ícone de como ele estava antes da caixa de diálogo foi exibida.  
  
##  <a name="m_ci"></a>  COleChangeIconDialog::m_ci  
 Estrutura do tipo OLEUICHANGEICON usado para controlar o comportamento da caixa de diálogo Alterar ícone.  
  
```  
OLEUICHANGEICON m_ci;  
```  
  
### <a name="remarks"></a>Comentários  
 Os membros dessa estrutura podem ser modificados diretamente ou através de funções de membro.  
  
 Para obter mais informações, consulte o [OLEUICHANGEICON](/windows/desktop/api/oledlg/ns-oledlg-tagoleuichangeicona) estrutura no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)
