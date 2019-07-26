---
title: Páginas de propriedade do vinculador
ms.date: 7/24/2019
ms.topic: article
ms.assetid: 7e7671e5-a35a-4e67-9bdb-661d75c4d11e
ms.openlocfilehash: 17880d50ae012b640cb83f3766883ab2b1bcbe73
ms.sourcegitcommit: 7b039b5f32f6c59be6c6bb1cffafd69c3bfadd35
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/26/2019
ms.locfileid: "68537596"
---
# <a name="linker-property-pages"></a>Páginas de propriedade do vinculador

As propriedades a seguir são encontradas em**Propriedades** > do **projeto** > **definição** > do**vinculador**de propriedades. Para obter mais informações sobre o vinculador, consulte [CL invoca as opções do vinculador e do](cl-invokes-the-linker.md) [vinculador](linker-options.md).

## <a name="general-property-page"></a>Página de propriedades geral

### <a name="output-file"></a>Arquivo de saída

A opção [/out](out-output-file-name.md) substitui o nome padrão e o local do programa que o vinculador cria.

### <a name="show-progress"></a>Mostrar progresso

Imprime mensagens de progresso do vinculador

**Durante**

- **Não definido** -sem detalhes.
- **Exibir todas as mensagens de progresso** – exibe todas as mensagens de progresso. 
- **Para bibliotecas pesquisadas** – exibe mensagens de progresso indicando apenas as bibliotecas pesquisadas.
- **Sobre o dobramento COMDAT durante a vinculação otimizada** – exibe informações sobre o dobramento COMDAT durante a vinculação otimizada.
- **Sobre os dados removidos durante a vinculação otimizada** – exibe informações sobre as funções e os dados removidos durante a vinculação otimizada.
- **Sobre módulos incompatíveis com Seh** -exibe informações sobre módulos incompatíveis com a manipulação de exceção segura.
- **Sobre a atividade do vinculador relacionada ao código gerenciado** – exiba informações sobre a atividade do vinculador relacionada ao código gerenciado.

### <a name="version"></a>Versão

A opção [/version](version-version-information.md) informa o vinculador para colocar um número de versão no cabeçalho do arquivo. exe ou. dll. Use DUMPBIN/HEADERS para ver o campo versão da imagem dos valores de cabeçalho OPCIONais para ver o efeito de **/version**.

### <a name="enable-incremental-linking"></a>Habilitar vinculação incremental

Habilita a vinculação incremental. ([/INCREMENTAL](incremental-link-incrementally.md),/INCREMENTAL: NO)

### <a name="suppress-startup-banner"></a>Suprimir Faixa de Inicialização

A opção [/nologo](nologo-suppress-startup-banner-linker.md) impede a exibição da mensagem de direitos autorais e do número de versão. 

### <a name="ignore-import-library"></a>Ignorar Biblioteca de Importação

Essa propriedade instrui o vinculador a não vincular nenhuma saída .lib gerada por esse build a nenhum projeto dependente. Isso permite que o sistema de projeto manipule arquivos .dll que não produzem um arquivo .lib quando compilados. Se um projeto depende de outro projeto que produz uma DLL, o sistema do projeto vincula automaticamente o arquivo .lib produzido por esse projeto filho. Isso pode não ser necessário para projetos que produzem DLLs COM ou DLLs somente de recursos; essas DLLs não têm exportações significativas. Se uma DLL não tem exportações, o vinculador não gera um arquivo .lib. Se nenhum arquivo .lib de exportação estiver presente no disco e o sistema de projeto instruir o vinculador a ser vinculado a essa DLL (ausente), o vínculo falhará. Use a propriedade **Ignorar Biblioteca de Importação** para resolver esse problema. Quando definido como **Sim**, o sistema de projeto ignora a presença ou a ausência do arquivo .lib e faz com que qualquer projeto que dependa desse projeto não seja vinculado ao arquivo .lib inexistente.

Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.IgnoreImportLibrary%2A>.

### <a name="register-output"></a>Registrar Saída

Executa `regsvr32.exe /s $(TargetPath)` na saída de build, que é válido somente em projetos .dll. Para projetos .exe, essa propriedade é ignorada. Para registrar uma saída .exe, defina um evento pós-build na configuração para fazer o registro personalizado que é sempre necessário para arquivos .exe registrados.

Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.RegisterOutput%2A>.

