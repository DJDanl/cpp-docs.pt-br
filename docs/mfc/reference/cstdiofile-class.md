---
title: Classe CStdioFile
ms.date: 11/04/2016
f1_keywords:
- CStdioFile
- AFX/CStdioFile
- AFX/CStdioFile::CStdioFile
- AFX/CStdioFile::Open
- AFX/CStdioFile::ReadString
- AFX/CStdioFile::Seek
- AFX/CStdioFile::WriteString
- AFX/CStdioFile::m_pStream
helpviewer_keywords:
- CStdioFile [MFC], CStdioFile
- CStdioFile [MFC], Open
- CStdioFile [MFC], ReadString
- CStdioFile [MFC], Seek
- CStdioFile [MFC], WriteString
- CStdioFile [MFC], m_pStream
ms.assetid: 88c2274c-4f0e-4327-882a-557ba4b3ae15
ms.openlocfilehash: 068e59fdc19821487bc78141d10743363221518e
ms.sourcegitcommit: 878a164fe6d550ca81ab87d8425c8d3cd52fe384
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/22/2019
ms.locfileid: "68375841"
---
# <a name="cstdiofile-class"></a>Classe CStdioFile

Representa um arquivo de fluxo de tempo de execução C como aberto pela função de tempo de execução [fopen](../../c-runtime-library/reference/fopen-wfopen.md).

## <a name="syntax"></a>Sintaxe

```
class CStdioFile : public CFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CStdioFile::CStdioFile](#cstdiofile)|Constrói um `CStdioFile` objeto a partir de um ponteiro de arquivo ou caminho.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStdioFile::Open](#open)|Sobrecarregado. Abrir é projetado para uso com o construtor `CStdioFile` padrão (Substitui [testcfile:: Open](../../mfc/reference/cfile-class.md#open)).|
|[CStdioFile::ReadString](#readstring)|Lê uma única linha de texto.|
|[CStdioFile::Seek](#seek)|Posiciona o ponteiro do arquivo atual.|
|[CStdioFile::WriteString](#writestring)|Grava uma única linha de texto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CStdioFile::m_pStream](#m_pstream)|Contém um ponteiro para um arquivo aberto.|

## <a name="remarks"></a>Comentários

Os arquivos de fluxo são armazenados em buffer e podem ser abertos no modo de texto (o padrão) ou no modo binário.

O modo de texto fornece processamento especial para pares de retorno de carro e alimentação de linha. Quando você escreve um caractere de alimentação de linha (0x0A) para um objeto de modo `CStdioFile` de texto, o par de bytes (0x0D, 0x0A) é enviado ao arquivo. Quando você lê, o par de bytes (0x0D, 0x0A) é convertido em um único byte 0x0A.

As funções de [Testcfile](../../mfc/reference/cfile-class.md) [duplicadas](../../mfc/reference/cfile-class.md#duplicate), [LockRange](../../mfc/reference/cfile-class.md#lockrange)e [UnlockRange](../../mfc/reference/cfile-class.md#unlockrange) não têm `CStdioFile`suporte para.

Se você chamar essas funções em um `CStdioFile`, receberá um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

Para obter mais informações sobre `CStdioFile`como usar o, consulte os artigos [arquivos em MFC](../../mfc/files-in-mfc.md) e [manipulação de arquivos](../../c-runtime-library/file-handling.md) na *referência da biblioteca de tempo de execução*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFile](../../mfc/reference/cfile-class.md)

`CStdioFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="cstdiofile"></a>  CStdioFile::CStdioFile

Constrói e inicializa um objeto `CStdioFile`.

```
CStdioFile();
CStdioFile(CAtlTransactionManager* pTM);
  CStdioFile(FILE* pOpenStream);

CStdioFile(
    LPCTSTR lpszFileName,
    UINT nOpenFlags);

CStdioFile(
    LPCTSTR lpszFileName,
    UINT nOpenFlags,
    CAtlTransactionManager* pTM);
```

### <a name="parameters"></a>Parâmetros

*pOpenStream*<br/>
Especifica o ponteiro do arquivo retornado por uma chamada para a função de tempo de execução C [fopen](../../c-runtime-library/reference/fopen-wfopen.md).

*lpszFileName*<br/>
Especifica uma cadeia de caracteres que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto.

