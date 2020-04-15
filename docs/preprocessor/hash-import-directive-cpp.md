---
title: '#Diretiva import (C++)'
ms.date: 08/29/2019
f1_keywords:
- '#import'
helpviewer_keywords:
- .tlh files
- '#import directive'
- import directive (#import)
- tlh files
- tlbid switch
- preprocessor, directives
- COM, type library header file
ms.assetid: 787d1112-e543-40d7-ab15-a63d43f4030a
ms.openlocfilehash: 9cdfef091b659151f427c381e386f0e83396e741
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81332061"
---
# <a name="import-directive-c"></a>diretiva #import (C++)

**Específico do C++**

Usada para incorporar informações de uma biblioteca de tipos. O conteúdo da biblioteca de tipos é convertido em classes do C++, a maioria descrevendo as interfaces COM.

## <a name="syntax"></a>Sintaxe

> **#import.** "*filename*" \[ *atributos*]\
> **#import** \<> \[*atributos* *de nome de arquivo]*

### <a name="parameters"></a>Parâmetros

*Filename*\
Especifica a biblioteca de tipos a ser importada. O *nome do arquivo* pode ser um dos seguintes tipos:

- O nome de um arquivo que contém uma biblioteca de tipos, como um arquivo .olb, .tlb ou .dll. A palavra-chave, `file:`pode preceder cada nome de arquivo.

- O progid de um controle na biblioteca de tipos. A palavra-chave `progid:`pode preceder cada progid. Por exemplo:

    ```cpp
    #import "progid:my.prog.id.1.5"
    ```

   Para obter mais informações sobre progids, consulte [Especificando o ID de localização e o número da versão](#_predir_the_23import_directive_specifyingthelocalizationidandversionnumber).

   Quando você usa um compilador cruzado de 32 bits em um sistema operacional de 64 bits, o compilador só pode ler a colmeia de registro de 32 bits. Pode ser conveniente usar o compilador de 64 bits nativo para criar e registrar uma biblioteca de tipos de 64 bits.

- A ID da biblioteca de tipos. A palavra-chave `libid:`pode preceder cada ID da biblioteca. Por exemplo:

    ```cpp
    #import "libid:12341234-1234-1234-1234-123412341234" version("4.0") lcid("9")
    ```

   Se você não `version` `lcid`especificar ou , `progid:` as [regras](#_predir_the_23import_directive_specifyingthelocalizationidandversionnumber) aplicadas também são aplicadas a `libid:`.

- Um arquivo executável (.exe).

- Um arquivo de biblioteca (.dll) contendo um recurso de biblioteca de tipo (como um .ocx).

- Um documento composto que contém uma biblioteca de tipos.

- Qualquer outro formato de arquivo que possa ser compreendido pela API **LoadTypeLib.**

*Atributos*\
Um ou mais [atributos #import.](#_predir_the_23import_directive_import_attributes) Separe os atributos com espaços ou vírgulas. Por exemplo:

```cpp
#import "..\drawctl\drawctl.tlb" no_namespace, raw_interfaces_only
```

\-ou-

```cpp
#import "..\drawctl\drawctl.tlb" no_namespace raw_interfaces_only
```

## <a name="remarks"></a>Comentários

### <a name="search-order-for-filename"></a><a name="_predir_the_23import_directive_searchorderforfilename"></a>Ordem de pesquisa para nome de arquivo

*filename* é opcionalmente precedido por uma especificação de diretório. O nome do arquivo deve nomear um arquivo existente. A diferença entre os dois formatos de sintaxe é a ordem em que o pré-processador procura os arquivos de biblioteca de tipos quando o caminho é especificado de forma incompleta.

|Formato de sintaxe|Ação|
|-----------------|------------|
|Forma entre aspas|Instrui o pré-processador a procurar arquivos de biblioteca de tipo primeiro no diretório do arquivo que contém`#include`a **instrução #import** e, em seguida, nos diretórios de quaisquer arquivos que incluam ( ) esse arquivo. Em seguida, o pré-processador pesquisa ao longo dos caminhos mostrados abaixo.|
|Forma de colchete angular|Instrui o pré-processador a procurar arquivos de biblioteca de tipos ao longo dos seguintes caminhos:<br /><br /> 1. `PATH` A lista de caminhos de variáveis do ambiente<br />2. `LIB` A lista de caminhos de variáveis do ambiente<br />3. O caminho especificado pela opção [compilador /I,](../build/reference/i-additional-include-directories.md) exceto que o compilador está procurando por uma biblioteca de tipos que foi referenciada de outra biblioteca de tipo com o atributo [no_registry.](../preprocessor/no-registry.md)|

### <a name="specify-the-localization-id-and-version-number"></a><a name="_predir_the_23import_directive_specifyingthelocalizationidandversionnumber"></a>Especifique o ID de localização e o número da versão

Ao especificar um progid, você também pode especificar a ID de localização e o número de versão do progid. Por exemplo:

```cpp
#import "progid:my.prog.id" lcid("0") version("4.0)
```

Se você não especificar um ID de localização, um progid será escolhido de acordo com as seguintes regras:

- Se há apenas um ID de localização, esse é usado.

- Se houver mais de um ID de localização, o primeiro com a versão número 0, 9 ou 409 é usado.

- Se houver mais de um ID de localização e nenhum deles for 0, 9 ou 409, o último é usado.

- Se você não especificar um número de versão, a versão mais recente será usada.

### <a name="header-files-created-by-import"></a><a name="_predir_the_23import_directive_header_files_created_by_import"></a>Arquivos de cabeçalho criados por importação

**#import** cria dois arquivos de cabeçalho que reconstroem o conteúdo da biblioteca do tipo no código-fonte C++. O arquivo de cabeçalho principal é semelhante ao produzido pelo compilador Microsoft Interface Definition Language (MIDL), mas com código e dados gerados pelo compilador adicional. O [arquivo de cabeçalho principal](#_predir_the_primary_type_library_header_file) tem o mesmo nome base da biblioteca do tipo, mais um . Extensão TLH. O arquivo de cabeçalho secundário tem o mesmo nome base que a biblioteca de tipos, com a extensão .TLI. Ele contém as implementações para funções de membro geradas pelo compilador e está incluído (`#include`) no arquivo de cabeçalho principal.

Se importar uma propriedade de `byref` dispinterface que use parâmetros, **#import** não gerará uma [declaração de __declspec (propriedade)](../cpp/property-cpp.md) para a função.

Ambos os arquivos de cabeçalho são colocados no diretório de saída especificado pela opção [/Fo (arquivo objeto nome).](../build/reference/fo-object-file-name.md) Eles são então lidos e compilados pelo compilador como se `#include` o arquivo de cabeçalho primário fosse nomeado por uma diretiva.

As seguintes otimizações do compilador vêm com a diretiva **#import:**

- O arquivo de cabeçalho, quando é criado, recebe o mesmo carimbo de data/hora que a biblioteca de tipos.

- Quando **#import** é processado, o compilador primeiro verifica se o cabeçalho existe e está atualizado. Se sim, então não precisa ser recriado.

A diretiva **#import** também participa de uma reconstrução mínima e pode ser colocada em um arquivo de cabeçalho pré-compilado.  Para obter mais informações, consulte [Criando arquivos de cabeçalho pré-compilados](../build/creating-precompiled-header-files.md).

### <a name="primary-type-library-header-file"></a><a name="_predir_the_primary_type_library_header_file"></a>Arquivo de cabeçalho de biblioteca de tipo principal

O arquivo de cabeçalho principal da biblioteca de tipos consiste em sete seções:

- Texto clichê de título: inclui comentários, a instrução `#include` para COMDEF.H (que define algumas macros padrão usadas no cabeçalho) e outras informações de configuração.

- Referências de encaminhamento e typedefs: consiste em declarações de estrutura como `struct IMyInterface` e typedefs.

- Declarações de ponteiro inteligente: A classe `_com_ptr_t` modelo é um ponteiro inteligente. Encapsula ponteiros de interface e elimina a `AddRef`necessidade `Release`de `QueryInterface` chamar , e funções. Ele também oculta `CoCreateInstance` a chamada ao criar um novo objeto COM. Esta seção usa `_COM_SMARTPTR_TYPEDEF` a declaração de macro para estabelecer typedefs de interfaces COM como especializações de modelo da [classe modelo _com_ptr_t.](../cpp/com-ptr-t-class.md) Por exemplo, `IMyInterface`para interface, o . O arquivo TLH conterá:

    ```TLH
    _COM_SMARTPTR_TYPEDEF(IMyInterface, __uuidof(IMyInterface));
    ```

   que o compilador expande para:

    ```cpp
    typedef _com_ptr_t<_com_IIID<IMyInterface, __uuidof(IMyInterface)> > IMyInterfacePtr;
    ```

   O tipo `IMyInterfacePtr` pode então ser usado no lugar do ponteiro de interface bruto `IMyInterface*`. Consequentemente, não há necessidade de `IUnknown` chamar as várias funções de membros

- Declarações typeinfo: Consiste principalmente em definições de classe e outros itens que expom `ITypeLib:GetTypeInfo`os itens de tipo individual retornados por . Nesta seção, cada typeinfo da biblioteca de tipos é refletido no cabeçalho em um formato que depende das informações de `TYPEKIND`.

- Definição de GUID de estilo antigo opcional: contém inicializações das constantes de GUID nomeadas. Esses nomes têm `CLSID_CoClass` `IID_Interface`a forma e , semelhante sosseido pelos gerados pelo compilador MIDL.

- Instrução `#include` para o cabeçalho secundário da biblioteca de tipos.

- Texto clichê de rodapé: atualmente, inclui `#pragma pack(pop)`.

Todas as seções, exceto a caldeira de título e a seção da caldeira `library` do rodapé, estão fechadas em um espaço de nome com seu nome especificado pela declaração no arquivo IDL original. Você pode usar os nomes do cabeçalho da biblioteca do tipo por uma qualificação explícita usando o nome do namespace. Ou, você pode incluir a seguinte declaração:

```cpp
using namespace MyLib;
```

imediatamente após a **declaração #import** no código fonte.

O namespace pode ser suprimido usando o atributo [no_namespace](no-namespace.md)) da diretiva **#import.** No entanto, suprimir o namespace pode resultar em colisões de nomes. O namespace também pode ser renomeado pelo atributo [rename_namespace.](rename-namespace.md)

O compilador fornece o caminho completo para qualquer dependência de biblioteca de tipo exigida pela biblioteca de tipos que está processando atualmente. O caminho é escrito, na forma de comentários, no cabeçalho da biblioteca de tipos (.TLH) gerado pelo compilador para cada biblioteca de tipos processada.

Se uma biblioteca de tipos incluir referências a tipos definidos em outras bibliotecas, o arquivo .TLH incluirá comentários do seguinte tipo:

```TLH
//
// Cross-referenced type libraries:
//
//  #import "c:\path\typelib0.tlb"
//
```

O nome de arquivo real no **comentário #import** é o caminho completo da biblioteca de tipo de referência cruzada, conforme armazenado no registro. Se você encontrar erros causados por definições de tipo ausentes, verifique os comentários na cabeça do . TLH para ver quais bibliotecas de tipo dependentes podem precisar ser importadas primeiro. Erros prováveis são erros de sintaxe (por exemplo, C2143, C2146, C2321), C2501 (especificadores de declarações ausentes) ou C2433 ("embutido" não permitido na declaração de dados) ao compilar o arquivo .TLI.

Para resolver erros de dependência, determine quais dos comentários de dependência não são fornecidos de outra forma por cabeçalhos do sistema e, em seguida, forneça uma diretiva **#import** em algum momento antes da **diretiva #import** da biblioteca do tipo dependente.

### <a name="import-attributes"></a><a name="_predir_the_23import_directive_import_attributes"></a>#import atributos

**#import** pode incluir opcionalmente um ou mais atributos. Esses atributos instruem o compilador a modificar o conteúdo dos cabeçalhos de biblioteca de tipos. Um símbolo**\\**de barra invertida pode ser usado para incluir linhas adicionais em uma única declaração **de #import.** Por exemplo:

```cpp
#import "test.lib" no_namespace \
   rename("OldName", "NewName")
```

Para obter mais informações, consulte [#import atributos](../preprocessor/hash-import-attributes-cpp.md).

**FIM de Específico do C++**

## <a name="see-also"></a>Confira também

[Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)\
[Suporte comcompilador COM](../cpp/compiler-com-support.md)
