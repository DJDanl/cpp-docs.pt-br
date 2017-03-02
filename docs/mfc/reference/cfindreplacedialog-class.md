---
title: Classe CFindReplaceDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CFindReplaceDialog
dev_langs:
- C++
helpviewer_keywords:
- text searches, replacing text
- text searches, CFindReplaceDialog class
- Find/Replace dialog box
- replacing text, CFindReplaceDialog class
- CFindReplaceDialog class
- replacing text
ms.assetid: 610f0b5d-b398-4ef6-8c05-e9d6641e50a8
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
ms.openlocfilehash: 510f6a763dbacb7d4e1b14ea808a4baaaf3d6bf3
ms.lasthandoff: 02/25/2017

---
# <a name="cfindreplacedialog-class"></a>Classe CFindReplaceDialog
Permite que você implementar caixas de diálogo Localizar/Substituir padrão de cadeia de caracteres em seu aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CFindReplaceDialog : public CCommonDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFindReplaceDialog::CFindReplaceDialog](#cfindreplacedialog)|Chame essa função para construir uma `CFindReplaceDialog` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFindReplaceDialog::Create](#create)|Cria e exibe um `CFindReplaceDialog` caixa de diálogo.|  
|[CFindReplaceDialog::FindNext](#findnext)|Chame essa função para determinar se o usuário deseja localizar a próxima ocorrência da cadeia de caracteres de localização.|  
|[CFindReplaceDialog::GetFindString](#getfindstring)|Chame essa função para recuperar a cadeia de caracteres de localização atual.|  
|[CFindReplaceDialog::GetNotifier](#getnotifier)|Chame essa função para recuperar o **FINDREPLACE** estrutura em seu manipulador de mensagens registradas.|  
|[CFindReplaceDialog::GetReplaceString](#getreplacestring)|Chame essa função para recuperar a cadeia de caracteres de substituição atual.|  
|[CFindReplaceDialog::IsTerminating](#isterminating)|Chame essa função para determinar se a caixa de diálogo está sendo encerrado.|  
|[CFindReplaceDialog::MatchCase](#matchcase)|Chame essa função para determinar se o usuário deseja corresponder o caso da cadeia de caracteres localizar exatamente.|  
|[CFindReplaceDialog::MatchWholeWord](#matchwholeword)|Chame essa função para determinar se o usuário deseja corresponder somente palavras inteiras.|  
|[CFindReplaceDialog::ReplaceAll](#replaceall)|Chame essa função para determinar se o usuário deseja que todas as ocorrências da cadeia de caracteres a ser substituído.|  
|[CFindReplaceDialog::ReplaceCurrent](#replacecurrent)|Chame essa função para determinar se o usuário deseja que a palavra atual a ser substituído.|  
|[CFindReplaceDialog::SearchDown](#searchdown)|Chame essa função para determinar se o usuário deseja que a pesquisa seja feita em uma direção para baixo.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFindReplaceDialog::m_fr](#m_fr)|Uma estrutura usada para personalizar um `CFindReplaceDialog` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Ao contrário de outras Windows caixas de diálogo comuns, `CFindReplaceDialog` objetos são sem janela restrita, permitindo que os usuários interajam com outras janelas enquanto estiverem na tela. Há dois tipos de `CFindReplaceDialog` objetos: localizar caixas de diálogo e caixas de diálogo Localizar/Substituir. Embora as caixas de diálogo permitem que o usuário pesquisa de entrada e pesquisa/substituir cadeias de caracteres, elas não executam a pesquisa ou substituição de funções. Você deve adicioná-los ao aplicativo.  
  
 Para construir um `CFindReplaceDialog` de objeto, use o construtor fornecido (que não possui argumentos). Como essa é uma caixa de diálogo sem janela restrita, alocar o objeto no heap usando o **novo** operador, em vez de na pilha.  
  
 Uma vez um `CFindReplaceDialog` objeto foi construído, você deve chamar o [criar](#create) função de membro para criar e exibir a caixa de diálogo.  
  
 Use o [m_fr](#m_fr) estrutura para inicializar a caixa de diálogo antes de chamar **criar**. O `m_fr` estrutura é do tipo [FINDREPLACE](http://msdn.microsoft.com/library/windows/desktop/ms646835). Para obter mais informações sobre essa estrutura, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para a janela pai ser notificado de localizar/substituir solicitações, você deve usar o Windows [RegisterWindowMessage](http://msdn.microsoft.com/library/windows/desktop/ms644947) de função e usar o [ON_REGISTERED_MESSAGE](http://msdn.microsoft.com/library/93c1c068-ae8c-4e04-8a60-a603800ab57d) macros de mapa de mensagem na janela do quadro que lida com essa mensagem registrada.  
  
 Você pode determinar se o usuário decidiu encerrar a caixa de diálogo com o `IsTerminating` função de membro.  
  
 `CFindReplaceDialog`depende do COMMDLG. Arquivo DLL que acompanha o Windows versões 3.1 e posteriores.  
  
 Para personalizar a caixa de diálogo, derive uma classe de `CFindReplaceDialog`, fornecer um modelo de caixa de diálogo personalizada e adicionar um mapa da mensagem para processar as mensagens de notificação de controles estendidos. Todas as mensagens não processadas devem ser passadas para a classe base.  
  
 Personalizando a função de gancho não é necessária.  
  
 Para obter mais informações sobre como usar o `CFindReplaceDialog`, consulte [Classes comuns do diálogo](../../mfc/common-dialog-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 `CFindReplaceDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdlgs. h  
  
##  <a name="a-namecfindreplacedialoga--cfindreplacedialogcfindreplacedialog"></a><a name="cfindreplacedialog"></a>CFindReplaceDialog::CFindReplaceDialog  
 Constrói um objeto `CFindReplaceDialog`.  
  
```  
CFindReplaceDialog();
```  
  
### <a name="remarks"></a>Comentários  
 Porque o `CFindReplaceDialog` objeto é uma caixa de diálogo sem janela restrita, você deve construi-lo no heap usando o `new` operador.  
  
 Durante a destruição, o framework tenta executar um `delete this` no ponteiro à caixa de diálogo. Se você tiver criado a caixa de diálogo na pilha, o `this` ponteiro não existir e poderá ocorrer um comportamento indefinido.  
  
 Para obter mais informações sobre a construção de `CFindReplaceDialog` objetos, consulte o [CFindReplaceDialog](../../mfc/reference/cfindreplacedialog-class.md) visão geral. Use o [CFindReplaceDialog::Create](#create) a função de membro para exibir a caixa de diálogo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#170;](../../mfc/codesnippet/cpp/cfindreplacedialog-class_1.cpp)]  
  
##  <a name="a-namecreatea--cfindreplacedialogcreate"></a><a name="create"></a>CFindReplaceDialog::Create  
 Cria e exibe uma localização ou localizar/substituir caixa objeto dialog, dependendo do valor de `bFindDialogOnly`.  
  
```  
virtual BOOL Create(
    BOOL bFindDialogOnly,  
    LPCTSTR lpszFindWhat,  
    LPCTSTR lpszReplaceWith = NULL,  
    DWORD dwFlags = FR_DOWN,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bFindDialogOnly`  
 Definir esse parâmetro como `TRUE` para exibir uma **localizar** caixa de diálogo. Defina-o como `FALSE` para exibir uma **localizar/substituir** caixa de diálogo.  
  
 `lpszFindWhat`  
 Ponteiro para a cadeia de pesquisa padrão quando a caixa de diálogo é exibida. Se `NULL`, a caixa de diálogo não contém uma cadeia de caracteres de pesquisa padrão.  
  
 `lpszReplaceWith`  
 Ponteiro para a cadeia de caracteres de substituição de padrão quando a caixa de diálogo é exibida. Se `NULL`, a caixa de diálogo não contém uma cadeia de caracteres de substituição padrão.  
  
 `dwFlags`  
 Um ou mais sinalizadores que você pode usar para personalizar as configurações da caixa de diálogo, combinadas com o operador OR bit a bit. O valor padrão é `FR_DOWN`, que especifica que a pesquisa continue em uma direção para baixo. Consulte o [FINDREPLACE](http://msdn.microsoft.com/library/windows/desktop/ms646835) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações sobre esses sinalizadores.  
  
 `pParentWnd`  
 Um ponteiro para a janela do pai ou o proprietário da caixa de diálogo. Esta é a janela que receberá a mensagem especial que indica que uma ação de localizar/substituir é solicitada. Se `NULL`, a janela principal do aplicativo é usada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto de caixa de diálogo foi criado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para a janela pai ser notificado de localizar/substituir solicitações, você deve usar o Windows [RegisterWindowMessage](http://msdn.microsoft.com/library/windows/desktop/ms644947) função cujo valor de retorno é um número exclusivo para a instância do aplicativo. A janela de quadro deve ter uma entrada de mapa de mensagem que declara a função de retorno de chamada ( `OnFindReplace` no exemplo a seguir) que lida com essa mensagem registrada. O fragmento de código a seguir é um exemplo de como fazer isso para uma classe de janela de quadro chamada `CMyRichEditView`:  
  
 [!code-cpp[NVC_MFCDocView&#171;](../../mfc/codesnippet/cpp/cfindreplacedialog-class_2.h)]  
  
 [!code-cpp[NVC_MFCDocView&#172;](../../mfc/codesnippet/cpp/cfindreplacedialog-class_3.cpp)]  
  
 [!code-cpp[NVC_MFCDocView&#173;](../../mfc/codesnippet/cpp/cfindreplacedialog-class_4.cpp)]  
  
 Dentro de seu `OnFindReplace` função, interpretar as intenções do usuário usando o [CFindReplaceDialog::FindNext](#findnext) e [CFindReplaceDialog::IsTerminating](#isterminating) métodos e você cria o código para as operações de localizar/substituir.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CFindReplaceDialog::CFindReplaceDialog](#cfindreplacedialog).  
  
##  <a name="a-namefindnexta--cfindreplacedialogfindnext"></a><a name="findnext"></a>CFindReplaceDialog::FindNext  
 Chame essa função de sua função de retorno de chamada para determinar se o usuário deseja localizar a próxima ocorrência da cadeia de pesquisa.  
  
```  
BOOL FindNext() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário deseja localizar a próxima ocorrência da cadeia de pesquisa; Caso contrário, 0.  
  
##  <a name="a-namegetfindstringa--cfindreplacedialoggetfindstring"></a><a name="getfindstring"></a>CFindReplaceDialog::GetFindString  
 Chame essa função de sua função de retorno de chamada para recuperar a cadeia de caracteres padrão para localizar.  
  
```  
CString GetFindString() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cadeia de caracteres do padrão para localizar.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#69;](../../mfc/codesnippet/cpp/cfindreplacedialog-class_5.cpp)]  
  
##  <a name="a-namegetnotifiera--cfindreplacedialoggetnotifier"></a><a name="getnotifier"></a>CFindReplaceDialog::GetNotifier  
 Chame essa função para recuperar um ponteiro para a caixa de diálogo Localizar Substituir atual.  
  
```  
static CFindReplaceDialog* PASCAL GetNotifier(LPARAM lParam);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lParam`  
 O **lparam** valor passado para a janela de quadro **OnFindReplace** função de membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a caixa de diálogo atual.  
  
### <a name="remarks"></a>Comentários  
 Ele deve ser usado dentro de sua função de retorno de chamada para acessar a caixa de diálogo atual, chame o membro de funções e acesso a `m_fr` estrutura.  
  
### <a name="example"></a>Exemplo  
 Consulte [CFindReplaceDialog::Create](#create) para obter um exemplo de como registrar o manipulador OnFindReplace para receber notificações de caixa de diálogo Localizar Substituir.  
  
 [!code-cpp[NVC_MFCDocView&#69;](../../mfc/codesnippet/cpp/cfindreplacedialog-class_5.cpp)]  
  
##  <a name="a-namegetreplacestringa--cfindreplacedialoggetreplacestring"></a><a name="getreplacestring"></a>CFindReplaceDialog::GetReplaceString  
 Chame essa função para recuperar a cadeia de caracteres de substituição atual.  
  
```  
CString GetReplaceString() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cadeia de caracteres de padrão com o qual substituir cadeias de caracteres encontradas.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CFindReplaceDialog::GetFindString](#getfindstring).  
  
##  <a name="a-nameisterminatinga--cfindreplacedialogisterminating"></a><a name="isterminating"></a>CFindReplaceDialog::IsTerminating  
 Chame essa função em sua função de retorno de chamada para determinar se o usuário decidiu encerrar a caixa de diálogo.  
  
```  
BOOL IsTerminating() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário optou por encerrar a caixa de diálogo. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se essa função retorna zero, você deve chamar o `DestroyWindow` a função de membro da caixa de diálogo atual e conjunto de qualquer caixa de diálogo caixa variável de ponteiro para **nulo**. Opcionalmente, você também pode armazenar localizar/substituir texto última inserido e usá-lo para inicializar a caixa de diálogo Localizar/Substituir próxima.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CFindReplaceDialog::GetFindString](#getfindstring).  
  
##  <a name="a-namemfra--cfindreplacedialogmfr"></a><a name="m_fr"></a>CFindReplaceDialog::m_fr  
 Usado para personalizar um `CFindReplaceDialog` objeto.  
  
```  
FINDREPLACE m_fr;  
```  
  
### <a name="remarks"></a>Comentários  
 `m_fr`é uma estrutura de tipo [FINDREPLACE](http://msdn.microsoft.com/library/windows/desktop/ms646835). Seus membros armazenam as características do objeto de caixa de diálogo. Depois de criar um `CFindReplaceDialog` do objeto, você pode usar `m_fr` para modificar vários valores na caixa de diálogo.  
  
 Para obter mais informações sobre essa estrutura, consulte o **FINDREPLACE** estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CFindReplaceDialog::CFindReplaceDialog](#cfindreplacedialog).  
  
##  <a name="a-namematchcasea--cfindreplacedialogmatchcase"></a><a name="matchcase"></a>CFindReplaceDialog::MatchCase  
 Chame essa função para determinar se o usuário deseja corresponder o caso da cadeia de caracteres localizar exatamente.  
  
```  
BOOL MatchCase() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário desejar localizar ocorrências da cadeia de caracteres de pesquisa que correspondem exatamente a ocorrência da cadeia de pesquisa; Caso contrário, 0.  
  
##  <a name="a-namematchwholeworda--cfindreplacedialogmatchwholeword"></a><a name="matchwholeword"></a>CFindReplaceDialog::MatchWholeWord  
 Chame essa função para determinar se o usuário deseja corresponder somente palavras inteiras.  
  
```  
BOOL MatchWholeWord() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário deseja corresponder somente as palavras inteiras da cadeia de pesquisa; Caso contrário, 0.  
  
##  <a name="a-namereplacealla--cfindreplacedialogreplaceall"></a><a name="replaceall"></a>CFindReplaceDialog::ReplaceAll  
 Chame essa função para determinar se o usuário deseja que todas as ocorrências da cadeia de caracteres a ser substituído.  
  
```  
BOOL ReplaceAll() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário solicitou que todas as cadeias de caracteres correspondentes a cadeia de caracteres de substituição seja substituído; Caso contrário, 0.  
  
##  <a name="a-namereplacecurrenta--cfindreplacedialogreplacecurrent"></a><a name="replacecurrent"></a>CFindReplaceDialog::ReplaceCurrent  
 Chame essa função para determinar se o usuário deseja que a palavra atual a ser substituído.  
  
```  
BOOL ReplaceCurrent() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário solicitou que a cadeia de caracteres selecionada no momento seja substituído com a cadeia de caracteres de substituição; Caso contrário, 0.  
  
##  <a name="a-namesearchdowna--cfindreplacedialogsearchdown"></a><a name="searchdown"></a>CFindReplaceDialog::SearchDown  
 Chame essa função para determinar se o usuário deseja que a pesquisa seja feita em uma direção para baixo.  
  
```  
BOOL SearchDown() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário deseja que a pesquisa seja feita em uma direção para baixo; 0 se o usuário deseja que a pesquisa seja feita em uma direção para cima.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)  

