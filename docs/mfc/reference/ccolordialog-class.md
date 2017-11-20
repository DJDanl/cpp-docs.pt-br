---
title: Classe CColorDialog | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
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
dev_langs: C++
helpviewer_keywords:
- CColorDialog [MFC], CColorDialog
- CColorDialog [MFC], DoModal
- CColorDialog [MFC], GetColor
- CColorDialog [MFC], GetSavedCustomColors
- CColorDialog [MFC], SetCurrentColor
- CColorDialog [MFC], OnColorOK
- CColorDialog [MFC], m_cc
ms.assetid: d013dc25-9290-4b5d-a97e-95ad7208e13b
caps.latest.revision: "25"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 329474d7d2212d621bdf263021a86d170118f1b0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ccolordialog-class"></a>Classe CColorDialog
Permite que você inserir uma caixa de diálogo de seleção de cor em seu aplicativo.  
  
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
 Um `CColorDialog` objeto é uma caixa de diálogo com uma lista de cores que são definidas para o sistema de exibição. O usuário pode selecionar ou criar uma cor específica da lista, que é então relatada de volta para o aplicativo quando sair da caixa de diálogo.  
  
 Para construir um `CColorDialog` do objeto, use o construtor fornecido ou derivar uma nova classe e usar seu próprio construtor personalizado.  
  
 Depois que a caixa de diálogo foi construída, você pode definir ou modificar valores no [m_cc](#m_cc) estrutura para inicializar os valores de controles da caixa de diálogo. O `m_cc` estrutura é do tipo [CHOOSECOLOR](http://msdn.microsoft.com/library/windows/desktop/ms646830).  
  
 Após a inicialização de controles da caixa de diálogo, chame o `DoModal` a função de membro para exibir a caixa de diálogo e permitir que o usuário selecione uma cor. `DoModal`Retorna a seleção do usuário da Okey caixa de diálogo ( **IDOK**) ou Cancelar ( **IDCANCEL**) botão.  
  
 Se `DoModal` retorna **IDOK**, você pode usar um dos `CColorDialog`de funções de membro para recuperar as informações de entrada do usuário.  
  
 Você pode usar o Windows [CommDlgExtendedError](http://msdn.microsoft.com/library/windows/desktop/ms646916) função para determinar se ocorreu um erro durante a inicialização da caixa de diálogo e para saber mais sobre o erro.  
  
 `CColorDialog`depende do COMMDLG. Arquivo DLL que é fornecido com o Windows versão 3.1 e posterior.  
  
 Para personalizar a caixa de diálogo, derive uma classe de `CColorDialog`, forneça um modelo de caixa de diálogo personalizada e adicionar um mapa de mensagem para processar as mensagens de notificação de controles estendidos. Todas as mensagens não processadas devem ser passadas para a classe base.  
  
 Personalizando a função de gancho não é necessária.  
  
> [!NOTE]
>  Em algumas instalações de `CColorDialog` objeto não será exibida com um plano de fundo cinza, se você tiver usado a estrutura para fazer outras `CDialog` cinza de objetos.  
  
 Para obter mais informações sobre como usar `CColorDialog`, consulte [Classes de caixa de diálogo comuns](../../mfc/common-dialog-classes.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 `CColorDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdlgs.h  
  
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
 Um conjunto de sinalizadores que personalizam a função e a aparência da caixa de diálogo. Para obter mais informações, consulte o [CHOOSECOLOR](http://msdn.microsoft.com/library/windows/desktop/ms646830) estrutura no SDK do Windows.  
  
 `pParentWnd`  
 Um ponteiro para a janela do pai ou o proprietário da caixa de diálogo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#49](../../mfc/codesnippet/cpp/ccolordialog-class_1.cpp)]  
  
##  <a name="domodal"></a>CColorDialog::DoModal  
 Chame essa função para exibir a caixa de diálogo de cor comuns do Windows e permitir que o usuário selecione uma cor.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 **IDOK** ou **IDCANCEL**. Se **IDCANCEL** é retornado, chame o Windows [CommDlgExtendedError](http://msdn.microsoft.com/library/windows/desktop/ms646916) função para determinar se ocorreu um erro.  
  
 **IDOK** e **IDCANCEL** são constantes que indicam se o usuário selecionou o botão Okey ou em Cancelar.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar as várias opções de caixa de diálogo de cor, definindo membros do [m_cc](#m_cc) estrutura, você deve fazer isso antes de chamar `DoModal` , mas depois que o objeto de caixa de diálogo é construído.  
  
 Depois de chamar `DoModal`, você pode chamar outro membro funções para recuperar as configurações ou a entrada de informações pelo usuário na caixa de diálogo.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CColorDialog::CColorDialog](#ccolordialog).  
  
##  <a name="getcolor"></a>CColorDialog::GetColor  
 Chamar essa função depois de chamar `DoModal` para recuperar as informações sobre a cor do usuário selecionado.  
  
```  
COLORREF GetColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor que contém as informações de RGB da cor selecionada na caixa de diálogo de cor.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#50](../../mfc/codesnippet/cpp/ccolordialog-class_2.cpp)]  
  
##  <a name="getsavedcustomcolors"></a>CColorDialog::GetSavedCustomColors  
 `CColorDialog`objetos permitem que o usuário, além de escolher as cores, defina até 16 cores personalizadas.  
  
```  
static COLORREF* PASCAL GetSavedCustomColors();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para uma matriz de valores de cor RGB 16 que armazena as cores personalizadas criadas pelo usuário.  
  
### <a name="remarks"></a>Comentários  
 O `GetSavedCustomColors` função membro fornece acesso a essas cores. Essas cores podem ser recuperadas após [DoModal](#domodal) retorna **IDOK**.  
  
 Cada um dos valores RGB 16 na matriz retornada é inicializada como RGB(255,255,255) (branco). As cores personalizadas escolhidas pelo usuário são salvas somente entre invocações de caixa de diálogo dentro do aplicativo. Se você deseja salvar essas cores entre invocações do aplicativo, você deve salvá-los em alguma outra forma, como em uma inicialização (. Arquivo INI).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#51](../../mfc/codesnippet/cpp/ccolordialog-class_3.cpp)]  
  
##  <a name="m_cc"></a>CColorDialog::m_cc  
 Uma estrutura de tipo [CHOOSECOLOR](http://msdn.microsoft.com/library/windows/desktop/ms646830), cujos membros armazenam as características e os valores da caixa de diálogo.  
  
```  
CHOOSECOLOR m_cc;  
```  
  
### <a name="remarks"></a>Comentários  
 Depois de construir um `CColorDialog` do objeto, você pode usar `m_cc` para definir vários aspectos da caixa de diálogo antes de chamar o [DoModal](#domodal) função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#53](../../mfc/codesnippet/cpp/ccolordialog-class_4.cpp)]  
  
##  <a name="oncolorok"></a>CColorDialog::OnColorOK  
 Substitua para validar a cor inserida na caixa de diálogo.  
  
```  
virtual BOOL OnColorOK();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a caixa de diálogo não deve ser ignorada; Caso contrário, 0 para aceitar a cor que foi inserida.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função somente se você deseja fornecer validação personalizada da cor que o usuário seleciona na caixa de diálogo de cor.  
  
 O usuário pode selecionar uma cor por um dos dois métodos a seguir:  
  
-   Clicando em uma cor na paleta de cores. Valores RGB da cor selecionada serão refletidos nas caixas de edição RGB apropriadas.  
  
-   Caixas de edição de inserir valores de RGB  
  
 Substituindo `OnColorOK` permite que você rejeite uma cor que o usuário insere em uma caixa de diálogo de cor comuns por qualquer motivo específico do aplicativo.  
  
 Normalmente, você não precisa usar essa função, porque a estrutura fornece validação de padrão de cores e exibe uma caixa de mensagem se uma cor inválida for digitada.  
  
 Você pode chamar [SetCurrentColor](#setcurrentcolor) na `OnColorOK` para forçar uma seleção de cor. Uma vez `OnColorOK` foi acionado (ou seja, o usuário clica em **Okey** para aceitar a alteração de cor), você pode chamar [GetColor](#getcolor) para obter o valor RGB da cor de novo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#52](../../mfc/codesnippet/cpp/ccolordialog-class_5.cpp)]  
  
##  <a name="setcurrentcolor"></a>CColorDialog::SetCurrentColor  
 Chamar essa função depois de chamar `DoModal` para forçar a seleção de cor atual para o valor de cor especificado no `clr`.  
  
```  
void SetCurrentColor(COLORREF clr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `clr`  
 Um valor de cor RGB.  
  
### <a name="remarks"></a>Comentários  
 Essa função é chamada de dentro de um manipulador de mensagens ou `OnColorOK`. A caixa de diálogo atualizará automaticamente a seleção do usuário com base no valor da `clr` parâmetro.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CColorDialog::OnColorOK](#oncolorok).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MDI](../../visual-cpp-samples.md)   
 [Exemplo MFC DRAWCLI](../../visual-cpp-samples.md)   
 [Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