*nOpenFlags*<br/>
Especifica opções para criação de arquivos, compartilhamento de arquivos e modos de acesso a arquivos. Você pode especificar várias opções usando o **|** operador OR

Uma opção de modo de acesso a um arquivo é necessária; outros modos são opcionais. Consulte [testcfile:: RecFile](../../mfc/reference/cfile-class.md#cfile) para obter uma lista de opções de modo e outros sinalizadores. No MFC versão 3,0 e posterior, são permitidos sinalizadores de compartilhamento.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager.

### <a name="remarks"></a>Comentários

O construtor padrão não anexa um arquivo ao `CStdioFile` objeto. Ao usar esse construtor, você deve usar o `CStdioFile::Open` método para abrir um arquivo e anexá-lo `CStdioFile` ao objeto.

O construtor de parâmetro único anexa um fluxo de arquivo aberto ao `CStdioFile` objeto. Os valores de ponteiro permitidos incluem os ponteiros de arquivo de entrada/saída predefinidos, *stdin*, *stdout*ou *stderr*.

O construtor de dois parâmetros cria um `CStdioFile` objeto e abre o arquivo correspondente com o caminho fornecido.

Se você passar NULL para *pOpenStream* ou *lpszFileName*, o construtor lançará um `CInvalidArgException*`.

Se o arquivo não puder ser aberto ou criado, o construtor lançará um `CFileException*`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#37](../../atl-mfc-shared/reference/codesnippet/cpp/cstdiofile-class_1.cpp)]

##  <a name="m_pstream"></a>  CStdioFile::m_pStream

O `m_pStream` membro de dados é o ponteiro para um arquivo aberto, como retornado pela função `fopen`de tempo de execução C.

```
FILE* m_pStream;
```

### <a name="remarks"></a>Comentários

Será nulo se o arquivo nunca tiver sido aberto ou tiver sido fechado.

##  <a name="open"></a>  CStdioFile::Open

Sobrecarregado. Abrir é projetado para ser usado com o `CStdioFile` construtor padrão.

```
virtual BOOL Open(
    LPCTSTR lpszFileName,
    UINT nOpenFlags,
    CFileException* pError = NULL);

virtual BOOL Open(
    LPCTSTR lpszFileName,
    UINT nOpenFlags,
    CAtlTransactionManager* pTM,
    CFileException* pError = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszFileName*<br/>
Uma cadeia de caracteres que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto.

*nOpenFlags*<br/>
Modo de compartilhamento e acesso. Especifica a ação a ser tomada ao abrir o arquivo. Você pode combinar as opções usando o operador bit-a&#124;-or (). Uma permissão de acesso e uma opção de compartilhamento são necessárias; os modos modeCreate e modeNoInherit são opcionais.

*pError*<br/>
Um ponteiro para um objeto de exceção de arquivo existente que receberá o status de uma operação com falha.

*pTM*<br/>
Ponteiro para um `CAtlTransactionManager` objeto.

### <a name="return-value"></a>Valor de retorno

Verdadeiro se for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="readstring"></a>  CStdioFile::ReadString

Lê dados de texto em um buffer, até um limite de *nmáx*-1 caracteres, do arquivo associado `CStdioFile` ao objeto.

```
virtual LPTSTR ReadString(
    LPTSTR lpsz,
    UINT nMax);

virtual BOOL ReadString(CString& rString);
```

### <a name="parameters"></a>Parâmetros

*lpsz*<br/>
Especifica um ponteiro para um buffer fornecido pelo usuário que receberá uma cadeia de texto terminada em nulo.

*nMax*<br/>
Especifica o número máximo de caracteres a serem lidos, não contando o caractere nulo de terminação.

*rString*<br/>
Uma referência a um `CString` objeto que conterá a cadeia de caracteres quando a função retornar.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o buffer que contém os dados de texto. NULL se o fim do arquivo foi atingido sem ler nenhum dado; ou se Boolean, FALSE se o fim do arquivo foi atingido sem ler nenhum dado.

### <a name="remarks"></a>Comentários

A leitura é interrompida pelo primeiro caractere de nova linha. Se, nesse caso, menos de *nmáx*-1 caracteres tiverem sido lidos, um caractere de nova linha será armazenado no buffer. Um caractere nulo (' \ 0 ') é acrescentado em ambos os casos.

[Testcfile:: Read](../../mfc/reference/cfile-class.md#read) também está disponível para entrada de modo de texto, mas não termina em um par de retorno de carro-alimentação de linha.

> [!NOTE]
>  A `CString` versão dessa função remove o `'\n'` se estiver presente; a versão do LPTSTR não.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#38](../../atl-mfc-shared/reference/codesnippet/cpp/cstdiofile-class_2.cpp)]

##  <a name="seek"></a>CStdioFile:: Seek

Reposiciona o ponteiro em um arquivo aberto anteriormente.

```
virtual ULONGLONG Seek(
    LONGLONG lOff,
    UINT nFrom);
```

### <a name="parameters"></a>Parâmetros

*lOff*<br/>
Número de bytes para mover o ponteiro.

*nFrom*<br/>
Modo de movimentação do ponteiro. Deve ser um dos seguintes valores:

- `CFile::begin`: Mova o ponteiro de arquivo *lOff* bytes para frente do início do arquivo.

- `CFile::current`: Mova o ponteiro de arquivo *lOff* bytes da posição atual no arquivo.

- `CFile::end`: Mova o ponteiro de arquivo *lOff* bytes do final do arquivo. Observe que *lOff* deve ser negativo para buscar no arquivo existente; os valores positivos serão procurados após o final do arquivo.

### <a name="return-value"></a>Valor de retorno

Se a posição solicitada for válida `Seek` , o retornará o novo deslocamento de byte do início do arquivo. Caso contrário, o valor de retorno será indefinido `CFileException` e um objeto será gerado.

### <a name="remarks"></a>Comentários

A `Seek` função permite acesso aleatório ao conteúdo de um arquivo movendo o ponteiro uma quantidade especificada, absolutamente ou relativamente. Nenhum dado é realmente lido durante a busca. Se a posição solicitada for maior que o tamanho do arquivo, o comprimento do arquivo será estendido para essa posição e nenhuma exceção será lançada.

Quando um arquivo é aberto, o ponteiro do arquivo é posicionado no deslocamento 0, o início do arquivo.

Essa implementação do `Seek` é baseada na função `fseek`de biblioteca de tempo de execução (CRT). Há vários limites no uso do `Seek` em fluxos abertos no modo de texto. Para obter mais informações, consulte [fseek, _fseeki64](../../c-runtime-library/reference/fseek-fseeki64.md).

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar `Seek` o para mover o ponteiro 1000 bytes do início `cfile` do arquivo. Observe que `Seek` o não lê os dados, portanto, você deve chamar subseqüentemente [CStdioFile:: ReadString](#readstring) para ler os dados.

[!code-cpp[NVC_MFCFiles#39](../../atl-mfc-shared/reference/codesnippet/cpp/cstdiofile-class_3.cpp)]

##  <a name="writestring"></a>  CStdioFile::WriteString

Grava dados de um buffer para o arquivo associado `CStdioFile` ao objeto.

```
virtual void WriteString(LPCTSTR lpsz);
```

### <a name="parameters"></a>Parâmetros

*lpsz*<br/>
Especifica um ponteiro para um buffer que contém uma cadeia de caracteres terminada em nulo.

### <a name="remarks"></a>Comentários

O caractere nulo de terminação ( `\0`) não é gravado no arquivo. Esse método grava os caracteres de nova linha em *lpsz* no arquivo como um par de retorno de carro-alimentação de linha.

Se você quiser gravar dados que não são terminados em nulo para um arquivo, use `CStdioFile::Write` ou [testcfile:: Write](../../mfc/reference/cfile-class.md#write).

Esse método gera um `CInvalidArgException*` se você especificar NULL para o parâmetro *lpsz* .

Esse método gera um `CFileException*` em resposta a erros do sistema de arquivos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#40](../../atl-mfc-shared/reference/codesnippet/cpp/cstdiofile-class_4.cpp)]

## <a name="see-also"></a>Consulte também

[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[Testcfile::D uplicar](../../mfc/reference/cfile-class.md#duplicate)<br/>
[CFile::LockRange](../../mfc/reference/cfile-class.md#lockrange)<br/>
[CFile::UnlockRange](../../mfc/reference/cfile-class.md#unlockrange)<br/>
[Classe CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md)
