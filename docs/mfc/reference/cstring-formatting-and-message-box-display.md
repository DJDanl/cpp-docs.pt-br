---
title: "Formatação CString e exibição da caixa de mensagem | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros.strings
dev_langs:
- C++
helpviewer_keywords:
- CString objects, formatting and message boxes
ms.assetid: d1068cf4-9cc5-4952-b9e7-d612c53cbc28
caps.latest.revision: 14
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
ms.sourcegitcommit: 3d045736f9a54d344c67e3f7408198e65a0bc95f
ms.openlocfilehash: 356562dc61971aa7a74ce9e9be94fc34af58f6f9
ms.lasthandoff: 03/29/2017

---
# <a name="cstring-formatting-and-message-box-display"></a>Formatação CString e exibição da caixa de mensagem
Um número de funções é fornecido para formatar e analisar `CString` objetos. Você pode usar essas funções sempre que você tiver que manipular `CString` objetos, mas eles são particularmente úteis para a formatação de cadeias de caracteres que serão exibido na caixa de mensagem de texto.  
  
 Esse grupo de funções também inclui uma rotina global para exibir uma caixa de mensagem.  
  
### <a name="cstring-functions"></a>Funções de CString  
  
|||  
|-|-|  
|[AfxExtractSubString](#afxextractsubstring)|Extrai subcadeias de caracteres separadas por um único caractere de uma cadeia de caracteres de origem especificado.|  
|[AfxFormatString1](#afxformatstring1)|Substitui uma cadeia de caracteres fornecida para os caracteres de formato "%1" em uma cadeia de caracteres contidas na tabela de cadeia de caracteres.|  
|[AfxFormatString2](#afxformatstring2)|Cadeias de caracteres substitutos duas para o formato de caracteres "%1" e "%2" em uma cadeia de caracteres contidas na tabela de cadeia de caracteres.|  
|[AfxMessageBox](#afxmessagebox)|Exibe uma caixa de mensagem.|  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  
  
##  <a name="afxextractsubstring"></a>AfxExtractSubString  
 Essa função global pode ser usada para extrair uma subcadeia de caracteres de uma cadeia de caracteres de origem especificado.  
  
```   
BOOL AFXAPI AfxExtractSubString (
    CString& rString,  
    LPCTSTR lpszFullString,  
    int iSubString,  
    TCHAR chSep  = '\n'); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *rString*  
 -   Referência a um [CString](../../atl-mfc-shared/using-cstring.md) objeto que recebe uma subcadeia de caracteres individual.  
  
 *lpszFullString*  
 -   Cadeia de caracteres que contém o texto completo da cadeia de caracteres para extrair.  
  
 *iSubString*  
 -   Índice de base zero da subcadeia de caracteres para extrair *lpszFullString*.  
  
 *chSep*  
 -   Caractere separador usado para delimitar subcadeias de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se a função extraído com êxito a subcadeia de caracteres no índice fornecido; caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Essa função é útil para extrair vários subcadeias de caracteres de uma cadeia de caracteres de origem quando um único caractere conhecido separa cada subcadeia de caracteres. Essa função de pesquisa do início do `lpszFullString` parâmetro cada vez que ele é chamado.  
  
 Esta função retornará FALSE se `lpszFullString` é definido como **nulo** ou a função atinge o final do `lpszFullString` sem Localizando `iSubString`+ 1 ocorrências do caractere separador especificado. O `rString` parâmetro não será modificado de seu valor original se `lpszFullString` foi definida como **nulo**; caso contrário, o `rString` parâmetro for definido como a cadeia de caracteres vazia se não foi possível extrair a subcadeia de caracteres para o índice especificado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[48 NVC_MFC_Utilities](../../mfc/codesnippet/cpp/cstring-formatting-and-message-box-display_1.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  
  
##  <a name="afxformatstring1"></a>AfxFormatString1  
 Substitui a cadeia de caracteres apontada por `lpsz1` para todas as instâncias dos caracteres "%1" no recurso de cadeia de caracteres de modelo identificado por `nIDS`.  
  
```  
void  AfxFormatString1(
    CString& rString,  
    UINT nIDS,  
    LPCTSTR lpsz1); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `rString`  
 Uma referência a um `CString` objeto que contém a cadeia de caracteres resultante após a substituição é executada.  
  
 `nIDS`  
 A ID de recurso da cadeia de caracteres de modelo no qual a substituição será executada.  
  
 `lpsz1`  
 Uma cadeia de caracteres que substituirá o formato de caracteres "%1" na cadeia de caracteres de modelo.  
  
### <a name="remarks"></a>Comentários  
 A cadeia de caracteres recém-criado é armazenada em `rString`. Por exemplo, se a cadeia de caracteres na tabela de cadeia de caracteres é "File %1 não encontrado", e `lpsz1` é igual a "C:\MYFILE. TXT", em seguida, `rString` irá conter a cadeia de caracteres"arquivo C:\MYFILE. TXT não encontrado". Essa função é útil para formatação de cadeias de caracteres enviadas para caixas de mensagem e outras janelas.  
  
 Se os caracteres de formato "%1" aparecem mais de uma vez na cadeia de caracteres, várias substituições serão feitas.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[25 NVC_MFC_Utilities](../../mfc/codesnippet/cpp/cstring-formatting-and-message-box-display_2.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  
  
##  <a name="afxformatstring2"></a>AfxFormatString2  
 Substitui a cadeia de caracteres apontada por `lpsz1` para todas as instâncias dos caracteres "%1" e a cadeia de caracteres apontada por `lpsz2` para todas as instâncias de caracteres "%2", o recurso de cadeia de caracteres de modelo identificado por `nIDS`.  
  
```   
void AfxFormatString2(
    CString& rString,  
    UINT nIDS,  
    LPCTSTR lpsz1,  
    LPCTSTR lpsz2); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `rString`  
 Uma referência para o `CString` que conterá a cadeia de caracteres resultante após a substituição é executada.  
  
 `nIDS`  
 A ID da tabela de cadeia de caracteres da cadeia de caracteres de modelo no qual a substituição será executada.  
  
 `lpsz1`  
 Uma cadeia de caracteres que substituirá o formato de caracteres "%1" na cadeia de caracteres de modelo.  
  
 `lpsz2`  
 Uma cadeia de caracteres que substituirá o formato de caracteres "%2" na cadeia de caracteres de modelo.  
  
### <a name="remarks"></a>Comentários  
 A cadeia de caracteres recém-criado é armazenada em `rString`. Por exemplo, se a cadeia de caracteres na tabela de cadeia de caracteres é "File %1 não encontrado no diretório %2", `lpsz1` aponta para "MYFILE. TXT", e `lpsz2` aponta para"C:\MYDIR", em seguida, `rString` irá conter a cadeia de caracteres"arquivo MYFILE. TXT não encontrado no diretório C:\MYDIR"  
  
 Se o formato de caracteres "%1" ou "%2" aparecer mais de uma vez na cadeia de caracteres, várias substituições serão feitas. Eles não precisam estar em ordem numérica.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[26 de # NVC_MFC_Utilities](../../mfc/codesnippet/cpp/cstring-formatting-and-message-box-display_3.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  
  
##  <a name="afxmessagebox"></a>AfxMessageBox  
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
 `lpszText`  
 Aponta para um `CString` objeto ou cadeia de caracteres terminada em nulo que contém a mensagem a ser exibida na caixa de mensagem.  
  
 `nType`  
 O estilo da caixa de mensagem. Aplicar o [estilos de caixa de mensagem](../../mfc/reference/message-box-styles.md) à caixa.  
  
 `nIDHelp`  
 A ID do contexto de ajuda para a mensagem. 0 indica que o contexto de Ajuda do aplicativo padrão será usado.  
  
 `nIDPrompt`  
 Uma ID exclusiva usada para fazer referência a uma cadeia de caracteres na tabela de cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Zero se não houver memória suficiente para exibir a caixa de mensagem. Caso contrário, um dos valores a seguir será retornado:  
  
- **IDABORT** anular o botão foi selecionado.  
  
- **IDCANCEL** cancelar o botão foi selecionado.  
  
- **IDIGNORE** ignorar o botão foi selecionado.  
  
- **IDNO** não o botão foi selecionado.  
  
- **IDOK** Okey o botão foi selecionado.  
  
- **IDRETRY** novamente o botão foi selecionado.  
  
- **IDYES** Sim o botão foi selecionado.  
  
 Se uma caixa de mensagem tem um botão Cancelar, o **IDCANCEL** valor será retornado se a tecla ESC está pressionada ou o botão Cancelar está selecionado. Se a caixa de mensagem nenhum botão Cancelar pressionando a tecla ESC não tem efeito.  
  
 As funções [AfxFormatString1](#afxformatstring1) e [AfxFormatString2](#afxformatstring2) pode ser útil na formatação de texto que aparece em uma caixa de mensagem.  
  
### <a name="remarks"></a>Comentários  
 O primeiro formulário deste sobrecarregado função exibe uma cadeia de caracteres de texto apontada pelo `lpszText` na caixa de mensagem e usa `nIDHelp` para descrever um contexto de Ajuda. O contexto da Ajuda é usado para saltar para um tópico de ajuda associado quando o usuário pressiona a tecla de Ajuda (F1 normalmente).  
  
 A segunda forma da função usa o recurso de cadeia de caracteres com a ID de `nIDPrompt` para exibir uma mensagem na caixa de mensagem. A página de ajuda associada é encontrada e o valor de `nIDHelp`. Se o valor padrão de `nIDHelp` é usado (-1), a ID de recurso de cadeia de caracteres, `nIDPrompt`, é usado para o contexto da Ajuda. Para obter mais informações sobre como definir contextos de Ajuda, consulte [28 de observação técnica](../../mfc/tn028-context-sensitive-help-support.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing #133](../../mfc/reference/codesnippet/cpp/cstring-formatting-and-message-box-display_4.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)   
 [Classe CStringT](../../atl-mfc-shared/reference/cstringt-class.md)

