---
title: Classe CUserTool | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
- CUserTool [MFC], CopyIconToClipboard
- CUserTool [MFC], DrawToolIcon
- CUserTool [MFC], GetCommand
- CUserTool [MFC], GetCommandId
- CUserTool [MFC], Invoke
- CUserTool [MFC], Serialize
- CUserTool [MFC], SetCommand
- CUserTool [MFC], SetToolIcon
- CUserTool [MFC], LoadDefaultIcon
- CUserTool [MFC], m_strArguments
- CUserTool [MFC], m_strInitialDirectory
- CUserTool [MFC], m_strLabel
ms.assetid: 7c287d3e-d012-488d-b4e1-aa0f83f294bb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ac2820757cd2adc120a3c2075fc6b0d5d8bcbd82
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50069744"
---
# <a name="cusertool-class"></a>Classe CUserTool

Uma ferramenta de usuário é um item de menu que executa um aplicativo externo. O **ferramentas** guia o **personalizar** caixa de diálogo ( [classe CMFCToolBarsCustomizeDialog](../../mfc/reference/cmfctoolbarscustomizedialog-class.md)) permite que o usuário adicione ferramentas de usuário e especifique o nome, o comando, argumentos, e diretório inicial para cada ferramenta de usuário.

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
|[CUserTool::GetCommand](#getcommand)|Retorna uma cadeia de caracteres que contém o texto do comando associado com a ferramenta de usuário.|
|[CUserTool::GetCommandId](#getcommandid)|Retorna a ID de comando do item de menu da ferramenta de usuário.|
|[CUserTool::Invoke](#invoke)|Executa o comando associado com a ferramenta de usuário.|
|[CUserTool::Serialize](#serialize)|Lê ou grava este objeto de ou para um arquivo morto. (Substitui [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize).)|
|[CUserTool::SetCommand](#setcommand)|Define o comando associado com a ferramenta de usuário.|
|[CUserTool::SetToolIcon](#settoolicon)|Carrega o ícone para a ferramenta de usuário do aplicativo associado com a ferramenta.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CUserTool::LoadDefaultIcon](#loaddefaulticon)|Carrega o ícone padrão para uma ferramenta de usuário.|

### <a name="data-members"></a>Membros de Dados

|Nome|Descrição|
|----------|-----------------|
|[CUserTool::m_strArguments](#m_strarguments)|Os argumentos de linha de comando para a ferramenta de usuário.|
|[CUserTool::m_strInitialDirectory](#m_strinitialdirectory)|O diretório inicial para a ferramenta de usuário.|
|[CUserTool::m_strLabel](#m_strlabel)|O nome da ferramenta que é exibido no item de menu para a ferramenta.|

## <a name="remarks"></a>Comentários

Para obter mais informações sobre como habilitar as ferramentas de usuário em seu aplicativo, consulte [classe CUserToolsManager](../../mfc/reference/cusertoolsmanager-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como criar uma ferramenta de um `CUserToolsManager` do objeto, defina o `m_strLabel` variável de membro e defina o aplicativo que executa a ferramenta de usuário. Este trecho de código faz parte do [amostra de demonstração do Visual Studio](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#35](../../mfc/codesnippet/cpp/cusertool-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CUserTool](../../mfc/reference/cusertool-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxusertool.h

##  <a name="copyicontoclipboard"></a>  CUserTool::CopyIconToClipboard

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

```
BOOL CopyIconToClipboard();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="drawtoolicon"></a>  CUserTool::DrawToolIcon

Desenha o ícone de ferramenta do usuário no Centro de um retângulo especificado.

```
void DrawToolIcon(
    CDC* pDC,
    const CRect& rectImage);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Um ponteiro para um contexto de dispositivo.

*rectImage*<br/>
[in] Especifica as coordenadas da área para exibir o ícone.

##  <a name="getcommand"></a>  CUserTool::GetCommand

Retorna uma cadeia de caracteres que contém o texto do comando associado com a ferramenta de usuário.

```
const CString& GetCommand() const;
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao `CString` objeto que contém o texto do comando associado com a ferramenta de usuário.

##  <a name="getcommandid"></a>  CUserTool::GetCommandId

Retorna a ID de comando da ferramenta de usuário.

```
UINT GetCommandId() const;
```

### <a name="return-value"></a>Valor de retorno

A ID de comando da ferramenta usuário.

##  <a name="invoke"></a>  CUserTool::Invoke

Executa o comando associado com a ferramenta de usuário.

```
virtual BOOL Invoke();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o comando foi executado com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Chamadas [ShellExecute](/windows/desktop/api/shellapi/nf-shellapi-shellexecutea) para executar um comando associado com a ferramenta de usuário. A função falhará se o comando está vazio ou se [ShellExecute](/windows/desktop/api/shellapi/nf-shellapi-shellexecutea) falhar.

##  <a name="loaddefaulticon"></a>  CUserTool::LoadDefaultIcon

Carrega o ícone padrão para uma ferramenta de usuário.

```
virtual HICON LoadDefaultIcon();
```

### <a name="return-value"></a>Valor de retorno

Um identificador para o ícone carregado (HICON), ou nulo se o ícone padrão não pode ser carregado.

### <a name="remarks"></a>Comentários

O framework chama esse método quando não é possível carregar um ícone para uma ferramenta definida pelo usuário a partir do arquivo executável da ferramenta.

Substitua este método para fornecer seu próprio ícone padrão da ferramenta.

##  <a name="m_strarguments"></a>  CUserTool::m_strArguments

Os argumentos de linha de comando para a ferramenta de usuário.

```
CString m_strArguments;
```

### <a name="remarks"></a>Comentários

Essa cadeia de caracteres é passada para a ferramenta quando você chama [CUserTool::Invoke](#invoke) ou quando um usuário clica o comando associado a essa ferramenta.

##  <a name="m_strinitialdirectory"></a>  CUserTool::m_strInitialDirectory

Especifica o diretório inicial para a ferramenta de usuário.

```
CString m_strInitialDirectory;
```

### <a name="remarks"></a>Comentários

Essa variável Especifica o diretório inicial que a ferramenta é executada quando você chamar [CUserTool::Invoke](#invoke) ou quando um usuário clica o comando associado a essa ferramenta.

##  <a name="m_strlabel"></a>  CUserTool::m_strLabel

O rótulo que é exibido no item de menu para a ferramenta.

```
CString m_strLabel;
```

##  <a name="serialize"></a>  CUserTool::Serialize

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

```
virtual void Serialize(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

[in] *ar*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setcommand"></a>  CUserTool::SetCommand

Define o aplicativo que executa a ferramenta de usuário.

```
void SetCommand(LPCTSTR lpszCmd);
```

### <a name="parameters"></a>Parâmetros

*lpszCmd*<br/>
[in] Especifica o novo aplicativo a ser associado com a ferramenta de usuário.

### <a name="remarks"></a>Comentários

Chame esse método para definir um novo aplicativo que executa a ferramenta de usuário. O método destrói o ícone antigo e carrega um novo ícone do aplicativo determinado. Se ele não é possível carregar um ícone do aplicativo, ele carrega o ícone padrão para uma ferramenta do usuário chamando [CUserTool::LoadDefaultIcon](#loaddefaulticon).

##  <a name="settoolicon"></a>  CUserTool::SetToolIcon

Carrega o ícone para a ferramenta de usuário do aplicativo que usa a ferramenta.

```
virtual HICON SetToolIcon();
```

### <a name="return-value"></a>Valor de retorno

Um identificador para o ícone carregado.

### <a name="remarks"></a>Comentários

Chame esse método para carregar o ícone a ser exibido no item de menu. Esse método pesquisará o ícone no arquivo executável que usa a ferramenta. Se ele não tem um ícone padrão, o ícone fornecido pelo [CUserTool::LoadDefaultIcon](#loaddefaulticon) é usado em vez disso.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CWinAppEx](../../mfc/reference/cwinappex-class.md)<br/>
[Classe CUserToolsManager](../../mfc/reference/cusertoolsmanager-class.md)
