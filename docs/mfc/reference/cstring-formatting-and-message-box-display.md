---
title: Formatação CString e exibição da caixa de mensagem | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.mfc.macros.strings
dev_langs:
- C++
helpviewer_keywords:
- CString objects [MFC], formatting and message boxes
ms.assetid: d1068cf4-9cc5-4952-b9e7-d612c53cbc28
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 125d0d3ec1549b9eba46cbfebfb7ecfe2c2186d9
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46387168"
---
# <a name="cstring-formatting-and-message-box-display"></a>Formatação CString e exibição da caixa de mensagem

Um número de funções é fornecido para formatar e analisar `CString` objetos. Você pode usar essas funções sempre que você tiver que manipular `CString` objetos, mas eles são particularmente úteis para formatação de cadeias de caracteres que serão exibido no texto da caixa de mensagem.

Esse grupo de funções também inclui uma rotina global para exibir uma caixa de mensagem.

### <a name="cstring-functions"></a>Funções de CString

|||
|-|-|
|[AfxExtractSubString](#afxextractsubstring)|Extrai as subcadeias de caracteres separadas por um único caractere de uma cadeia de caracteres de origem especificado.|
|[AfxFormatString1](#afxformatstring1)|Substitui uma determinada cadeia de caracteres de formato "%1" em uma cadeia de caracteres contidos na tabela de cadeia de caracteres.|
|[AfxFormatString2](#afxformatstring2)|Cadeias de caracteres substitutos duas para o formato de caracteres "%1" e "%2" em uma cadeia de caracteres contidos na tabela de cadeia de caracteres.|
|[AfxMessageBox](#afxmessagebox)|Exibe uma caixa de mensagem.|

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin. h

##  <a name="afxextractsubstring"></a>  AfxExtractSubString

Essa função global pode ser usada para extrair uma subcadeia de caracteres de uma cadeia de caracteres de origem especificado.

```
BOOL AFXAPI AfxExtractSubString (
    CString& rString,
    LPCTSTR lpszFullString,
    int iSubString,
    TCHAR chSep  = '\n');
```

### <a name="parameters"></a>Parâmetros

*rString*<br/>
Referência a um [CString](../../atl-mfc-shared/using-cstring.md) objeto que receberá uma subcadeia de caracteres individual.

*lpszFullString*<br/>
Cadeia de caracteres que contém o texto completo da cadeia de caracteres para extrair de.

*iSubString*<br/>
O índice baseado em zero da subcadeia de caracteres para extrair *lpszFullString*.

*chSep*<br/>
Caractere separador usado para delimitar as subcadeias de caracteres.

### <a name="return-value"></a>Valor de retorno

TRUE se a função extraída com êxito a subcadeia de caracteres no índice fornecido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Essa função é útil para extrair várias subcadeias de caracteres de uma cadeia de caracteres de origem quando um único caractere conhecido separa cada subcadeia de caracteres. Essa função pesquisa desde o início do *lpszFullString* parâmetro toda vez que é chamado.

Essa função retornará FALSE se algum *lpszFullString* é definido como NULL ou a função atinge o final do *lpszFullString* sem Localizando *iSubString*+ 1 ocorrências do caractere separador especificado. O *rString* parâmetro não será modificado de seu valor original se *lpszFullString* foi definido como nulo; caso contrário, o *rString* parâmetro for definido como a cadeia de caracteres vazia se não foi possível extrair a subcadeia de caracteres para o índice especificado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#48](../../mfc/codesnippet/cpp/cstring-formatting-and-message-box-display_1.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin. h

##  <a name="afxformatstring1"></a>  AfxFormatString1

Substitui a cadeia de caracteres apontada por *lpsz1* para todas as instâncias dos caracteres "%1" no recurso de cadeia de caracteres de modelo identificada pelo *nIDS*.

```
void  AfxFormatString1(
    CString& rString,
    UINT nIDS,
    LPCTSTR lpsz1);
```

### <a name="parameters"></a>Parâmetros

*rString*<br/>
Uma referência a um `CString` objeto que contém a cadeia de caracteres resultante após a substituição é executada.

*nIDS*<br/>
A ID de recurso da cadeia de caracteres de modelo no qual a substituição será executada.

*lpsz1*<br/>
Uma cadeia de caracteres que substituirá o formato de caracteres "%1" na cadeia de caracteres de modelo.

### <a name="remarks"></a>Comentários

A cadeia de caracteres recém-criado é armazenada no *rString*. Por exemplo, se a cadeia de caracteres na tabela de cadeia de caracteres é "File %1 não encontrado", e *lpsz1* é igual a "C:\MYFILE. TXT", em seguida *rString* conterá a cadeia de caracteres"File C:\MYFILE. TXT não encontrado". Essa função é útil para formatação de cadeias de caracteres enviadas para caixas de mensagem e outras janelas.

Se os caracteres de formato "%1" aparecem mais de uma vez na cadeia de caracteres, serão feitas várias substituições.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#25](../../mfc/codesnippet/cpp/cstring-formatting-and-message-box-display_2.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin. h

##  <a name="afxformatstring2"></a>  AfxFormatString2

Substitui a cadeia de caracteres apontada por *lpsz1* para todas as instâncias dos caracteres "%1" e a cadeia de caracteres apontada por *lpsz2* para todas as instâncias dos caracteres "%2", em que o recurso de cadeia de caracteres de modelo identificado pelo *nIDS*.

```
void AfxFormatString2(
    CString& rString,
    UINT nIDS,
    LPCTSTR lpsz1,
    LPCTSTR lpsz2);
```

### <a name="parameters"></a>Parâmetros

*rString*<br/>
Uma referência para o `CString` que conterá a cadeia de caracteres resultante após a substituição é executada.

*nIDS*<br/>
A ID da tabela de cadeia de caracteres da cadeia de caracteres de modelo no qual a substituição será executada.

*lpsz1*<br/>
Uma cadeia de caracteres que substituirá o formato de caracteres "%1" na cadeia de caracteres de modelo.

*lpsz2*<br/>
Uma cadeia de caracteres que substituirá o formato de caracteres "%2" na cadeia de caracteres de modelo.

### <a name="remarks"></a>Comentários

A cadeia de caracteres recém-criado é armazenada no *rString*. Por exemplo, se a cadeia de caracteres na tabela de cadeia de caracteres é "File %1 não encontrado no diretório %2", *lpsz1* aponta para "MYFILE. TXT", e *lpsz2* aponta para"C:\MYDIR", em seguida, *rString* conterá a cadeia de caracteres"arquivo MYFILE. TXT não encontrado no diretório C:\MYDIR"

Se o formato de caracteres "%1" ou "%2" são exibidos mais de uma vez na cadeia de caracteres, serão feitas várias substituições. Eles não precisam estar em ordem numérica.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#26](../../mfc/codesnippet/cpp/cstring-formatting-and-message-box-display_3.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin. h

##  <a name="afxmessagebox"></a>  AfxMessageBox

Exibe uma caixa de mensagem na tela.

```
int AfxMessageBox(
    LPCTSTR lpszText,
    UINT nType = MB_OK,
    UINT nIDHelp = 0);

int AFXAPI AfxMessageBox(
    UINT nIDPrompt,
    UINT nType = MB_OK,
    UINT nIDHelp = (UINT) -1);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Aponta para um `CString` objeto ou cadeia de caracteres terminada em nulo que contém a mensagem a ser exibido na caixa de mensagem.

*nType*<br/>
O estilo da caixa de mensagem. Aplicar qualquer um dos [estilos de caixa de mensagem](../../mfc/reference/styles-used-by-mfc.md#message-box-styles) à caixa.

*nIDHelp*<br/>
A ID de contexto de ajuda para a mensagem; 0 indica que o contexto da Ajuda do aplicativo padrão será usado.

*nIDPrompt*<br/>
Uma ID exclusiva usada para fazer referência a uma cadeia de caracteres na tabela de cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

Zero se não houver memória suficiente para exibir a caixa de mensagem. Caso contrário, um dos valores a seguir será retornado:

- IDABORT o botão anular foi selecionado.

- IDCANCEL o botão Cancelar foi selecionado.

- IDIGNORE o botão ignorar foi selecionado.

- IDNO o botão não foi selecionado.

- IDOK Okey do botão foi selecionado.

- IDRETRY o botão tentar novamente foi selecionado.

- IDYES o botão Sim foi selecionado.

Se uma caixa de mensagem tem um botão Cancelar, o valor IDCANCEL será retornado se a tecla ESC for pressionada ou o botão Cancelar é selecionado. Se a caixa de mensagem não tem nenhum botão Cancelar, pressionar a tecla ESC não terá efeito.

As funções [AfxFormatString1](#afxformatstring1) e [AfxFormatString2](#afxformatstring2) podem ser úteis em formatação de texto que aparece em uma caixa de mensagem.

### <a name="remarks"></a>Comentários

A primeira forma dessa função sobrecarregada exibe uma cadeia de caracteres de texto apontada por *lpszText* na caixa de mensagem e usa *nIDHelp* para descrever um contexto de Ajuda. O contexto da Ajuda é usado para saltar para um tópico de ajuda associado quando o usuário pressiona a tecla de Ajuda (normalmente F1).

A segunda forma da função usa o recurso de cadeia de caracteres com a ID *nIDPrompt* para exibir uma mensagem na caixa de mensagem. A página de ajuda associada é encontrada por meio do valor de *nIDHelp*. Se o valor padrão de *nIDHelp* é usado (-1), a ID de recurso de cadeia de caracteres *nIDPrompt*, é usado para o contexto da Ajuda. Para obter mais informações sobre como definir contextos da Ajuda, consulte [nota técnica 28](../../mfc/tn028-context-sensitive-help-support.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#133](../../mfc/reference/codesnippet/cpp/cstring-formatting-and-message-box-display_4.cpp)]

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)<br/>
[Classe CStringT](../../atl-mfc-shared/reference/cstringt-class.md)