### <a name="per-user-redirection"></a>Redirecionamento por usuário

Tradicionalmente, o registro no Visual Studio é feito em HKEY_CLASSES_ROOT (HKCR). Com o Windows Vista e sistemas operacionais posteriores, para acessar HKCR, é necessário executar o Visual Studio no modo elevado. Os desenvolvedores nem sempre desejam executá-lo no modo elevado, mas ainda precisam trabalhar com o registro. O redirecionamento por usuário permite que você faça o registro sem precisar executar o Visual Studio nesse modo.

O redirecionamento por usuário força as gravações em HKCR a serem redirecionadas para HKEY\_CURRENT\_USER (HKCU). Se o redirecionamento por usuário estiver desativado, isso poderá causar o [Erro de Build PRJ0050 do Projeto](../../error-messages/tool-errors/project-build-error-prj0050.md) quando o programa tentar fazer uma gravação em HKCR.

### <a name="additional-library-directories"></a>Diretórios de Biblioteca Adicionais

Permite que o usuário substitua o caminho da biblioteca ambiental. ([/LIBPATH](libpath-additional-libpath.md): pasta)

### <a name="link-library-dependencies"></a>Dependências da Biblioteca de Links

Especifica se os arquivos .lib produzidos por projetos dependentes devem ser vinculados. Normalmente, você deseja criar um vínculo com os arquivos .lib, mas esse pode não ser o caso para algumas DLLs.

Especifique também um arquivo .obj fornecendo o nome de arquivo e o caminho relativo, por exemplo, "..\\..\MyLibProject\MyObjFile.obj". Se o código-fonte do arquivo .obj incluir um cabeçalho pré-compilado, por exemplo pch.h, o arquivo pch.obj estará localizado na mesma pasta de MyObjFile.obj e você também precisará adicionar pch.obj como uma dependência adicional.

### <a name="use-library-dependency-inputs"></a>Usar Entradas de Dependência da Biblioteca

Especifica se as entradas para a ferramenta de bibliotecário são usadas em vez do próprio arquivo de biblioteca durante o vínculo em saídas de biblioteca de dependências do projeto. Em um projeto grande, quando um projeto dependente produz um arquivo .lib, o vínculo incremental é desabilitado. Se houver muitos projetos dependentes que produzem arquivos .lib, a compilação do aplicativo poderá levar muito tempo. Quando essa propriedade é definida como **Sim**, o sistema de projeto cria o vínculo nos arquivos .obj para os .libs produzidos por projetos dependentes, permitindo o vínculo incremental.

Para obter informações sobre como acessar a página de propriedades do vinculador **geral** , consulte [definir C++ Propriedades do compilador e de compilação no Visual Studio](../working-with-project-properties.md).

### <a name="link-status"></a>Status do link

Especifica se o vinculador deve exibir um indicador de progresso mostrando qual porcentagem do link foi concluída. O padrão é não exibir essas informações de status. ([/LTCG](ltcg-link-time-code-generation.md): STATUS | LTCG: NOSTATUS)

### <a name="prevent-dll-binding"></a>Impedir Associação de dll

[/ALLOWBIND](allowbind-prevent-dll-binding.md): não define um bit no cabeçalho de uma DLL que indica ao BIND. exe que a imagem não tem permissão para ser associada. Talvez você não queira que uma DLL seja vinculada caso ela tenha sido assinada digitalmente (a associação invalida a assinatura).

### <a name="treat-linker-warning-as-errors"></a>Tratar aviso do vinculador como erros

[/WX](wx-treat-linker-warnings-as-errors.md) faz com que nenhum arquivo de saída seja gerado se o vinculador gerar um aviso.

### <a name="force-file-output"></a>Forçar saída de arquivo

A opção [/Force](force-force-file-output.md) informa o vinculador para criar um arquivo. exe ou dll, mesmo que um símbolo seja referenciado, mas não definido ou seja definido com multiplicação. Ele pode criar um arquivo. exe inválido.

**Durante**

