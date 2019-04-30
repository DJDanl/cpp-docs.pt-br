---
title: Classe CArchiveException
ms.date: 11/04/2016
f1_keywords:
- CArchiveException
- AFX/CArchiveException
- AFX/CArchiveException::CArchiveException
- AFX/CArchiveException::m_cause
- AFX/CArchiveException::m_strFileName
helpviewer_keywords:
- CArchiveException [MFC], CArchiveException
- CArchiveException [MFC], m_cause
- CArchiveException [MFC], m_strFileName
ms.assetid: da31a127-e86c-41d1-b0b6-bed0865b1b49
ms.openlocfilehash: 731735bccf9225e67d82b1fe90336c92a630b368
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62391303"
---
# <a name="carchiveexception-class"></a>Classe CArchiveException

Representa uma condição de exceção de serialização

## <a name="syntax"></a>Sintaxe

```
class CArchiveException : public CException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CArchiveException::CArchiveException](#carchiveexception)|Constrói um objeto `CArchiveException`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CArchiveException::m_cause](#m_cause)|Indica a causa da exceção.|
|[CArchiveException::m_strFileName](#m_strfilename)|Especifica o nome do arquivo para essa condição de exceção.|

## <a name="remarks"></a>Comentários

O `CArchiveException` classe inclui um membro de dados públicos que indica a causa da exceção.

`CArchiveException` objetos são construídos e lançados dentro [CArchive](../../mfc/reference/carchive-class.md) funções de membro. Você pode acessar esses objetos dentro do escopo de um **CATCH** expressão. O código causa é independente do sistema operacional. Para obter mais informações sobre o processamento de exceção, consulte [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

`CArchiveException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="carchiveexception"></a>  CArchiveException::CArchiveException

Constrói uma `CArchiveException` objeto, armazenando o valor da *causar* no objeto.

```
CArchiveException(
    int cause = CArchiveException::none,
    LPCTSTR lpszArchiveName = NULL);
```

### <a name="parameters"></a>Parâmetros

*cause*<br/>
Uma variável do tipo enumerado que indica o motivo da exceção. Para obter uma lista dos enumeradores, consulte o [m_cause](#m_cause) membro de dados.

*lpszArchiveName*<br/>
Aponta para uma cadeia de caracteres que contém o nome da `CArchive` objeto que causou a exceção.

### <a name="remarks"></a>Comentários

Você pode criar uma `CArchiveException` do objeto no heap e lançá-la por conta própria ou permitir que a função global [AfxThrowArchiveException](../../mfc/reference/exception-processing.md#afxthrowarchiveexception) tratá-la para você.

Não use esse construtor diretamente. em vez disso, chame a função global `AfxThrowArchiveException`.

##  <a name="m_cause"></a>  CArchiveException::m_cause

Especifica a causa da exceção.

```
int m_cause;
```

### <a name="remarks"></a>Comentários

Este membro de dados é uma variável pública do tipo **int**. Seus valores são definidos por um `CArchiveException` tipo enumerado. Os enumeradores e seus significados são os seguintes:

- `CArchiveException::none` Nenhum erro tiver ocorrido.

- `CArchiveException::genericException` Erro não especificado.

- `CArchiveException::readOnly` Tentativa de gravação em um arquivo aberto para o carregamento.

- `CArchiveException::endOfFile` Fim do arquivo atingido durante a leitura de um objeto.

- `CArchiveException::writeOnly` Tentativa de leitura de um arquivo aberto para armazenamento.

- `CArchiveException::badIndex` Formato de arquivo inválido.

- `CArchiveException::badClass` Você tentou ler um objeto em um objeto do tipo errado.

- `CArchiveException::badSchema` Você tentou ler um objeto com uma versão diferente da classe.

    > [!NOTE]
    >  Esses enumeradores de causa de `CArchiveException` são diferentes dos enumeradores de causa de `CFileException`.

    > [!NOTE]
    > O `CArchiveException::generic` foi preterido. Use `genericException` em seu lugar. Se **genérico** é usado em um aplicativo e compilado com /clr, haverá erros de sintaxe que não são fáceis de decifrar.

##  <a name="m_strfilename"></a>  CArchiveException::m_strFileName

Especifica o nome do arquivo para essa condição de exceção.

```
CString m_strFileName;
```

## <a name="see-also"></a>Consulte também

[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CArchive](../../mfc/reference/carchive-class.md)<br/>
[AfxThrowArchiveException](../../mfc/reference/exception-processing.md#afxthrowarchiveexception)<br/>
[Processamento de exceção](../../mfc/reference/exception-processing.md)
