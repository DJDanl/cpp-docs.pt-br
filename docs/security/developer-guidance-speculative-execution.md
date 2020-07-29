---
title: Diretrizes para desenvolvedores do C++ para canais laterais de execução especulativa
ms.date: 07/10/2018
helpviewer_keywords:
- Visual C++, security
- security [C++]
- security [C++], best practices
- Spectre
- CVE-2017-5753
- Speculative Execution
ms.openlocfilehash: d0b9faf0bd11892c05e25e981e8cd729cb623dd4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219320"
---
# <a name="c-developer-guidance-for-speculative-execution-side-channels"></a>Diretrizes para desenvolvedores do C++ para canais laterais de execução especulativa

Este artigo contém orientações para os desenvolvedores auxiliarem na identificação e mitigação de vulnerabilidades de hardware de canal lateral de execução especulativa em software C++. Essas vulnerabilidades podem divulgar informações confidenciais entre limites de confiança e podem afetar o software que é executado em processadores que dão suporte à execução especulativa de instruções e de uso fora de ordem. Essa classe de vulnerabilidades foi descrita pela primeira vez em janeiro de 2018, e em segundo plano e orientações adicionais podem ser encontradas no [comunicado de segurança da Microsoft](https://portal.msrc.microsoft.com/security-guidance/advisory/ADV180002).

As diretrizes fornecidas por este artigo estão relacionadas às classes de vulnerabilidades representadas por:

1. CVE-2017-5753, também conhecido como Spectre Variant 1. Essa classe de vulnerabilidade de hardware está relacionada a canais laterais que podem surgir devido à execução especulativa que ocorre como resultado de uma previsão incorreta da ramificação condicional. O compilador do Microsoft C++ no Visual Studio 2017 (a partir da versão 15.5.5) inclui suporte para o `/Qspectre` comutador que fornece uma mitigação em tempo de compilação para um conjunto limitado de padrões de codificação potencialmente vulneráveis relacionados ao CVE-2017-5753. A `/Qspectre` opção também está disponível no Visual Studio 2015 atualização 3 a [KB 4338871](https://support.microsoft.com/help/4338871). A documentação do sinalizador [/Qspectre](https://docs.microsoft.com/cpp/build/reference/qspectre) fornece mais informações sobre seus efeitos e uso.

2. CVE-2018-3639, também conhecido como [bypass do armazenamento especulativo (SSB)](https://aka.ms/sescsrdssb). Essa classe de vulnerabilidade de hardware está relacionada a canais laterais que podem surgir devido à execução especulativa de uma carga antecipada de um armazenamento dependente como resultado de uma previsão incorreta de acesso à memória.

Uma introdução acessível às vulnerabilidades do canal lateral de execução especulativa pode ser encontrada na apresentação intitulada [o caso de Spectre e Meltdown](https://www.youtube.com/watch?v=_4O0zMW-Zu4) por uma das equipes de pesquisa que descobriram esses problemas.

## <a name="what-are-speculative-execution-side-channel-hardware-vulnerabilities"></a>O que são vulnerabilidades de hardware de canal do lado de execução especulativa?

As CPUs modernas fornecem níveis mais altos de desempenho, fazendo uso de uma execução especulativa e fora de ordem de instruções. Por exemplo, isso geralmente é feito prevendo o destino de branches (condicional e indireto) que permite que a CPU comece a executar instruções de forma especulativa no destino da ramificação prevista, evitando assim uma parada até que o destino da ramificação real seja resolvido. Caso a CPU descubra posteriormente que ocorreu um erro de previsão, todo o estado da máquina que foi computada especulativamente é Descartado. Isso garante que não haja efeitos visíveis de forma arquitetônica da especulação incorreta.

Embora a execução especulativa não afete o estado de arquitetura visível, ela pode deixar rastreamentos residuais no estado de não-arquitetura, como os vários caches usados pela CPU. São esses rastreamentos residuais de execução especulativa que podem dar às vulnerabilidades do canal de aumento. Para entender melhor isso, considere o fragmento de código a seguir, que fornece um exemplo de CVE-2017-5753 (bypass de verificação de limites):

```cpp
// A pointer to a shared memory region of size 1MB (256 * 4096)
unsigned char *shared_buffer;

unsigned char ReadByte(unsigned char *buffer, unsigned int buffer_size, unsigned int untrusted_index) {
    if (untrusted_index < buffer_size) {
        unsigned char value = buffer[untrusted_index];
        return shared_buffer[value * 4096];
    }
}
```

Neste exemplo, `ReadByte` é fornecido um buffer, um tamanho de buffer e um índice nesse buffer. O parâmetro de índice, conforme especificado por `untrusted_index` , é fornecido por um contexto menos privilegiado, como um processo não administrativo. Se `untrusted_index` for menor que `buffer_size` , o caractere nesse índice será lido `buffer` e usado para indexar em uma região compartilhada de memória referenciada por `shared_buffer` .

Do ponto de vista da arquitetura, essa sequência de código é perfeitamente segura, pois é garantido que `untrusted_index` será sempre menor que `buffer_size` . No entanto, na presença de execução especulativa, é possível que a CPU faça uma previsão incorreta da ramificação condicional e execute o corpo da instrução If mesmo quando `untrusted_index` for maior ou igual a `buffer_size` . Como consequência disso, a CPU pode, especulativamente, ler um byte de além dos limites de `buffer` (que poderia ser um segredo) e, em seguida, usar esse valor de byte para computar o endereço de uma carga subsequente por meio do `shared_buffer` .

Embora a CPU eventualmente detecte esse erro de previsão, os efeitos colaterais podem ser deixados no cache da CPU que revela informações sobre o valor de byte que foi lido dos limites de `buffer` . Esses efeitos colaterais podem ser detectados por um contexto menos privilegiado em execução no sistema, investigando a rapidez com que cada linha de cache `shared_buffer` é acessada. As etapas que podem ser executadas para fazer isso são:

1. **Invocar `ReadByte` várias vezes com `untrusted_index` menos de `buffer_size` **. O contexto de ataque pode fazer com que o contexto da vítima invoque `ReadByte` (por exemplo, via RPC), de modo que o Predictor da ramificação seja treinado para não ser levado como `untrusted_index` é menor que `buffer_size` .

2. **Libere todas as linhas de `shared_buffer` cache no **. O contexto de ataque deve liberar todas as linhas de cache na região compartilhada da memória referenciada por `shared_buffer` . Como a região de memória é compartilhada, isso é simples e pode ser feito usando intrínsecos, como `_mm_clflush` .

3. **Invocar `ReadByte` com `untrusted_index` ser maior `buffer_size` que **. O contexto de ataque faz com que o contexto da vítima seja invocado `ReadByte` , de modo que ele prevê incorretamente que a ramificação não será executada. Isso faz com que o processador execute especulativamente o corpo do bloco If com `untrusted_index` um maior que `buffer_size` , o que leva a uma leitura fora dos limites de `buffer` . Consequentemente, `shared_buffer` é indexado usando um valor potencialmente secreto que foi lido fora dos limites, fazendo com que a respectiva linha de cache seja carregada pela CPU.

4. **Leia cada linha de cache `shared_buffer` para ver qual é acessado mais rapidamente**. O contexto de ataque pode ler cada linha de cache no `shared_buffer` e detectar a linha de cache que carrega significativamente mais rápido do que as outras. Essa é a linha de cache que provavelmente foi apresentada pela etapa 3. Como há uma relação de 1:1 entre o valor de byte e a linha de cache neste exemplo, isso permite que o invasor inferir o valor real do byte que foi lido fora dos limites.

As etapas acima fornecem um exemplo de como usar uma técnica conhecida como liberação + recarga em conjunto com a exploração de uma instância de CVE-2017-5753.

## <a name="what-software-scenarios-can-be-impacted"></a>Quais cenários de software podem ser afetados?

O desenvolvimento de software seguro usando um processo como o SDL ( [ciclo de vida de desenvolvimento da segurança](https://www.microsoft.com/sdl/) ) normalmente exige que os desenvolvedores identifiquem os limites de confiança que existem em seu aplicativo. Existe um limite de confiança em locais onde um aplicativo pode interagir com os dados fornecidos por um contexto menos confiável, como outro processo no sistema ou um processo de modo de usuário não administrativo no caso de um driver de dispositivo em modo kernel. A nova classe de vulnerabilidades envolvendo canais do lado de execução especulativa é relevante para muitos dos limites de confiança em modelos de segurança de software existentes que isolam o código e os dados em um dispositivo.

A tabela a seguir fornece um resumo dos modelos de segurança de software em que os desenvolvedores podem precisar se preocupar com essas vulnerabilidades que ocorrem:

|Limite de confiança|Descrição|
|----------------|----------------|
|Limite da máquina virtual|Os aplicativos que isolam cargas de trabalho em máquinas virtuais separadas que recebem dados não confiáveis de outra máquina virtual podem estar em risco.|
|Limite do kernel|Um driver de dispositivo de modo kernel que recebe dados não confiáveis de um processo de modo de usuário não administrativo pode estar em risco.|
|Limite do processo|Um aplicativo que recebe dados não confiáveis de outro processo em execução no sistema local, como por meio de uma RPC (chamada de procedimento remoto), memória compartilhada ou outros mecanismos de IPC (comunicação entre processos) pode estar em risco.|
|Limite de enclave|Um aplicativo que é executado em um enclave seguro (como o Intel SGX) que recebe dados não confiáveis de fora do enclave pode estar em risco.|
|Limite de idioma|Um aplicativo que interpreta ou JIT (just-in-time) compila e executa código não confiável escrito em uma linguagem de nível superior pode estar em risco.|

Os aplicativos que têm a superfície de ataque exposta a qualquer um dos limites de confiança acima devem revisar o código na superfície de ataque para identificar e atenuar possíveis instâncias de vulnerabilidades de canal lateral de execução especulativa. Deve-se observar que os limites de confiança expostos a superfícies de ataque remoto, como protocolos de rede remota, não foram demonstrados como risco de vulnerabilidades de canal lateral de execução especulativa.

## <a name="potentially-vulnerable-coding-patterns"></a>Padrões de codificação potencialmente vulneráveis

As vulnerabilidades do canal lateral de execução especulativa podem surgir como consequência de vários padrões de codificação. Esta seção descreve os padrões de codificação potencialmente vulneráveis e fornece exemplos para cada um, mas deve ser reconhecido que as variações nesses temas podem existir. Dessa forma, os desenvolvedores são aconselhados a usar esses padrões como exemplos e não como uma lista completa de todos os padrões de codificação potencialmente vulneráveis. As mesmas classes de vulnerabilidades de segurança de memória que podem existir no software hoje também podem existir juntamente com caminhos especulativos e fora de ordem de execução, incluindo, mas não se limitando a estouros de buffer, acessos de matriz fora de limites, uso de memória não inicializado, confusão de tipo e assim por diante. Os mesmos primitivos que os invasores podem usar para explorar vulnerabilidades de segurança de memória ao longo dos caminhos de arquitetura também podem se aplicar a caminhos especulares.

Em geral, os canais laterais de execução especulativa relacionados à previsão de incorretação de ramificação condicional podem surgir quando uma expressão condicional opera nos dados que podem ser controlados ou influenciados por um contexto menos confiável. Por exemplo, isso pode incluir expressões condicionais usadas **`if`** nas **`for`** instruções,, **`while`** , **`switch`** ou ternário. Para cada uma dessas instruções, o compilador pode gerar uma ramificação condicional que a CPU pode então prever o destino da ramificação em tempo de execução.

Para cada exemplo, um comentário com a frase "barreira de ESPECULAção" é inserido onde um desenvolvedor pode introduzir uma barreira como uma mitigação. Isso é discutido mais detalhadamente na seção sobre mitigações.

## <a name="speculative-out-of-bounds-load"></a>Carga fora dos limites especulativos

Essa categoria de padrões de codificação envolve uma previsão incorreta da ramificação condicional que leva a um acesso restrito à memória.

### <a name="array-out-of-bounds-load-feeding-a-load"></a>Carga fora dos limites da matriz alimentando uma carga

Esse padrão de codificação é o padrão de codificação vulnerável originalmente descrito para CVE-2017-5753 (delimite de verificação de limites). A seção de plano de fundo deste artigo explica esse padrão em detalhes.

```cpp
// A pointer to a shared memory region of size 1MB (256 * 4096)
unsigned char *shared_buffer;

unsigned char ReadByte(unsigned char *buffer, unsigned int buffer_size, unsigned int untrusted_index) {
    if (untrusted_index < buffer_size) {
        // SPECULATION BARRIER
        unsigned char value = buffer[untrusted_index];
        return shared_buffer[value * 4096];
    }
}
```

Da mesma forma, uma carga fora dos limites da matriz pode ocorrer em conjunto com um loop que exceda sua condição de encerramento devido a uma previsão incorreta. Neste exemplo, a ramificação condicional associada à `x < buffer_size` expressão pode prever incorretamente e executar de forma especulativa o corpo do **`for`** loop quando `x` é maior ou igual a `buffer_size` , resultando, assim, em uma carga de fora dos limites especulativo.

```cpp
// A pointer to a shared memory region of size 1MB (256 * 4096)
unsigned char *shared_buffer;

unsigned char ReadBytes(unsigned char *buffer, unsigned int buffer_size) {
    for (unsigned int x = 0; x < buffer_size; x++) {
        // SPECULATION BARRIER
        unsigned char value = buffer[x];
        return shared_buffer[value * 4096];
    }
}
```

### <a name="array-out-of-bounds-load-feeding-an-indirect-branch"></a>Carga fora de limites de matriz alimentando uma ramificação indireta

Esse padrão de codificação envolve o caso em que uma previsão de incorretação de ramificação condicional pode levar a um acesso fora de limites a uma matriz de ponteiros de função que, em seguida, leva a uma ramificação indireta para o endereço de destino que foi lido fora dos limites. O trecho a seguir fornece um exemplo que demonstra isso.

Neste exemplo, um identificador de mensagem não confiável é fornecido para DispatchMessage por meio do `untrusted_message_id` parâmetro. Se `untrusted_message_id` for menor que `MAX_MESSAGE_ID` , ele será usado para indexar em uma matriz de ponteiros de função e Branch para o destino de ramificação correspondente. Esse código é seguro em termos de segurança, mas se a CPU previr incorretamente a ramificação condicional, isso poderá resultar na `DispatchTable` indexação por `untrusted_message_id` quando seu valor for maior ou igual a `MAX_MESSAGE_ID` , o que leva a um acesso fora dos limites. Isso pode resultar na execução especulativa de um endereço de destino de ramificação que é derivado além dos limites da matriz, o que pode levar à divulgação de informações dependendo do código executado de forma especulativa.

```cpp
#define MAX_MESSAGE_ID 16

typedef void (*MESSAGE_ROUTINE)(unsigned char *buffer, unsigned int buffer_size);

const MESSAGE_ROUTINE DispatchTable[MAX_MESSAGE_ID];

void DispatchMessage(unsigned int untrusted_message_id, unsigned char *buffer, unsigned int buffer_size) {
    if (untrusted_message_id < MAX_MESSAGE_ID) {
        // SPECULATION BARRIER
        DispatchTable[untrusted_message_id](buffer, buffer_size);
    }
}
```

Assim como no caso de uma carga fora dos limites da matriz alimentar outra carga, essa condição também pode surgir em conjunto com um loop que exceda sua condição de encerramento devido a uma previsão incorreta.

### <a name="array-out-of-bounds-store-feeding-an-indirect-branch"></a>Armazenamento fora de limites de matriz alimentando uma ramificação indireta

Enquanto o exemplo anterior mostrou como uma carga fora de limites restritos pode influenciar um destino de ramificação indireta, também é possível para um armazenamento fora de limites para modificar um destino de ramificação indireta, como um ponteiro de função ou um endereço de retorno. Isso pode potencialmente levar à execução especulativa de um endereço especificado pelo invasor.

Neste exemplo, um índice não confiável é passado pelo `untrusted_index` parâmetro. Se `untrusted_index` for menor que a contagem de elementos da `pointers` matriz (256 elementos), o valor de ponteiro fornecido em `ptr` será gravado na `pointers` matriz. Esse código é seguro em termos de segurança, mas se a CPU previr incorretamente a ramificação condicional, isso poderá resultar na `ptr` escrita especulativa dos limites da matriz alocada na pilha `pointers` . Isso pode levar à corrupção especulativa do endereço de retorno para `WriteSlot` . Se um invasor puder controlar o valor de `ptr` , ele poderá causar a execução especulativa de um endereço arbitrário quando `WriteSlot` retornar ao longo do caminho especulativo.

```cpp
unsigned char WriteSlot(unsigned int untrusted_index, void *ptr) {
    void *pointers[256];
    if (untrusted_index < 256) {
        // SPECULATION BARRIER
        pointers[untrusted_index] = ptr;
    }
}
```

Da mesma forma, se uma variável local de ponteiro de função tiver `func` sido alocada na pilha, poderá ser possível modificar especulativamente o endereço que `func` se refere quando a previsão de ramificação condicional ocorrer. Isso pode resultar na execução especulativa de um endereço arbitrário quando o ponteiro de função é chamado por meio de.

```cpp
unsigned char WriteSlot(unsigned int untrusted_index, void *ptr) {
    void *pointers[256];
    void (*func)() = &callback;
    if (untrusted_index < 256) {
        // SPECULATION BARRIER
        pointers[untrusted_index] = ptr;
    }
    func();
}
```

Deve-se observar que esses dois exemplos envolvem a modificação especulativa de ponteiros de ramificação indiretos alocados para pilha. É possível que a modificação especulativa também possa ocorrer para variáveis globais, memória alocada para heap e até mesmo memória somente leitura em algumas CPUs. Para a memória alocada para pilha, o compilador do Microsoft C++ já usa etapas para tornar mais difícil modificar de forma especulativa os destinos de ramificação indiretos alocados na pilha, como reordenar variáveis locais, de forma que os buffers sejam colocados adjacentes a um cookie de segurança como parte do recurso de segurança do compilador [/GS](https://docs.microsoft.com/cpp/build/reference/gs-buffer-security-check) .

## <a name="speculative-type-confusion"></a>Confusão de tipo especulativo

Essa categoria lida com padrões de codificação que podem dar a elevação a uma confusão de tipo especulativo. Isso ocorre quando a memória é acessada usando um tipo incorreto ao longo de um caminho não-arquitetônico durante a execução especulativa. O desvio de ramificação condicional e o bypass de armazenamento especulativo podem potencialmente levar a uma confusão de tipo especulativo.

Para bypass de armazenamento especulativo, isso pode ocorrer em cenários em que um compilador reutiliza um local de pilha para variáveis de vários tipos. Isso ocorre porque o armazenamento arquitetônico de uma variável do tipo `A` pode ser ignorado, permitindo assim que a carga do tipo seja `A` executada especulativamente antes de a variável ser atribuída. Se a variável armazenada anteriormente for de um tipo diferente, isso poderá criar as condições para uma confusão de tipo especulativo.

Para um erro de previsão de ramificação condicional, o trecho de código a seguir será usado para descrever diferentes condições que a confusão de tipo especulativa pode dar ao aumento.

```cpp
enum TypeName {
    Type1,
    Type2
};

class CBaseType {
public:
    CBaseType(TypeName type) : type(type) {}
    TypeName type;
};

class CType1 : public CBaseType {
public:
    CType1() : CBaseType(Type1) {}
    char field1[256];
    unsigned char field2;
};

class CType2 : public CBaseType {
public:
    CType2() : CBaseType(Type2) {}
    void (*dispatch_routine)();
    unsigned char field2;
};

// A pointer to a shared memory region of size 1MB (256 * 4096)
unsigned char *shared_buffer;

unsigned char ProcessType(CBaseType *obj)
{
    if (obj->type == Type1) {
        // SPECULATION BARRIER
        CType1 *obj1 = static_cast<CType1 *>(obj);

        unsigned char value = obj1->field2;

        return shared_buffer[value * 4096];
    }
    else if (obj->type == Type2) {
        // SPECULATION BARRIER
        CType2 *obj2 = static_cast<CType2 *>(obj);

        obj2->dispatch_routine();

        return obj2->field2;
    }
}
```

### <a name="speculative-type-confusion-leading-to-an-out-of-bounds-load"></a>Confusão de tipo especulativo que leva a uma carga fora de limites

Esse padrão de codificação envolve o caso em que uma confusão de tipo especulativo pode resultar em um acesso de campo de tipo confuso ou incorreto, onde o valor carregado alimenta um endereço de carregamento subsequente. Isso é semelhante ao padrão de codificação da matriz fora de limites, mas é manifestado por meio de uma sequência de codificação alternativa, conforme mostrado acima. Neste exemplo, um contexto de ataque pode fazer com que o contexto da vítima seja executado `ProcessType` várias vezes com um objeto do tipo `CType1` (o `type` campo é igual a `Type1` ). Isso terá o efeito de treinar a ramificação condicional para que a primeira **`if`** instrução não seja realizada. O contexto de ataque pode fazer com que o contexto da vítima seja executado `ProcessType` com um objeto do tipo `CType2` . Isso pode resultar em uma confusão de tipo especulativo se a ramificação condicional da primeira **`if`** instrução previr incorretamente e executar o corpo da **`if`** instrução, convertendo, assim, um objeto do tipo `CType2` para `CType1` . Como `CType2` é menor que `CType1` , o acesso de memória para `CType1::field2` resultará em uma carga de dados restrito fora dos limites que pode ser secreta. Esse valor é usado em uma carga a partir da `shared_buffer` qual o pode criar efeitos colaterais observáveis, como com o exemplo de limite fora de limites de matriz descrito anteriormente.

### <a name="speculative-type-confusion-leading-to-an-indirect-branch"></a>Confusão de tipo especulativo que leva a uma ramificação indireta

Esse padrão de codificação envolve o caso em que uma confusão de tipo especulativo pode resultar em uma ramificação indireta não segura durante a execução especulativa. Neste exemplo, um contexto de ataque pode fazer com que o contexto da vítima seja executado `ProcessType` várias vezes com um objeto do tipo `CType2` (o `type` campo é igual a `Type2` ). Isso terá o efeito de treinar a ramificação condicional para a primeira **`if`** instrução a ser executada e a `else if` instrução não ser executada. O contexto de ataque pode fazer com que o contexto da vítima seja executado `ProcessType` com um objeto do tipo `CType1` . Isso pode resultar em uma confusão de tipo especulativo se a ramificação condicional da primeira **`if`** instrução for executada e a `else if` instrução prever não for realizada, executando o corpo do `else if` e convertendo um objeto do tipo `CType1` para `CType2` . Como o `CType2::dispatch_routine` campo se sobrepõe à **`char`** matriz `CType1::field1` , isso pode resultar em uma ramificação indireta especulativa para um destino de ramificação não intencional. Se o contexto de ataque puder controlar os valores de bytes na `CType1::field1` matriz, eles poderão controlar o endereço de destino da ramificação.

## <a name="speculative-uninitialized-use"></a>Uso não inicializado especulativo

Essa categoria de padrões de codificação envolve cenários em que a execução especulativa pode acessar memória não inicializada e usá-la para alimentar uma carga subsequente ou uma ramificação indireta. Para que esses padrões de codificação sejam exploráveis, um invasor precisa ser capaz de controlar ou influenciar de acordo com o conteúdo da memória usado sem ser inicializado pelo contexto em que está sendo usado.

### <a name="speculative-uninitialized-use-leading-to-an-out-of-bounds-load"></a>Uso especulativo não inicializado levando a uma carga fora dos limites

Um uso especulativo não inicializado pode potencialmente levar a uma carga fora do limite usando um valor controlado pelo invasor. No exemplo a seguir, o valor de `index` é atribuído `trusted_index` em todos os caminhos arquitetônicos e `trusted_index` é considerado menor ou igual a `buffer_size` . No entanto, dependendo do código produzido pelo compilador, é possível que um bypass de armazenamento especulativo possa ocorrer, permitindo que o carregamento `buffer[index]` e as expressões dependentes sejam executados à frente da atribuição `index` . Se isso ocorrer, um valor não inicializado para `index` será usado como o deslocamento no `buffer` qual o pode permitir que um invasor Leia informações confidenciais fora de limites e transmita isso por meio de um canal lateral por meio da carga dependente de `shared_buffer` .

```cpp
// A pointer to a shared memory region of size 1MB (256 * 4096)
unsigned char *shared_buffer;

void InitializeIndex(unsigned int trusted_index, unsigned int *index) {
    *index = trusted_index;
}

unsigned char ReadByte(unsigned char *buffer, unsigned int buffer_size, unsigned int trusted_index) {
    unsigned int index;

    InitializeIndex(trusted_index, &index); // not inlined

    // SPECULATION BARRIER
    unsigned char value = buffer[index];
    return shared_buffer[value * 4096];
}
```

### <a name="speculative-uninitialized-use-leading-to-an-indirect-branch"></a>Uso especulativo não inicializado levando a uma ramificação indireta

Um uso especulativo não inicializado pode potencialmente levar a uma ramificação indireta em que o destino da ramificação é controlado por um invasor. No exemplo a seguir, `routine` é atribuído a um `DefaultMessageRoutine1` ou `DefaultMessageRoutine` dependendo do valor de `mode` . No caminho arquitetônico, isso resultará `routine` sempre sendo inicializado à frente da ramificação indireta. No entanto, dependendo do código produzido pelo compilador, pode ocorrer um bypass de armazenamento especulativo que permite que a ramificação indireta `routine` seja executada especulativamente à frente da atribuição `routine` . Se isso ocorrer, um invasor poderá ser capaz de executar especulativamente a partir de um endereço arbitrário, supondo que o invasor possa influenciar ou controlar o valor não inicializado de `routine` .

```cpp
#define MAX_MESSAGE_ID 16

typedef void (*MESSAGE_ROUTINE)(unsigned char *buffer, unsigned int buffer_size);

const MESSAGE_ROUTINE DispatchTable[MAX_MESSAGE_ID];
extern unsigned int mode;

void InitializeRoutine(MESSAGE_ROUTINE *routine) {
    if (mode == 1) {
        *routine = &DefaultMessageRoutine1;
    }
    else {
        *routine = &DefaultMessageRoutine;
    }
}

void DispatchMessage(unsigned int untrusted_message_id, unsigned char *buffer, unsigned int buffer_size) {
    MESSAGE_ROUTINE routine;

    InitializeRoutine(&routine); // not inlined

    // SPECULATION BARRIER
    routine(buffer, buffer_size);
}
```

## <a name="mitigation-options"></a>Opções de mitigação

As vulnerabilidades do canal lateral de execução especulativa podem ser atenuadas fazendo alterações no código-fonte. Essas alterações podem envolver a mitigação de instâncias específicas de uma vulnerabilidade, como adicionar uma *barreira de especulação*ou fazer alterações no design de um aplicativo para tornar as informações confidenciais inacessíveis à execução especulativa.

### <a name="speculation-barrier-via-manual-instrumentation"></a>Barreira de especulação via instrumentação manual

Uma *barreira de especulação* pode ser inserida manualmente por um desenvolvedor para impedir que a execução especulativa continue em um caminho de não-arquitetura. Por exemplo, um desenvolvedor pode inserir uma barreira de especulação antes de um padrão de codificação perigoso no corpo de um bloco condicional, seja no início do bloco (após a ramificação condicional) ou antes da primeira carga que for preocupante. Isso impedirá que uma previsão de ramificação condicional execute o código perigoso em um caminho que não seja de arquitetura ao serializar a execução. A sequência de barreira de especulação difere pela arquitetura de hardware, conforme descrito pela tabela a seguir:

|Arquitetura|Barreira de especulação intrínseca para CVE-2017-5753|Barreira de especulação intrínseca para CVE-2018-3639|
|----------------|----------------|----------------|
|x86/x64|_mm_lfence ()|_mm_lfence ()|
|ARM|não disponível atualmente|__dsb (0)|
|ARM64|não disponível atualmente|__dsb (0)|

Por exemplo, o seguinte padrão de código pode ser mitigado usando o `_mm_lfence` intrínseco, conforme mostrado abaixo.

```cpp
// A pointer to a shared memory region of size 1MB (256 * 4096)
unsigned char *shared_buffer;

unsigned char ReadByte(unsigned char *buffer, unsigned int buffer_size, unsigned int untrusted_index) {
    if (untrusted_index < buffer_size) {
        _mm_lfence();
        unsigned char value = buffer[untrusted_index];
        return shared_buffer[value * 4096];
    }
}
```

### <a name="speculation-barrier-via-compiler-time-instrumentation"></a>Barreira de especulação por meio de instrumentação de tempo de compilador

O compilador do Microsoft C++ no Visual Studio 2017 (a partir da versão 15.5.5) inclui suporte para o `/Qspectre` comutador que insere automaticamente uma barreira de especulação para um conjunto limitado de padrões de codificação potencialmente vulneráveis relacionados ao CVE-2017-5753. A documentação do sinalizador [/Qspectre](https://docs.microsoft.com/cpp/build/reference/qspectre) fornece mais informações sobre seus efeitos e uso. É importante observar que esse sinalizador não cobre todos os padrões de codificação potencialmente vulneráveis e, como tal, os desenvolvedores não devem confiar nele como uma mitigação abrangente para essa classe de vulnerabilidades.

### <a name="masking-array-indices"></a>Mascarando índices de matriz

Nos casos em que pode ocorrer uma carga de limite restrito fora de limites, o índice de matriz pode ser rigidamente limitado no caminho de arquitetura e fora da arquitetura, adicionando lógica para associar explicitamente o índice de matriz. Por exemplo, se uma matriz puder ser alocada para um tamanho que esteja alinhado a uma potência de dois, uma máscara simples poderá ser introduzida. Isso é ilustrado no exemplo abaixo, onde supõe-se que `buffer_size` está alinhado a uma potência de dois. Isso garante que `untrusted_index` é sempre menor que `buffer_size` , mesmo se ocorrer uma previsão incorreta da ramificação condicional e se for `untrusted_index` passado com um valor maior ou igual a `buffer_size` .

Deve-se observar que a máscara de índice executada aqui pode estar sujeita ao bypass de armazenamento especulativo, dependendo do código gerado pelo compilador.

```cpp
// A pointer to a shared memory region of size 1MB (256 * 4096)
unsigned char *shared_buffer;

unsigned char ReadByte(unsigned char *buffer, unsigned int buffer_size, unsigned int untrusted_index) {
    if (untrusted_index < buffer_size) {
        untrusted_index &= (buffer_size - 1);
        unsigned char value = buffer[untrusted_index];
        return shared_buffer[value * 4096];
    }
}
```

### <a name="removing-sensitive-information-from-memory"></a>Removendo informações confidenciais da memória

Outra técnica que pode ser usada para mitigar vulnerabilidades de canal lateral de execução especulativa é remover informações confidenciais da memória. Os desenvolvedores de software podem procurar oportunidades para refatorar seus aplicativos de modo que as informações confidenciais não sejam acessíveis durante a execução especulativa. Isso pode ser feito Refatorando o design de um aplicativo para isolar informações confidenciais em processos separados. Por exemplo, um aplicativo de navegador da Web pode tentar isolar os dados associados a cada origem da Web em processos separados, evitando assim que um processo seja capaz de acessar dados entre origens por meio de execução especulativa.

## <a name="see-also"></a>Confira também

[Diretrizes para atenuar as vulnerabilidades de canal lateral de execução especulativa](https://portal.msrc.microsoft.com/security-guidance/advisory/ADV180002)<br/>
[Atenuando vulnerabilidades de hardware de canal lateral de execução especulativa](https://blogs.technet.microsoft.com/srd/2018/03/15/mitigating-speculative-execution-side-channel-hardware-vulnerabilities/)
