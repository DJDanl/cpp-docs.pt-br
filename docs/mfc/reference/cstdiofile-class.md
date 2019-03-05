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
ms.openlocfilehash: fd42934107591905a1bbc273ee9eec4b37e58ea7
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57258782"
---
# <a name="cstdiofile-class"></a>Classe CStdioFile

Representa um arquivo de fluxo de tempo de execução do C como aberto pela função de tempo de execução [fopen](../../c-runtime-library/reference/fopen-wfopen.md).

## <a name="syntax"></a>Sintaxe

```
class CStdioFile : public CFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CStdioFile::CStdioFile](#cstdiofile)|Constrói um `CStdioFile` objeto a partir de um ponteiro de arquivo ou caminho.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStdioFile::Open](#open)|Sobrecarregado. Abrir é projetado para uso com o padrão `CStdioFile` construtor (substitui [CFile::Open](../../mfc/reference/cfile-class.md#open)).|
|[CStdioFile::ReadString](#readstring)|Lê uma única linha de texto.|
|[CStdioFile::Seek](#seek)|Posiciona o ponteiro do arquivo atual.|
|[CStdioFile::WriteString](#writestring)|Grava uma única linha de texto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CStdioFile::m_pStream](#m_pstream)|Contém um ponteiro para um arquivo aberto.|

## <a name="remarks"></a>Comentários

Arquivos de Stream são armazenados em buffer e podem ser abertos no modo de texto (o padrão) ou no modo binário.

Modo de texto fornece processamento especial para os pares de alimentação de linha de retorno de carro. Quando você escreve uma nova linha (0x0A) de caracteres para um modo de texto `CStdioFile` object, o par de bytes (0x0D, 0x0A) é enviado para o arquivo. Quando você lê, o par de bytes (0x0D, 0x0A) é convertido em um único byte do 0x0A.

O [CFile](../../mfc/reference/cfile-class.md) funções [duplicar](../../mfc/reference/cfile-class.md#duplicate), [LockRange](../../mfc/reference/cfile-class.md#lockrange), e [UnlockRange](../../mfc/reference/cfile-class.md#unlockrange) não têm suporte para `CStdioFile`.

Se você chamar essas funções em um `CStdioFile`, você obterá uma [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

Para obter mais informações sobre como usar `CStdioFile`, consulte os artigos [arquivos no MFC](../../mfc/files-in-mfc.md) e [tratamento de arquivos](../../c-runtime-library/file-handling.md) no *referência da biblioteca de tempo de execução*.

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
Especifica opções para criação de arquivos, compartilhamento de arquivos e modos de acesso de arquivo. Você pode especificar várias opções usando o OR bit a bit ( **|** ) operador.

Uma opção de modo de acesso de arquivo é necessária; outros modos são opcionais. Ver [CFile::CFile](../../mfc/reference/cfile-class.md#cfile) para obter uma lista de opções de modo e outros sinalizadores. No MFC versão 3.0 e posterior, os sinalizadores de compartilhamento são permitidos.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager.

### <a name="remarks"></a>Comentários

O construtor padrão não for anexado a um arquivo para o `CStdioFile` objeto. Ao usar esse construtor, você deve usar o `CStdioFile::Open` método para abrir um arquivo e anexá-lo para o `CStdioFile` objeto.

O único parâmetro construtor anexa um fluxo de arquivos abertos para o `CStdioFile` objeto. Permitidos valores de ponteiro incluem os ponteiros de arquivo de entrada/saída predefinidos *stdin*, *stdout*, ou *stderr*.

O construtor de dois parâmetros cria um `CStdioFile` de objeto e abre o arquivo correspondente com o caminho fornecido.

Se você passar NULL para qualquer um *pOpenStream* ou *lpszFileName*, o construtor gerará um `CInvalidArgException*`.

Se o arquivo não pode ser aberto ou criado, o construtor gerará um `CFileException*`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#37](../../atl-mfc-shared/reference/codesnippet/cpp/cstdiofile-class_1.cpp)]

##  <a name="m_pstream"></a>  CStdioFile::m_pStream

O `m_pStream` membro de dados é o ponteiro para um arquivo aberto, conforme retornado pela função de tempo de execução C `fopen`.

```
FILE* m_pStream;
```

### <a name="remarks"></a>Comentários

É NULL se o arquivo nunca foi aberto ou foi fechado.

##  <a name="open"></a>  CStdioFile::Open

Sobrecarregado. Abrir é projetado para uso com o padrão `CStdioFile` construtor.

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
Modo de compartilhamento e acesso. Especifica a ação a ser tomada ao abrir o arquivo. Você pode combinar as opções com o uso de OR bit a bit (&#124;) operador. Permissão de acesso de um e um compartilhamento de opção são necessários; os modos de modeCreate e modeNoInherit são opcionais.

*pError*<br/>
Um ponteiro para um objeto de exceção de arquivo existente que receberá o status de uma operação com falha.

*pTM*<br/>
Ponteiro para um `CAtlTransactionManager` objeto.

### <a name="return-value"></a>Valor de retorno

VERDADEIRO se bem-sucedido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="readstring"></a>  CStdioFile::ReadString

Lê dados de texto em um buffer, até o limite de *Nmáx*-1 caracteres, do arquivo associado a `CStdioFile` objeto.

```
virtual LPTSTR ReadString(
    LPTSTR lpsz,
    UINT nMax);