- **Enabled** -/Force sem argumentos implica vários e não resolvidos.
- **Somente símbolo definido multiplicado** – Use/Force: Multiple para criar um arquivo de saída se o link encontrar mais de uma definição para um símbolo.
- **Somente símbolo não definido** – Use/Force: não resolvido para criar um arquivo de saída se o link encontrar ou não um símbolo indefinido. /FORCE: não resolvido será ignorado se o símbolo de ponto de entrada não for resolvido.

### <a name="create-hot-patchable-image"></a>Criar imagem com patches quentes

Prepara uma imagem para HotPatching.

**Durante**

- **Enabled** -prepara uma imagem para HotPatching.
- **Somente imagem x86** -prepara uma imagem x86 para HotPatching.
- **Somente imagem x64** – prepara uma imagem x64 para HotPatching.
- **Somente imagem do Itanium** – prepara uma imagem do Itanium para HotPatching.

### <a name="specify-section-attributes"></a>Especificar atributos de seção

A opção [/Section](section-specify-section-attributes.md) altera os atributos de uma seção, substituindo os atributos definidos quando o arquivo. obj da seção foi compilado.

## <a name="input-property-page"></a>Página de propriedades de entrada

### <a name="additional-dependencies"></a>Dependências adicionais

Especifica itens adicionais a serem adicionados à linha de comando do link, por exemplo, *Kernel32. lib*.

### <a name="ignore-all-default-libraries"></a>Ignorar todas as bibliotecas padrão

A opção [/NODEFAULTLIB](nodefaultlib-ignore-libraries.md) informa o vinculador para remover uma ou mais bibliotecas padrão da lista de bibliotecas que pesquisa ao resolver referências externas. 

### <a name="ignore-specific-default-libraries"></a>Ignorar bibliotecas padrão específicas

Especifica um ou mais nomes de bibliotecas padrão a serem ignoradas; Separe várias bibliotecas com ponto e vírgula. (/NODEFAULTLIB: [nome, nome,...])

### <a name="module-definition-file"></a>Arquivo de definição de módulo

A opção [/def](def-specify-module-definition-file.md) passa um arquivo de definição de módulo (. def) para o vinculador. Somente um arquivo. def pode ser especificado para vincular. 

### <a name="add-module-to-assembly"></a>Adicionar módulo ao assembly

A opção [/ASSEMBLYMODULE](assemblymodule-add-a-msil-module-to-the-assembly.md) permite que você adicione uma referência de módulo a um assembly. As informações de tipo no módulo não estarão disponíveis para o programa assembly que adicionou a referência de módulo. No entanto, as informações de tipo no módulo estarão disponíveis para qualquer programa que referencie o assembly.

### <a name="embed-managed-resource-file"></a>Inserir arquivo de recurso gerenciado

[/ASSEMBLYRESOURCE](assemblyresource-embed-a-managed-resource.md) insere um arquivo de recurso no arquivo de saída.

### <a name="force-symbol-references"></a>Forçar referências de símbolo

A opção [/include](include-force-symbol-references.md) informa o vinculador para adicionar um símbolo especificado à tabela de símbolos.

### <a name="delay-loaded-dlls"></a>Atrasar DLLs carregadas

A opção [/DELAYLOAD](delayload-delay-load-import.md) causa o carregamento atrasado de DLLs. O nome da dll especifica uma DLL para atrasar a carga. 

### <a name="assembly-link-resource"></a>Recurso de link de assembly

A opção [/ASSEMBLYLINKRESOURCE](assemblylinkresource-link-to-dotnet-framework-resource.md) cria um link para um recurso de .NET Framework no arquivo de saída; o arquivo de recurso não é colocado no arquivo de saída.

## <a name="manifest-file-property-page"></a>Página de propriedades do arquivo de manifesto

### <a name="generate-manifest"></a>Gerar manifesto

[/Manifest](manifest-create-side-by-side-assembly-manifest.md) especifica que o vinculador deve criar um arquivo de manifesto lado a lado.

### <a name="manifest-file"></a>Arquivo de manifesto

[/MANIFESTFILE](manifestfile-name-manifest-file.md) permite alterar o nome padrão do arquivo de manifesto. O nome padrão do arquivo de manifesto é o nome do arquivo com. manifest anexado.

### <a name="additional-manifest-dependencies"></a>Dependências de manifesto adicionais

