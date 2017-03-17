---
title: Classe CUserTool | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CUserTool
- AFXUSERTOOL/CUserTool
- AFXUSERTOOL/CUserTool::CopyIconToClipboard
- AFXUSERTOOL/CUserTool::DrawToolIcon
- AFXUSERTOOL/CUserTool::GetCommand
- AFXUSERTOOL/CUserTool::GetCommandId
- AFXUSERTOOL/CUserTool::Invoke
- AFXUSERTOOL/CUserTool::Serialize
- AFXUSERTOOL/CUserTool::SetCommand
- AFXUSERTOOL/CUserTool::SetToolIcon
- AFXUSERTOOL/CUserTool::LoadDefaultIcon
- AFXUSERTOOL/CUserTool::m_strArguments
- AFXUSERTOOL/CUserTool::m_strInitialDirectory
- AFXUSERTOOL/CUserTool::m_strLabel
dev_langs:
- C++
helpviewer_keywords:
- CUserTool class
ms.assetid: 7c287d3e-d012-488d-b4e1-aa0f83f294bb
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
ms.openlocfilehash: 2e0b082be6aac7314d8251f89b42ed09e44e2f3d
ms.lasthandoff: 02/25/2017

---
# <a name="cusertool-class"></a>Classe CUserTool
Uma ferramenta de usuário é um item de menu que executa um aplicativo externo. O **ferramentas** guia o **personalizar** caixa de diálogo ( [CMFCToolBarsCustomizeDialog classe](../../mfc/reference/cmfctoolbarscustomizedialog-class.md)) permite que o usuário adicionar ferramentas de usuário e para especificar o nome do comando, argumentos e diretório inicial para cada ferramenta de usuário.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CUserTool : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CUserTool::CopyIconToClipboard](#copyicontoclipboard)||  
|[CUserTool::DrawToolIcon](#drawtoolicon)|Desenha o ícone de ferramenta do usuário em um retângulo especificado.|  
|[CUserTool::GetCommand](#getcommand)|Retorna uma cadeia de caracteres que contém o texto do comando associado com a ferramenta do usuário.|  
|[CUserTool::GetCommandId](#getcommandid)|Retorna a ID de comando do item de menu da ferramenta de usuário.|  
|[CUserTool::Invoke](#invoke)|Executa o comando associado com a ferramenta do usuário.|  
|[CUserTool::Serialize](#serialize)|Lê ou grava este objeto de ou para um arquivo morto. (Substitui [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize).)|  
|[CUserTool::SetCommand](#setcommand)|Define o comando associado com a ferramenta do usuário.|  
|[CUserTool::SetToolIcon](#settoolicon)|Carrega o ícone para a ferramenta do usuário do aplicativo associado com a ferramenta.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CUserTool::LoadDefaultIcon](#loaddefaulticon)|Carrega o ícone padrão para uma ferramenta de usuário.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CUserTool::m_strArguments](#m_strarguments)|Os argumentos de linha de comando para a ferramenta do usuário.|  
|[CUserTool::m_strInitialDirectory](#m_strinitialdirectory)|O diretório inicial para a ferramenta do usuário.|  
|[CUserTool::m_strLabel](#m_strlabel)|O nome da ferramenta que é exibido no item de menu para a ferramenta.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações sobre como habilitar ferramentas do usuário em seu aplicativo, consulte [CUserToolsManager classe](../../mfc/reference/cusertoolsmanager-class.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar uma ferramenta de um `CUserToolsManager` do objeto, defina o `m_strLabel` variável de membro e defina o aplicativo que executa a ferramenta de usuário. Este trecho de código é parte do [exemplo de demonstração do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo&#35;](../../mfc/codesnippet/cpp/cusertool-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CUserTool](../../mfc/reference/cusertool-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxusertool.h  
  
##  <a name="copyicontoclipboard"></a>CUserTool::CopyIconToClipboard  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL CopyIconToClipboard();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="drawtoolicon"></a>CUserTool::DrawToolIcon  
 Desenha o ícone de ferramenta do usuário no Centro de um retângulo especificado.  
  
```  
void DrawToolIcon(
    CDC* pDC,  
    const CRect& rectImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rectImage`  
 Especifica as coordenadas da área para exibir o ícone.  
  
##  <a name="getcommand"></a>CUserTool::GetCommand  
 Retorna uma cadeia de caracteres que contém o texto do comando associado com a ferramenta do usuário.  
  
```  
const CString& GetCommand() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a `CString` objeto que contém o texto do comando associado com a ferramenta do usuário.  
  
##  <a name="getcommandid"></a>CUserTool::GetCommandId  
 Retorna a ID de comando da ferramenta de usuário.  
  
```  
UINT GetCommandId() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A ID de comando dessa ferramenta do usuário.  
  
##  <a name="invoke"></a>CUserTool::Invoke  
 Executa o comando associado com a ferramenta do usuário.  
  
```  
virtual BOOL Invoke();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o comando foi executado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chamadas [ShellExecute](http://msdn.microsoft.com/library/windows/desktop/bb762153) para executar um comando associado com a ferramenta do usuário. A função falhará se o comando estiver vazio ou se [ShellExecute](http://msdn.microsoft.com/library/windows/desktop/bb762153) falhar.  
  
##  <a name="loaddefaulticon"></a>CUserTool::LoadDefaultIcon  
 Carrega o ícone padrão para uma ferramenta de usuário.  
  
```  
virtual HICON LoadDefaultIcon();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o ícone carregado ( `HICON`), ou `NULL` se o ícone padrão não pode ser carregado.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando não é possível carregar um ícone de uma ferramenta definida pelo usuário do arquivo executável da ferramenta.  
  
 Substitui esse método para fornecer seu próprio ícone padrão da ferramenta.  
  
##  <a name="m_strarguments"></a>CUserTool::m_strArguments  
 Os argumentos de linha de comando para a ferramenta do usuário.  
  
```  
CString m_strArguments;  
```  
  
### <a name="remarks"></a>Comentários  
 Essa cadeia de caracteres é passada para a ferramenta quando você chama [CUserTool::Invoke](#invoke) ou quando um usuário clica o comando associado a essa ferramenta.  
  
##  <a name="m_strinitialdirectory"></a>CUserTool::m_strInitialDirectory  
 Especifica o diretório inicial para a ferramenta do usuário.  
  
```  
CString m_strInitialDirectory;  
```  
  
### <a name="remarks"></a>Comentários  
 Essa variável Especifica o diretório inicial que a ferramenta é executada quando você chamar [CUserTool::Invoke](#invoke) ou quando um usuário clica o comando associado a essa ferramenta.  
  
##  <a name="m_strlabel"></a>CUserTool::m_strLabel  
 O rótulo que é exibido no item de menu para a ferramenta.  
  
```  
CString m_strLabel;  
```  
  
##  <a name="serialize"></a>CUserTool::Serialize  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void Serialize(CArchive& ar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `ar`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setcommand"></a>CUserTool::SetCommand  
 Define o aplicativo que executa a ferramenta de usuário.  
  
```  
void SetCommand(LPCTSTR lpszCmd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszCmd`  
 Especifica o novo aplicativo a ser associado com a ferramenta do usuário.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para definir um novo aplicativo que executa a ferramenta de usuário. O método destrói o ícone antigo e carrega um novo ícone de determinado aplicativo. Se ele não é possível carregar um ícone do aplicativo, ele carrega o ícone padrão para uma ferramenta do usuário chamando [CUserTool::LoadDefaultIcon](#loaddefaulticon).  
  
##  <a name="settoolicon"></a>CUserTool::SetToolIcon  
 Carrega o ícone para a ferramenta do usuário do aplicativo que usa a ferramenta.  
  
```  
virtual HICON SetToolIcon();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o ícone carregado.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para carregar o ícone a ser exibido no item de menu. Este método pesquisa o ícone no arquivo executável que usa a ferramenta. Se ele não tem um ícone padrão, o ícone fornecido pelo [CUserTool::LoadDefaultIcon](#loaddefaulticon) será usado.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe de CWinAppEx](../../mfc/reference/cwinappex-class.md)   
 [Classe CUserToolsManager](../../mfc/reference/cusertoolsmanager-class.md)