virtual BOOL ReadString(CString& rString);
```

### <a name="parameters"></a>Parâmetros

*lpsz*<br/>
Especifica um ponteiro para um buffer fornecido pelo usuário que receberá uma cadeia de caracteres de texto terminada em nulo.

*nMax*<br/>
Especifica o número máximo de caracteres a serem lidos, sem contar o caractere nulo de terminação.

*rString*<br/>
Uma referência a um `CString` objeto que contém a cadeia de caracteres quando a função retorna.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o buffer que contém os dados de texto. NULL se o final do arquivo foi atingido sem ler todos os dados; ou, se boolean, FALSE se o final do arquivo foi atingido sem ler todos os dados.

### <a name="remarks"></a>Comentários

Leitura será interrompida pelo primeiro caractere de nova linha. Se, nesse caso, a menos que *Nmáx*-1 caracteres tiverem sido lidos, um caractere de nova linha é armazenado em buffer. Um caractere nulo ('\0') é acrescentado em ambos os casos.

[CFile::Read](../../mfc/reference/cfile-class.md#read) também está disponível para a entrada de modo de texto, mas ele não terminar em um par de avanço de linha de retorno de carro.

> [!NOTE]
>  O `CString` versão dessa função remove o `'\n'` se estiver presente; a versão LPTSTR não.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#38](../../atl-mfc-shared/reference/codesnippet/cpp/cstdiofile-class_2.cpp)]

##  <a name="seek"></a>  CStdioFile::Seek

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

- `CFile::begin`: Mova o ponteiro do arquivo *lOff* bytes encaminham desde o início do arquivo.

- `CFile::current`: Mova o ponteiro do arquivo *lOff* bytes da posição atual no arquivo.

- `CFile::end`: Mova o ponteiro do arquivo *lOff* bytes do final do arquivo. Observe que *lOff* deve ser negativo busca no existente de arquivos; positivo de valores serão buscar após o final do arquivo.

### <a name="return-value"></a>Valor de retorno

Se a posição solicitada é legal, `Seek` retorna o novo deslocamento de bytes do início do arquivo. Caso contrário, o valor retornado será indefinido e um `CFileException` objeto é gerado.

### <a name="remarks"></a>Comentários

O `Seek` função permite acesso aleatório ao conteúdo do arquivo, movendo o ponteiro de um valor especificado, forma absoluta ou relativa. Na verdade, nenhum dado será lido durante a busca. Se a posição solicitada é maior que o tamanho do arquivo, o tamanho do arquivo será estendido para essa posição e nenhuma exceção será lançada.

Quando um arquivo é aberto, o ponteiro do arquivo é posicionado no deslocamento 0, o início do arquivo.

Essa implementação do `Seek` baseia-se a função de biblioteca em tempo de execução (CRT) `fseek`. Há vários limites sobre o uso de `Seek` em fluxos abertos no modo de texto. Para obter mais informações, consulte [fseek, _fseeki64](../../c-runtime-library/reference/fseek-fseeki64.md).

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar `Seek` para mover o ponteiro de 1.000 bytes do início do `cfile` arquivo. Observe que `Seek` não lê os dados, portanto, você deve chamar subsequentemente [CStdioFile::ReadString](#readstring) para ler dados.

[!code-cpp[NVC_MFCFiles#39](../../atl-mfc-shared/reference/codesnippet/cpp/cstdiofile-class_3.cpp)]

##  <a name="writestring"></a>  CStdioFile::WriteString

Grava dados de um buffer para o arquivo associado a `CStdioFile` objeto.

```
virtual void WriteString(LPCTSTR lpsz);
```

### <a name="parameters"></a>Parâmetros

*lpsz*<br/>
Especifica um ponteiro para um buffer que contém uma cadeia de caracteres terminada em nulo.

### <a name="remarks"></a>Comentários

O caractere nulo de terminação ( `\0`) não é gravada no arquivo. Esse método grava caracteres de nova linha *lpsz* para o arquivo como um par de avanço de linha/retorno de carro.

Se você quiser gravar dados que não não terminada em nulo em um arquivo, use `CStdioFile::Write` ou [CFile::Write](../../mfc/reference/cfile-class.md#write).

Este método lança um `CInvalidArgException*` se você especificar NULL para o *lpsz* parâmetro.

Este método lança um `CFileException*` em resposta a erros de sistema de arquivos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#40](../../atl-mfc-shared/reference/codesnippet/cpp/cstdiofile-class_4.cpp)]

## <a name="see-also"></a>Consulte também

[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[CFile::Duplicate](../../mfc/reference/cfile-class.md#duplicate)<br/>
[CFile::LockRange](../../mfc/reference/cfile-class.md#lockrange)<br/>
[CFile::UnlockRange](../../mfc/reference/cfile-class.md#unlockrange)<br/>
[Classe CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md)