[/MANIFESTDEPENDENCY](manifestdependency-specify-manifest-dependencies.md) permite especificar atributos que serão colocados na seção de dependência do arquivo de manifesto.

### <a name="allow-isolation"></a>Permitir isolamento

Especifica o comportamento da pesquisa de manifesto. ([/ALLOWISOLATION](allowisolation-manifest-lookup.md): NO)

### <a name="enable-user-account-control-uac"></a>Habilitar UAC (controle de conta de usuário)

Especifica se o controle de conta de usuário está habilitado ou não.  ([/MANIFESTUAC](manifestuac-embeds-uac-information-in-manifest.md),/MANIFESTUAC: NO)

### <a name="uac-execution-level"></a>Nível de execução do UAC

Especifica o nível de execução solicitado para o aplicativo durante a execução com o controle de conta de usuário.  (/MANIFESTUAC: Level = [valor])

**Durante**

- **asInvoker** -nível de execução do UAC: como chamador.
- **highestAvailable** -nível de execução do UAC: mais alto disponível.
- **requireAdministrator** -nível de execução do UAC: requer administrador.

### <a name="uac-bypass-ui-protection"></a>Proteção de interface do usuário de bypass do UAC

Especifica se os níveis de proteção da interface do usuário devem ser ignorados ou não para outras janelas na área de trabalho.  Defina essa propriedade como ' Sim ' somente para aplicativos de acessibilidade.  ([/MANIFESTUAC](manifestuac-embeds-uac-information-in-manifest.md): UIAccess = [true | false])

## <a name="debugging-property-page"></a>Página de propriedades de depuração

### <a name="generate-debug-info"></a>Gerar informações de depuração

Essa opção permite a criação de informações de depuração para o arquivo. exe ou a DLL.

**Durante**

- **Não** – não produz nenhuma informação de depuração.
- **Gerar informações de depuração** -crie um banco de dados de programa completo (PDB) ideal para distribuição para o servidor de símbolos da Microsoft.
- **Gerar informações de depuração otimizadas para links mais rápidos** – produz um banco de dados de programa (PDB) ideal para o ciclo de depuração de link de edição. 
- **Gerar informações de depuração otimizadas para compartilhamento e publicação** – produz um banco de dados de programa (PDB) ideal para o ciclo de depuração de link de edição. 

### <a name="generate-program-database-file"></a>Gerar arquivo de banco de dados do programa

Por padrão, quando [/debug](debug-generate-debug-info.md) é especificado, o vinculador cria um banco de dados de programa (PDB) que contém informações de depuração. O nome de arquivo padrão para o PDB tem o nome base do programa e a extensão. pdb.

### <a name="strip-private-symbols"></a>Remover símbolos privados

A opção [/PDBSTRIPPED](pdbstripped-strip-private-symbols.md) cria um segundo arquivo de banco de dados do programa (PDB) quando você cria a imagem do programa com qualquer um dos compiladores ou opções do vinculador que geram um arquivo PDB (/Debug,/Z7,/ZD ou/Zi).

### <a name="generate-map-file"></a>Gerar arquivo de mapa

A opção [/MAP](map-generate-mapfile.md) informa o vinculador para criar um mapa.

### <a name="map-file-name"></a>Nome do arquivo de mapa

Um nome especificado pelo usuário para o mapa. Ele substitui o nome padrão.

### <a name="map-exports"></a>Exportações de mapa

A opção [/MapInfo](mapinfo-include-information-in-mapfile.md) informa o vinculador para incluir as informações especificadas em um mapa, que será criado se você especificar a opção/Map. Exportações informa ao vinculador para incluir funções exportadas.

### <a name="debuggable-assembly"></a>Assembly depurável

[/ASSEMBLYDEBUG](assemblydebug-add-debuggableattribute.md) emite o atributo DebuggableAttribute com o controle de informações de depuração e desabilita as otimizações JIT.

## <a name="system-property-page"></a>Página de propriedades do sistema

### <a name="subsystem"></a>Subsistema

A opção [/Subsystem](subsystem-specify-subsystem.md) informa ao sistema operacional como executar o arquivo. exe. A escolha do subsistema afeta o símbolo de ponto de entrada (ou função de ponto de entrada) que o vinculador escolherá.

