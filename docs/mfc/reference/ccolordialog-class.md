---
title: Classe CColorDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CColorDialog
- AFXDLGS/CColorDialog
- AFXDLGS/CColorDialog::CColorDialog
- AFXDLGS/CColorDialog::DoModal
- AFXDLGS/CColorDialog::GetColor
- AFXDLGS/CColorDialog::GetSavedCustomColors
- AFXDLGS/CColorDialog::SetCurrentColor
- AFXDLGS/CColorDialog::OnColorOK
- AFXDLGS/CColorDialog::m_cc
dev_langs:
- C++
helpviewer_keywords:
- colors, dialog box
- dialog boxes, colors
- CColorDialog class
ms.assetid: d013dc25-9290-4b5d-a97e-95ad7208e13b
caps.latest.revision: 25
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
ms.openlocfilehash: a8aee088aadbca18acda348c574c8f4b55d1ecbb
ms.lasthandoff: 02/25/2017

---
# <a name="ccolordialog-class"></a>Classe CColorDialog
Permite incorporar uma caixa de diálogo de seleção de cor em seu aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CColorDialog : public CCommonDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CColorDialog::CColorDialog](#ccolordialog)|Constrói um objeto `CColorDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CColorDialog::DoModal](#domodal)|Exibe uma caixa de diálogo de cor e permite que o usuário faça uma seleção.|  
|[CColorDialog::GetColor](#getcolor)|Retorna um **COLORREF** estrutura que contém os valores da cor selecionada.|  
|[CColorDialog::GetSavedCustomColors](#getsavedcustomcolors)|Recupera as cores personalizadas criadas pelo usuário.|  
|[CColorDialog::SetCurrentColor](#setcurrentcolor)|Força a seleção de cor atual com a cor especificada.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CColorDialog::OnColorOK](#oncolorok)|Substitua para validar a cor inserida na caixa de diálogo.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CColorDialog::m_cc](#m_cc)|Uma estrutura usada para personalizar as configurações da caixa de diálogo.|  
  
## <a name="remarks"></a>Comentários  
 Um `CColorDialog` objeto é uma caixa de diálogo com uma lista de cores que são definidos para o sistema do vídeo. O usuário pode selecionar ou criar uma cor específica da lista, que é então relatada de volta para o aplicativo quando sair da caixa de diálogo.  
  
 Para construir um `CColorDialog` do objeto, use o construtor fornecido ou derivar uma nova classe e usar seu próprio construtor personalizado.  
  
 Depois que a caixa de diálogo foi construída, você pode definir ou modificar qualquer valor de [m_cc](#m_cc) estrutura para inicializar os valores dos controles da caixa de diálogo. O `m_cc` estrutura é do tipo [CHOOSECOLOR](http://msdn.microsoft.com/library/windows/desktop/ms646830).  
  
 Após inicializar controles da caixa de diálogo, chame o `DoModal` a função de membro para exibir a caixa de diálogo e permitir que o usuário selecione uma cor. `DoModal`Retorna a seleção do usuário do Okey da caixa de diálogo ( **IDOK**) ou Cancel ( **IDCANCEL**) botão.  
  
 Se `DoModal` retorna **IDOK**, você pode usar um dos `CColorDialog`de funções de membro para recuperar as informações de entrada do usuário.  
  
 Você pode usar o Windows [CommDlgExtendedError](http://msdn.microsoft.com/library/windows/desktop/ms646916) função para determinar se ocorreu um erro durante a inicialização da caixa de diálogo e saiba mais sobre o erro.  
  
 `CColorDialog`depende do COMMDLG. Arquivo DLL que acompanha o Windows versões 3.1 e posteriores.  
  
 Para personalizar a caixa de diálogo, derive uma classe de `CColorDialog`, fornecer um modelo de caixa de diálogo personalizada e adicionar um mapa da mensagem para processar as mensagens de notificação de controles estendidos. Todas as mensagens não processadas devem ser passadas para a classe base.  
  
 Personalizando a função de gancho não é necessária.  
  
> [!NOTE]
>  Em algumas instalações a `CColorDialog` objeto não será exibida com um plano de fundo cinza, se você tiver usado a estrutura para fazer outras `CDialog` cinza de objetos.  
  
 Para obter mais informações sobre como usar o `CColorDialog`, consulte [Classes de caixa de diálogo comuns](../../mfc/common-dialog-classes.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 `CColorDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdlgs. h  
  
##  <a name="ccolordialog"></a>CColorDialog::CColorDialog  
 Constrói um objeto `CColorDialog`.  
  
```  
CColorDialog(
    COLORREF clrInit = 0,  
    DWORD dwFlags = 0,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *clrInit*  
 A seleção de cor padrão. Se nenhum valor for especificado, o padrão é RGB(0,0,0) (preto).  
  
 `dwFlags`  
 Um conjunto de sinalizadores que personalizam a função e a aparência da caixa de diálogo. Para obter mais informações, consulte o [CHOOSECOLOR](http://msdn.microsoft.com/library/windows/desktop/ms646830) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `pParentWnd`  
 Um ponteiro para a janela do pai ou o proprietário da caixa de diálogo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[49 NVC_MFCDocView](../../mfc/codesnippet/cpp/ccolordialog-class_1.cpp)]  
  
##  <a name="domodal"></a>CColorDialog::DoModal  
 Chame essa função para exibir a caixa de diálogo de cor comuns do Windows e permitir que o usuário selecione uma cor.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 **IDOK** ou **IDCANCEL**. Se **IDCANCEL** é retornado, chame o Windows [CommDlgExtendedError](http://msdn.microsoft.com/library/windows/desktop/ms646916) função para determinar se ocorreu um erro.  
  
 **IDOK** e **IDCANCEL** são constantes que indicam se o usuário selecionou o botão Okey ou Cancelar.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar as várias opções de caixa de diálogo de cor, definindo membros do [m_cc](#m_cc) estrutura, você deve fazer isso antes de chamar `DoModal` , mas depois que o objeto de caixa de diálogo é construído.  
  
 Depois de chamar `DoModal`, você pode chamar outro membro funções para recuperar as configurações ou entrada de informações pelo usuário na caixa de diálogo.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CColorDialog::CColorDialog](#ccolordialog).  
  
##  <a name="getcolor"></a>CColorDialog::GetColor  
 Chame essa função depois de chamar `DoModal` para recuperar as informações sobre a cor do usuário selecionado.  
  
```  
COLORREF GetColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor que contém informações para a cor selecionada na caixa de diálogo de cor RGB.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#50;](../../mfc/codesnippet/cpp/ccolordialog-class_2.cpp)]  
  
##  <a name="getsavedcustomcolors"></a>CColorDialog::GetSavedCustomColors  
 `CColorDialog`objetos permitem que o usuário, além de escolher as cores, defina até 16 cores personalizadas.  
  
```  
static COLORREF* PASCAL GetSavedCustomColors();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para uma matriz de valores de cor RGB 16 que armazena as cores personalizadas criadas pelo usuário.  
  
### <a name="remarks"></a>Comentários  
 O `GetSavedCustomColors` função de membro fornece acesso a essas cores. Essas cores podem ser recuperadas após [DoModal](#domodal) retorna **IDOK**.  
  
 Cada um dos valores RGB 16 na matriz retornada é inicializada com RGB(255,255,255) (branco). As cores personalizadas escolhidas pelo usuário são salvas somente entre invocações de caixa de diálogo dentro do aplicativo. Se você deseja salvar essas cores entre invocações do aplicativo, você deverá salvá-los de alguma outra maneira, como em uma inicialização (. Arquivo INI).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#51;](../../mfc/codesnippet/cpp/ccolordialog-class_3.cpp)]  
  
##  <a name="m_cc"></a>CColorDialog::m_cc  
 Uma estrutura do tipo [CHOOSECOLOR](http://msdn.microsoft.com/library/windows/desktop/ms646830), cujos membros armazenam as características e os valores da caixa de diálogo.  
  
```  
CHOOSECOLOR m_cc;  
```  
  
### <a name="remarks"></a>Comentários  
 Depois de criar um `CColorDialog` do objeto, você pode usar `m_cc` para definir vários aspectos da caixa de diálogo antes de chamar o [DoModal](#domodal) função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#53;](../../mfc/codesnippet/cpp/ccolordialog-class_4.cpp)]  
  
##  <a name="oncolorok"></a>CColorDialog::OnColorOK  
 Substitua para validar a cor inserida na caixa de diálogo.  
  
```  
virtual BOOL OnColorOK();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a caixa de diálogo não deve ser ignorada; Caso contrário, 0 para aceitar a cor que foi inserida.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função somente se você desejar fornecer validação personalizada da cor que o usuário seleciona na caixa de diálogo de cor.  
  
 O usuário pode selecionar uma cor por um dos dois métodos a seguir:  
  
-   Clicando em uma cor na paleta de cores. Valores RGB da cor selecionada são refletidos nas caixas de edição RGB apropriadas.  
  
-   Inserindo valores de RGB caixas de edição  
  
 Substituindo `OnColorOK` permite que você rejeitar uma cor que o usuário insere em uma caixa de diálogo de cor comuns por qualquer motivo específico do aplicativo.  
  
 Normalmente, você não precisa usar essa função, porque a estrutura fornece validação padrão de cores e exibe uma caixa de mensagem se uma cor inválido for inserida.  
  
 Você pode chamar [SetCurrentColor](#setcurrentcolor) na `OnColorOK` para forçar uma seleção de cor. Uma vez `OnColorOK` tiver sido acionado (ou seja, o usuário clica em **Okey** para aceitar a alteração de cor), você pode chamar [GetColor](#getcolor) para obter o valor RGB da cor de novo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#52;](../../mfc/codesnippet/cpp/ccolordialog-class_5.cpp)]  
  
##  <a name="setcurrentcolor"></a>CColorDialog::SetCurrentColor  
 Chame essa função depois de chamar `DoModal` para forçar a seleção de cor atual para o valor de cor especificado em `clr`.  
  
```  
void SetCurrentColor(COLORREF clr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `clr`  
 Um valor de cor RGB.  
  
### <a name="remarks"></a>Comentários  
 Essa função é chamada de dentro de um manipulador de mensagens ou `OnColorOK`. A caixa de diálogo atualizará automaticamente a seleção do usuário com base no valor da `clr` parâmetro.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CColorDialog::OnColorOK](#oncolorok).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MDI](../../visual-cpp-samples.md)   
 [Exemplo MFC DRAWCLI](../../visual-cpp-samples.md)   
 [Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)