**Durante**

- **Não definido** -nenhum subsistema definido.
- **Console** -aplicativo de modo de caractere Win32. Os aplicativos de console recebem um console do sistema operacional. Se Main ou wmain for definido, CONSOLE será o padrão.
- O aplicativo **Windows** não requer um console, provavelmente porque ele cria suas próprias janelas para interação com o usuário. Se WinMain ou wWinMain for definido, o WINDOWS será o padrão.
- Drivers de dispositivo **nativo** para o Windows NT. Se/DRIVER: WDM for especificado, NATIVE será o padrão.
- Aplicativo **EFI** -aplicativo EFI.
- **Driver do serviço de inicialização EFI** -driver do serviço de inicialização EFI.
- **EFI ROM** -EFI ROM.
- Runtime **EFI** -tempo de execução EFI.
- **POSIX** -aplicativo que é executado com o subsistema Posix no Windows NT.

### <a name="minimum-required-version"></a>Versão mínima necessária

Especifique a versão mínima necessária do subsistema. Os argumentos são números decimais no intervalo de 0 a 65.535.

### <a name="heap-reserve-size"></a>Tamanho de reserva de heap

Especifica o tamanho de alocação de heap total na memória virtual. O padrão é 1 MB.    ([/Heap](heap-set-heap-size.md): Reserve)

### <a name="heap-commit-size"></a>Tamanho de confirmação de heap

Especifica o tamanho de alocação de heap total na memória física. O padrão é 4 KB.    ([/Heap](heap-set-heap-size.md): reservar, confirmar)

### <a name="stack-reserve-size"></a>Tamanho da reserva da pilha

Especifica o tamanho de alocação de pilha total em memória virtual. O padrão é 1 MB.     ([/Stack](stack-stack-allocations.md): Reserve)

### <a name="stack-commit-size"></a>Tamanho de confirmação da pilha

Especifica o tamanho de alocação de pilha total na memória física. O padrão é 4 KB.     ([/Stack](stack-stack-allocations.md): reservar, confirmar)

### <a name="enable-large-addresses"></a>Habilitar endereços grandes

A opção [/LARGEADDRESSAWARE](largeaddressaware-handle-large-addresses.md) informa ao vinculador que o aplicativo pode manipular endereços maiores que 2 gigabytes. Por padrão,/LARGEADDRESSAWARE: NO será habilitado se/LARGEADDRESSAWARE não for especificado de outra forma na linha do vinculador.

### <a name="terminal-server"></a>Terminal Server

A opção [/TSAWARE](tsaware-create-terminal-server-aware-application.md) define um sinalizador no campo IMAGE_OPTIONAL_HEADER DllCharacteristics no cabeçalho opcional da imagem do programa. Quando esse sinalizador estiver definido, o servidor Host da Sessão da Área de Trabalho Remota não fará certas alterações no aplicativo.

### <a name="swap-run-from-cd"></a>Execução de permuta do CD

A opção [/SWAPRUN](swaprun-load-linker-output-to-swap-file.md) informa o sistema operacional para primeiro copiar a saída do vinculador para um arquivo de permuta e, em seguida, executar a imagem a partir daí. Este é um recurso do Windows NT 4,0 (e posterior). Quando o **CD** for especificado, o sistema operacional copiará a imagem em um disco removível para um arquivo de paginação e, em seguida, a carregará.

### <a name="swap-run-from-network"></a>Execução de permuta da rede

A opção [/SWAPRUN](swaprun-load-linker-output-to-swap-file.md) informa o sistema operacional para primeiro copiar a saída do vinculador para um arquivo de permuta e, em seguida, executar a imagem a partir daí. Este é um recurso do Windows NT 4,0 (e posterior). Se **net** for especificado, o sistema operacional primeiro copiará a imagem binária da rede para um arquivo de permuta e a carregará a partir daí. Essa opção é útil para executar aplicativos na rede.

### <a name="driver"></a>Driver

Use a opção de vinculador [/Driver](driver-windows-nt-kernel-mode-driver.md) para criar um driver de modo kernel do Windows NT.

**Durante**

- **Não definido** -configuração de driver padrão.
- Driver **Driver**
- **Somente** -/Driver: faz com que o vinculador adicione o bit IMAGE_FILE_UP_SYSTEM_ONLY às características no cabeçalho de saída para especificar que ele é um driver uniprocessador (up). O sistema operacional se recusará a carregar um driver ativo em um sistema de multiprocessador (MP).
- **WDM** -/Driver: WDM faz com que o vinculador defina o bit IMAGE_DLLCHARACTERISTICS_WDM_DRIVER no campo DLLCHARACTERISTICS do cabeçalho opcional.

## <a name="optimization-property-page"></a>Página de propriedades de otimização

### <a name="references"></a>Referências

[/Opt](opt-optimizations.md): REF elimina funções e/ou dados que nunca são referenciados enquanto/OPT: NOREF mantém funções e/ou dados que nunca são referenciados. 

### <a name="enable-comdat-folding"></a>Habilitar Dobra COMDAT

Use [/opt](opt-optimizations.md): ICF\[= iterations] para executar o dobramento COMDAT idêntico. 

### <a name="function-order"></a>Ordem da função

A opção [/Order](order-put-functions-in-order.md)informa o link para otimizar seu programa colocando determinados COMDATs na imagem em uma ordem predeterminada. O LINK coloca as funções na ordem especificada dentro de cada seção na imagem.

### <a name="profile-guided-database"></a>Banco de dados guiado por perfil

Especifique o arquivo. pgd para otimizações guiadas por perfil. ([/PGD](pgd-specify-database-for-profile-guided-optimizations.md))

### <a name="link-time-code-generation"></a>Geração de código de tempo de vinculação

Especifica a geração do código de tempo de vinculação. ([/LTCG](ltcg-link-time-code-generation.md))

**Durante**

- **Padrão** -configuração de LTCG padrão.
- **Usar geração de código de tempo de link rápido** -use a geração de código de tempo de link com [/FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md).
- **Usar geração de código de tempo de link** -usar geração de [código para tempo de vinculação](ltcg-link-time-code-generation.md).
- **Otimização guiada por perfil-instrumento** -use [otimização guiada por perfil](../profile-guided-optimizations.md) com:P ginstrument.
- **Otimização guiada por perfil-otimização** -especifica que o vinculador deve usar os dados de perfil criados após a execução do binário instrumentado para criar uma imagem otimizada.
- **Otimização guiada por perfil-Update** -permite e rastreia a lista de arquivos de entrada a serem adicionados ou modificados a partir do que foi especificado na fase de:P ginstrument.

## <a name="embedded-idl-property-page"></a>Página de propriedades IDL inserida

### <a name="midl-commands"></a>Comandos de MIDL

Especifique as opções de linha de comando MIDL. ([/MIDL](midl-specify-midl-command-line-options.md):@responsefile)

### <a name="ignore-embedded-idl"></a>Ignorar IDL inserida

A opção [/IGNOREIDL](ignoreidl-don-t-process-attributes-into-midl.md) especifica que qualquer atributo IDL no código-fonte não deve ser processado em um arquivo. idl.

### <a name="merged-idl-base-file-name"></a>Nome do arquivo base IDL mesclado

A opção [/IDLOUT](idlout-name-midl-output-files.md) especifica o nome e a extensão do arquivo. idl.

### <a name="type-library"></a>Biblioteca de tipos

A opção [/TLBOUT](tlbout-name-dot-tlb-file.md) especifica o nome e a extensão do arquivo. tlb.

### <a name="typelib-resource-id"></a>ID de recurso de TypeLib

Permite especificar a ID de recurso da biblioteca de tipos gerada pelo vinculador. ([/TLBID](tlbid-specify-resource-id-for-typelib.md): ID)

## <a name="windows-metadata-property-page"></a>Página de propriedades de metadados do Windows

### <a name="generate-windows-metadata"></a>Gerar metadados do Windows

Habilita ou desabilita a geração de metadados do Windows.

**Durante**

- **Sim** – habilite a geração de arquivos de metadados do Windows.
- **Não** -desabilite a geração de arquivos de metadados do Windows.

### <a name="windows-metadata-file"></a>Arquivo de metadados do Windows

A opção [/WINMDFILE](winmdfile-specify-winmd-file.md) .

### <a name="windows-metadata-key-file"></a>Arquivo de chave de metadados do Windows

Especifique a chave ou o par de chaves para assinar um metadado do Windows. ([/WINMDKEYFILE](winmdkeyfile-specify-winmd-key-file.md): filename)

### <a name="windows-metadata-key-container"></a>Contêiner de chave de metadados do Windows

Especifique um contêiner de chave para assinar um metadado do Windows. ([/WINMDKEYCONTAINER](winmdkeycontainer-specify-key-container.md): nome)

### <a name="windows-metadata-delay-sign"></a>Sinal de atraso de metadados do Windows

Assine parcialmente um metadado do Windows. Use [/WINMDDELAYSIGN](winmddelaysign-partially-sign-a-winmd.md) se você quiser apenas posicionar a chave pública nos metadados do Windows. O padrão é/WINMDDELAYSIGN: NO.

## <a name="advanced-property-page"></a>Página de propriedades avançada

### <a name="entry-point"></a>Ponto de entrada

A opção [/entry](entry-entry-point-symbol.md) especifica uma função de ponto de entrada como o endereço inicial de um arquivo. exe ou dll.

### <a name="no-entry-point"></a>Nenhum ponto de entrada

A opção [/NOENTRY](noentry-no-entry-point.md)é necessária para criar uma DLL somente de recursos. Use esta opção para impedir que o link vincule uma referência `_main` à dll.

### <a name="set-checksum"></a>Definir soma de verificação

A opção [/Release](release-set-the-checksum.md) define a soma de verificação no cabeçalho de um arquivo. exe.

### <a name="base-address"></a>Endereço base

Define um endereço básico para o programa. ([/Base](base-base-address.md): {endereço\[, tamanho] | @filename, chave})

### <a name="randomized-base-address"></a>Endereço base aleatório

Endereço base aleatório. ([/DYNAMICBASE](dynamicbase-use-address-space-layout-randomization.md)\[: NO])

### <a name="fixed-base-address"></a>Endereço base fixo

Cria um programa que só pode ser carregado em seu endereço básico preferido. ([/FIXED](fixed-fixed-base-address.md)\[: NO])

### <a name="data-execution-prevention-dep"></a>Prevenção de execução de dados (DEP)

Marca um executável como tendo sido testado para ser compatível com o recurso de prevenção de execução de dados do Windows. ([/NXCOMPAT](nxcompat-compatible-with-data-execution-prevention.md)\[: NO])

### <a name="turn-off-assembly-generation"></a>Desativar a geração de assembly

A opção [/noAssembly](noassembly-create-a-msil-module.md) informa o vinculador para criar uma imagem para o arquivo de saída atual sem um assembly .NET Framework.

### <a name="unload-delay-loaded-dll"></a>Descarregar DLL carregada com atraso

O qualificador **Unload** informa a função auxiliar de carregamento de atraso para dar suporte ao descarregamento explícito da dll. ([/DELAY](delay-delay-load-import-settings.md): UNLOAD)

### <a name="nobind-delay-loaded-dll"></a>DLL de atraso NOBIND carregado

O  qualificador NOBIND instrui o vinculador a não incluir um IAT vinculável na imagem final. O padrão é criar a IAT associável para DLLs carregadas com atraso. ([/DELAY](delay-delay-load-import-settings.md): NOBIND)

### <a name="import-library"></a>Biblioteca de importação

Substitui o nome da biblioteca de importação padrão. ([/IMPLIB](implib-name-import-library.md): filename)

### <a name="merge-sections"></a>Mesclar seções

A opção [/Merge](merge-combine-sections.md) combina a primeira seção (from) com a segunda seção (to), nomeando a seção resultante como. Por exemplo,/Merge:. rdata =. Text.

### <a name="target-machine"></a>Computador de destino

A opção [/Machine](machine-specify-target-platform.md) especifica a plataforma de destino para o programa.

**Durante**

- **Não definido**
- **MachineARM**
- **MachineARM64**
- **MachineEBC**
- **MachineIA64**
- **MachineMIPS**
- **MachineMIPS16**
- **MachineMIPSFPU**
- **MachineMIPSFPU16**
- **MachineSH4**
- **MachineTHUMB**
- **MachineX64**
- **MachineX86**

### <a name="profile"></a>Perfil

Produz um arquivo de saída que pode ser usado com o criador de perfil de Ferramentas de desempenho. Requer que GenerateDebugInformation (/[/debug](debug-generate-debug-info.md)) seja definido. ([/PROFILE](profile-performance-tools-profiler.md))

### <a name="clr-thread-attribute"></a>Atributo de thread CLR

Especifique explicitamente o atributo threading para o ponto de entrada do seu programa CLR.

**Durante**

- **Atributo threading do MTA** – aplica o atributo MTAThreadAttribute ao ponto de entrada do seu programa.
- **Atributo threading STA** – aplica o atributo STAThreadAttribute ao ponto de entrada do seu programa.
- **Atributo de Threading padrão** -o mesmo que não especificar [/CLRTHREADATTRIBUTE](clrthreadattribute-set-clr-thread-attribute.md). Permite que o CLR (Common Language Runtime) defina o atributo threading padrão.

### <a name="clr-image-type"></a>Tipo de imagem CLR

Define o tipo (IJW, puro ou seguro) de uma imagem do CLR.

**Durante**

- **Forçar imagem IJW**
- **Forçar imagem IL pura**
- **Forçar imagem IL segura**
- **Tipo de imagem padrão**

### <a name="key-file"></a>Arquivo de chave

Especifique a chave ou o par de chaves para assinar um assembly. ([/Keyfile](keyfile-specify-key-or-key-pair-to-sign-an-assembly.md): filename)

### <a name="key-container"></a>Contêiner de chave

Especifique um contêiner de chave para assinar um assembly. ([/Keycontainer](keycontainer-specify-a-key-container-to-sign-an-assembly.md): nome)

### <a name="delay-sign"></a>Sinal de atraso

Assinar parcialmente um assembly. Use [/delaysign](delaysign-partially-sign-an-assembly.md) se você quiser apenas posicionar a chave pública no assembly. O padrão é/DELAYSIGN: NO.

### <a name="clr-unmanaged-code-check"></a>Verificação de código não gerenciado do CLR

[/CLRUNMANAGEDCODECHECK](clrunmanagedcodecheck-add-suppressunmanagedcodesecurityattribute.md) especifica se o vinculador aplicará SuppressUnmanagedCodeSecurityAttribute às chamadas PInvoke geradas pelo vinculador do código gerenciado em DLLs nativas.

### <a name="error-reporting"></a>Relatório de Erros

Permite fornecer informações de ICE (erro interno do compilador) diretamente à equipe do Visual C++.

**Durante**

- **PromptImmediately** -solicitar imediatamente.
- **Fila para o próximo** logon-fila para o próximo logon.
- **Enviar relatório de erros** – Enviar relatório de erros.
- **Nenhum relatório de erros** -nenhum relatório de erros.

### <a name="sectionalignment"></a>SectionAlignment

A opção [/align](align-section-alignment.md) especifica o alinhamento de cada seção dentro do espaço de endereço linear do programa. O argumento Number está em bytes e deve ser uma potência de dois.

### <a name="preserve-last-error-code-for-pinvoke-calls"></a>Preservar o último código de erro para chamadas do PInvoke

[/CLRSUPPORTLASTERROR](clrsupportlasterror-preserve-last-error-code-for-pinvoke-calls.md), que é ativado por padrão, preserva o último código de erro das funções chamadas por meio do mecanismo P/Invoke, que permite chamar funções nativas em DLLs, do código compilado com/CLR.

**Durante**

- **Habilitado** -habilitar CLRSupportLastError.
- **Desabilitado** -desabilitar CLRSupportLastError.
- **Somente DLLs do sistema** – habilitar CLRSupportLastError somente para DLLs do sistema.

### <a name="image-has-safe-exception-handlers"></a>A imagem tem manipuladores de exceção segura

Quando [/SAFESEH](safeseh-image-has-safe-exception-handlers.md) for especificado, o vinculador produzirá apenas uma imagem se ele também puder produzir uma tabela dos manipuladores de exceção segura da imagem. Esta tabela especifica para o sistema operacional quais manipuladores de exceção são válidos para a imagem.
