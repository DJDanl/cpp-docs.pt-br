---
title: Diretrizes para desenvolvedores de C++ para canais do lado de execução especulativa
ms.date: 07/10/2018
helpviewer_keywords:
- Visual C++, security
- security [C++]
- security [C++], best practices
- Spectre
- CVE-2017-5753
- Speculative Execution
ms.openlocfilehash: 94e55f08e4ff427aef0c93bf74c711a6fd935d0a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50631005"
---
# <a name="c-developer-guidance-for-speculative-execution-side-channels"></a>Diretrizes para desenvolvedores de C++ para canais do lado de execução especulativa

Este artigo contém diretrizes para desenvolvedores para ajudá-lo a identificar e atenuar a execução especulativa lado canal hardware as vulnerabilidades no software de C++. Essas vulnerabilidades podem revelar informações confidenciais entre limites de confiança e podem afetar o software que é executado em processadores que dão suporte à execução especulativa, fora de ordem de instruções. Essa classe de vulnerabilidades foi primeiro descrito em janeiro de 2018 e plano de fundo adicional e diretrizes que podem ser encontradas no [comunicado de segurança da Microsoft](https://portal.msrc.microsoft.com/security-guidance/advisory/ADV180002).

A orientação fornecida por este artigo está relacionada às classes de vulnerabilidades representadas por:

1. CVE-2017-5753, também conhecido como variante Spectre 1. Essa classe de vulnerabilidade de hardware está relacionado aos canais de lado que podem surgir devido a execução especulativa que ocorre como resultado um misprediction ramificação condicional. O compilador do Visual C++ no Visual Studio 2017 (começando com a versão 15.5.5) inclui suporte para o `/Qspectre` switch que fornece uma redução do tempo de compilação para um conjunto limitado de padrões de codificação potencialmente vulnerável relacionados para CVE 2017-5753. O `/Qspectre` comutador também está disponível no Visual Studio 2015 atualização 3 por meio [4338871 KB](https://support.microsoft.com/help/4338871). A documentação para o [/Qspectre](https://docs.microsoft.com/cpp/build/reference/qspectre) sinalizador fornece mais informações sobre o seu uso e efeitos.

2. CVE-2018-3639, também conhecido como [especulativa Store Bypass (SSB)](https://aka.ms/sescsrdssb). Essa classe de vulnerabilidade de hardware está relacionado aos canais de lado que podem surgir devido à execução especulativa de uma carga à frente de um repositório dependente como resultado um misprediction de acesso de memória.

Uma introdução acessível à vulnerabilidades de canal lateral de execução especulativa pode ser encontrada na apresentação intitulada [caso do Spectre e Meltdown](https://www.youtube.com/watch?v=_4O0zMW-Zu4) por uma das equipes de pesquisa que esses problemas descobertos.

## <a name="what-are-speculative-execution-side-channel-hardware-vulnerabilities"></a>O que são vulnerabilidades de hardware especulativo execução lado canal?

CPUs modernas fornecem níveis mais altos de desempenho, fazendo uso de execução especulativa e fora de ordem de instruções. Por exemplo, isso geralmente é feito ao prever o destino de ramificações (condicionais e indiretos) que permite que a CPU começar a forma especulativa executar instruções em que o destino da ramificação previstos, evitando uma vaga de até que seja o destino da ramificação real resolvido. No caso em que a CPU mais tarde descobre que um misprediction ocorreu, todos os estados de máquina que foi calculado de forma especulativa é descartado. Isso garante que não há nenhum efeitos visíveis em termos de arquitetura da especulação mispredicted.

Durante a execução especulativa não afeta o estado visível em termos de arquitetura, ele pode deixar rastreamentos residuais em estado não-arquitetura, como os vários caches que são usados pela CPU. Ele é esses rastreamentos residuais de execução especulativa que pode dar origem a vulnerabilidades de canal lateral. Para entender isso melhor, considere o seguinte fragmento de código que fornece um exemplo de CVE-2017-5753 (Bypass verificar limites):

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

Neste exemplo, `ReadByte` é fornecido um buffer, um tamanho de buffer e um índice nesse buffer. O parâmetro de índice, conforme especificado pelo `untrusted_index`, é fornecido por um menor contexto privilegiado, como um processo não administrativas. Se `untrusted_index` é menor que `buffer_size`, em seguida, o caractere daquele índice é lido a partir `buffer` e é usado para o índice em uma região compartilhada de memória referenciada por `shared_buffer`.

De uma perspectiva arquitetônica, esta sequência de código é segura perfeitamente como que é garantido que ele `untrusted_index` sempre será menor que `buffer_size`. No entanto, na presença de execução especulativa, é possível que a CPU previsão a ramificação condicional e executar o corpo da se instrução mesmo quando `untrusted_index` é maior que ou igual a `buffer_size`. Como consequência disso, a CPU forma especulativa pode ler um byte fora dos limites da `buffer` (que poderia ser um segredo) e, em seguida, poderia usar esse valor de byte para calcular o endereço de uma carga subsequente por meio de `shared_buffer`.

Enquanto a CPU será, eventualmente, detectar esse misprediction, efeito colateral residual poderão ser deixados no cache da CPU que revelam informações sobre o valor de byte foi lido fora dos limites de `buffer`. Esses efeitos colaterais podem ser detectados por um menor contexto privilegiado, em execução no sistema, a rapidez de investigação de cada cache de linha no `shared_buffer` é acessado. As etapas que podem ser executadas para realizar isso são:

1. **Invocar `ReadByte` várias vezes com `untrusted_index` sendo menor que `buffer_size`** . O contexto de ataque pode fazer com que o contexto da vítima invocar `ReadByte` (por exemplo, via RPC), de modo que o indicador de ramificação é treinado para não ser-considerado `untrusted_index` é menor que `buffer_size`.

2. **Liberar todas as linhas de cache no `shared_buffer`** . O contexto de ataque deve liberar todas as linhas de cache na região compartilhada de memória referenciada por `shared_buffer`. Como a região de memória for compartilhada, isso é simples e não pode ser feito usando intrínsecos, como `_mm_clflush`.

3. **Invocar `ReadByte` com `untrusted_index` que é maior que `buffer_size`** . O contexto de ataque faz com que o contexto da vítima invocar `ReadByte` , de modo que prevê incorretamente que a ramificação não será executada. Isso faz com que o processador de forma especulativa, executar o corpo da se bloquear com `untrusted_index` que é maior que `buffer_size`, portanto, à esquerda para uma leitura fora dos limites de `buffer`. Consequentemente, `shared_buffer` é indexado usando um valor possivelmente secreto que foi lido de fora dos limites, fazendo com que a linha do respectivo cache a ser carregado pela CPU.

4. **Leia cada linha de cache no `shared_buffer` para ver o que é acessado mais rapidamente**. O contexto de ataque pode ler cada linha de cache no `shared_buffer` e detectar a linha de cache que carrega, significativamente mais rápido do que os outros. Esta é a linha de cache que provavelmente foi levou a etapa 3. Já que há uma relação de 1:1 entre a linha de cache e o valor de byte neste exemplo, isso permite que o invasor inferir o valor real do byte que foi lido de fora dos limites.

As etapas acima fornecem um exemplo de como usar uma técnica conhecida como FLUSH + RECARREGAR em conjunto com a exploração de uma instância de CVE 2017-5753.

## <a name="what-software-scenarios-can-be-impacted"></a>Quais cenários de software podem ser afetados?

Desenvolvimento de software seguro usando um processo, como o [Security Development Lifecycle](https://www.microsoft.com/sdl/) (SDL) normalmente exige que os desenvolvedores identificar os limites de confiança que existem em seus aplicativos. Existe um limite de confiança em lugares onde um aplicativo pode interagir com dados fornecidos por um contexto de menos confiáveis, como outro processo no sistema ou um processo de modo de usuário não administrativo no caso de um driver de dispositivo de modo kernel. A nova classe de vulnerabilidades que envolvem os canais do lado de execução especulativa é relevante para muitos dos limites de confiança nos modelos de segurança de software existentes que isolar o código e os dados em um dispositivo.

A tabela a seguir fornece um resumo dos modelos de segurança de software em que os desenvolvedores podem precisar se preocupar com essas vulnerabilidades ocorrendo:

|Limite de confiança|Descrição|
|----------------|----------------|
|Limites de máquina virtual|Aplicativos que isolar as cargas de trabalho em máquinas virtuais separadas que recebem dados não confiáveis de outra máquina virtual podem estar em risco.|
|Limite de kernel|Um driver de dispositivo de modo kernel que recebe dados não confiáveis de um processo do modo de usuário não administrativo pode estar em risco.|
|Limite de processo|Um aplicativo que recebe dados não confiáveis de outro processo em execução no sistema local, como por meio de um procedimento remoto (RPC), memória compartilhada ou outra comunicação entre processos (IPC) mecanismos podem estar em risco.|
|Limite de enclave|Um aplicativo que é executado dentro de um enclave seguro (como Intel SGX) que recebe dados não confiáveis de fora o enclave pode estar em risco.|
|Limites de linguagem|Um aplicativo que interpreta ou (JIT) just-in-compila e executa o código não confiável, escrito em uma linguagem de nível mais alto pode estar em risco.|

Aplicativos que têm a superfície de ataque exposta a qualquer um dos itens acima dos limites devem examinar o código na superfície de ataque para identificar e atenuar possíveis ocorrências de vulnerabilidades de canal lateral de execução especulativa de confiança. Deve-se observar que os limites de confiança expostos a superfícies de ataque remoto, tais como protocolos de rede remota, não foram demonstrados fiquem em risco a vulnerabilidades de canal lateral de execução especulativa.

## <a name="potentially-vulnerable-coding-patterns"></a>Padrões de codificação potencialmente vulnerável

Vulnerabilidades de canal lateral de execução especulativa podem surgir como consequência de vários padrões de codificação. Esta seção descreve os padrões de codificação potencialmente vulneráveis e fornece exemplos para cada um, mas devem ser reconhecido que variações esses temas podem existir. Dessa forma, os desenvolvedores são aconselhados a levar esses padrões como exemplos e não como uma lista completa de todos os padrões de codificação potencialmente vulneráveis. As mesmas classes de vulnerabilidades de segurança de memória que podem existir no software hoje em dia também podem existir ao longo de especulativo e os caminhos de fora de ordem de execução, incluindo mas não limitado a estouros de buffer, acessos, o uso de memória não inicializada, o tipo de matriz fora dos limites confusão e assim por diante. Os mesmos primitivos do que os invasores podem usar para explorar vulnerabilidades de segurança de memória ao longo de caminhos de arquiteturas também podem ser aplicáveis aos caminhos especulativos.

Em geral, misprediction de ramificação relacionados a condicional a execução especulativa lado canais pode surgir quando uma expressão condicional opera em dados que podem ser controlados ou influenciados por um contexto de menos confiáveis. Por exemplo, isso pode incluir expressões condicionais usadas na `if`, `for`, `while`, `switch`, ou instruções ternárias. Para cada uma dessas instruções, o compilador pode gerar uma ramificação condicional que a CPU, em seguida, pode prever o destino da ramificação para em tempo de execução.

Para cada exemplo, um comentário com a frase "BARREIRA de ESPECULAÇÃO" é inserido em que um desenvolvedor poderia introduzir uma barreira como uma mitigação. Isso é discutido mais detalhadamente na seção reduções.

## <a name="speculative-out-of-bounds-load"></a>Especulativo fora dos limites de carga

Essa categoria de padrões de codificação envolve um misprediction branch condicional que leva a um especulativa fora dos limites acesso à memória.

### <a name="array-out-of-bounds-load-feeding-a-load"></a>Alimentando uma carga de carga de matriz fora dos limites

Esse padrão de codificação é o padrão de codificação vulnerável originalmente descrito para CVE-2017-5753 (Bypass verificar limites). A seção de plano de fundo deste artigo explica esse padrão em detalhes.

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

Da mesma forma, uma matriz fora dos limites a carga pode ocorrer em conjunto com um loop que excede seu encerramento condição devido a um misprediction. Neste exemplo, a ramificação condicional associado com o `x < buffer_size` expressão pode de previsão e forma especulativa executa o corpo do `for` quando um loop `x` é maior que ou igual a `buffer_size`, portanto, resultando em um especulativo fora dos limites de carga.

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

### <a name="array-out-of-bounds-load-feeding-an-indirect-branch"></a>Matriz fora dos limites de carga alimentando uma ramificação indireta

Esse padrão de codificação envolve o caso em que um misprediction ramificação condicional pode levar a um fora dos limites acesso a uma matriz de ponteiros de função que, em seguida, leva a uma ramificação indireta para o destino de endereço que foi lido fora dos limites. O trecho a seguir fornece um exemplo que demonstra isso.

Neste exemplo, um identificador de mensagem não confiáveis é fornecido para DispatchMessage por meio de `untrusted_message_id` parâmetro. Se `untrusted_message_id` é menor que `MAX_MESSAGE_ID`, em seguida, ele é usado para indexar uma matriz de ponteiros de função e ramificar para o destino de ramificação correspondente. Esse código é seguro em termos de arquitetura, mas se a CPU previsões incorretas de branch condicional, ela pode resultar na `DispatchTable` estão sendo indexados pelo `untrusted_message_id` quando seu valor é maior que ou igual a `MAX_MESSAGE_ID`, gerando, portanto, um acesso fora dos limites. Isso pode resultar na execução especulativa de um endereço de destino de ramificação que é derivada além dos limites da matriz que pode levar à divulgação de informações dependendo do código que é executado de forma especulativa.

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

Como no caso de uma matriz fora dos limites de carga alimentando carga outro, essa condição também pode surgir em conjunto com um loop que excede sua condição de terminação devido a um misprediction.

### <a name="array-out-of-bounds-store-feeding-an-indirect-branch"></a>Matriz fora dos limites armazenar alimentando uma ramificação indireta

Embora o exemplo anterior mostrou como um especulativa fora dos limites carga pode influenciar a um destino de ramificação indireta, também é possível que um repositório fora dos limites para modificar um destino de ramificação indireta, como um ponteiro de função ou um endereço de retorno. Isso pode levar à execução especulativa de um endereço especificado pelo invasor.

Neste exemplo, um índice não confiável é passado por meio de `untrusted_index` parâmetro. Se `untrusted_index` é menor que a contagem de elemento do `pointers` array (256 elementos), em seguida, o valor de ponteiro fornecido na `ptr` é gravado o `pointers` matriz. Esse código é seguro em termos de arquitetura, mas se a CPU previsões incorretas de branch condicional, ela pode resultar na `ptr` que estão sendo gravados de forma especulativa além dos limites de alocados a pilha `pointers` matriz. Isso pode levar à corrupção especulativa do endereço para devolução para `WriteSlot`. Se um invasor pode controlar o valor de `ptr`, poderão causar a execução especulativa de um arbitrário de endereços quando `WriteSlot` retorna ao longo do caminho especulativo.

```cpp
unsigned char WriteSlot(unsigned int untrusted_index, void *ptr) {
    void *pointers[256];
    if (untrusted_index < 256) {
        // SPECULATION BARRIER
        pointers[untrusted_index] = ptr;
    }
}
```

Da mesma forma, se uma variável local de ponteiro de função chamada `func` foram alocados na pilha, em seguida, talvez seja possível de forma especulativa, modifique o endereço que `func` refere-se a quando ocorre o misprediction ramificação condicional. Isso pode resultar na execução especulativa de um endereço arbitrário quando o ponteiro de função é chamado por meio do.

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

Observe que ambos os exemplos envolvem modificação especulativa de ponteiros de branch indireta alocada na pilha. É possível que a modificação especulativa também pode ocorrer para variáveis globais, a memória alocada no heap e até mesma memória somente leitura em algumas CPUs. Para a memória alocada na pilha, o compilador do Visual C++ já toma medidas para tornar mais difícil modificar forma especulativa destinos de ramificação indireta alocada na pilha, como a reordenação de variáveis locais, de modo que os buffers serão colocadas adjacentes para um cookie de segurança como parte dos [/GS](https://docs.microsoft.com/cpp/build/reference/gs-buffer-security-check) recurso de segurança do compilador.

## <a name="speculative-type-confusion"></a>Confusão de tipo especulativo

Esta categoria lida com os padrões que podem dar origem a uma confusão especulativa tipo de codificação. Isso ocorre quando a memória é acessada por meio de um tipo incorreto ao longo de um caminho não arquitetura durante a execução especulativa. Misprediction ramificação condicional e repositório especulativa bypass potencialmente podem gerar confusão um tipo especulativa.

Para ignorar store especulativa, isso pode ocorrer em cenários em que um compilador reutiliza um local da pilha para variáveis de vários tipos. Isso ocorre porque o repositório de arquitetura de uma variável do tipo `A` pode ser ignorado, permitindo assim que a carga do tipo `A` para executar de forma especulativa antes que a variável é atribuída. Se a variável armazenada anteriormente é de um tipo diferente, isso pode criar as condições para uma confusão de tipo especulativa.

Para misprediction ramificação condicional, o trecho de código a seguir será usado para descrever a enfrentar condições diferentes que pode dar a confusão de tipo especulativa.

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

### <a name="speculative-type-confusion-leading-to-an-out-of-bounds-load"></a>Confusão de tipo especulativa, levando a um fora dos limites de carga

Esse padrão de codificação envolve o caso em que uma confusão de tipo especulativa pode resultar em um fora dos limites ou acesso confundido por tipo de campo em que o valor carregado feeds de um endereço de carregamento subsequente. Isso é semelhante ao padrão de codificação fora dos limites de matriz, mas ela é manifestada por meio de uma alternativa a sequência de codificação, como mostrado acima. Neste exemplo, um contexto de ataque pode fazer com que o contexto da vítima para executar `ProcessType` várias vezes com um objeto do tipo `CType1` (`type` campo é igual a `Type1`). Isso terá o efeito de treinar a ramificação condicional para o primeiro `if` instrução não prever feito. O contexto de ataque pode fazer com que o contexto da vítima para executar `ProcessType` com um objeto do tipo `CType2`. Isso pode resultar em uma confusão de tipo especulativa se condicional ramificar para a primeira `if` previsões incorretas de instrução e executa o corpo do `if` instrução, portanto, um objeto do tipo de conversão `CType2` para `CType1`. Uma vez que `CType2` é menor do que `CType1`, o acesso de memória para `CType1::field2` resultam em um especulativa fora dos limites carregará de dados que podem ser secretos. Esse valor é usado em uma carga de `shared_buffer` que pode criar um efeito colateral observável, assim como acontece com a matriz fora dos limites exemplo descrito anteriormente.

### <a name="speculative-type-confusion-leading-to-an-indirect-branch"></a>Confusão de tipo especulativa levando a uma ramificação indireta

Esse padrão de codificação envolve o caso em que uma confusão de tipo especulativa pode resultar em uma ramificação indireta não segura durante a execução especulativa. Neste exemplo, um contexto de ataque pode fazer com que o contexto da vítima para executar `ProcessType` várias vezes com um objeto do tipo `CType2` (`type` campo é igual a `Type2`). Isso terá o efeito de treinar a ramificação condicional para o primeiro `if` instrução a ser executada e o `else if` instrução, a não ser executada. O contexto de ataque pode fazer com que o contexto da vítima para executar `ProcessType` com um objeto do tipo `CType1`. Isso pode resultar em uma confusão de tipo especulativa se condicional ramificar para a primeira `if` prevê a instrução executada e o `else if` prevê a instrução não é feito, em execução, portanto, o corpo do `else if` e conversão de um objeto do tipo `CType1` para `CType2`. Uma vez que o `CType2::dispatch_routine` campo se sobrepõe a `char` matriz `CType1::field1`, isso pode resultar em uma ramificação indireta especulativa a um destino de ramificação não intencionais. Se o contexto de ataque pode controlar os valores de byte no `CType1::field1` matriz, eles podem ser capazes de controlar o endereço de destino de ramificação.

## <a name="speculative-uninitialized-use"></a>Especulativo uso não inicializado

Essa categoria de padrões de codificação envolve a cenários em que a execução especulativa pode acessar a memória não inicializada e usá-lo para alimentar uma carga subsequente ou ramificação indireta. Para esses padrões de codificação a ser explorada, um invasor precisa ser capaz de controlar ou influenciar significativamente o conteúdo da memória que é usado sem ser inicializado pelo que está sendo usado no contexto.

### <a name="speculative-uninitialized-use-leading-to-an-out-of-bounds-load"></a>Especulativo uso não inicializado, levando a um fora dos limites de carga

Um uso não inicializado especulativo potencialmente pode levar a um fora dos limites de carga usando um valor controlado pelo invasor. No exemplo a seguir, o valor de `index` é atribuída `trusted_index` em todos os caminhos de arquiteturas e `trusted_index` deve para ser menor ou igual a `buffer_size`. No entanto, dependendo do código produzido pelo compilador, é possível que um repositório especulativa bypass pode ocorrer que permite que a carga de `buffer[index]` e as expressões dependentes executado à frente da atribuição a `index`. Se isso ocorrer, um valor não inicializado para `index` será usado como o deslocamento na `buffer` que permite que um invasor leia informações confidenciais fora dos limites e transmitir isso por meio de um canal de lado por meio de carregamento dependente de `shared_buffer` .

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

### <a name="speculative-uninitialized-use-leading-to-an-indirect-branch"></a>Especulativo uso não inicializado, levando a uma ramificação indireta

Um uso não inicializado especulativo potencialmente pode levar a uma ramificação indireta em que o destino da ramificação é controlado por um invasor. No exemplo a seguir, `routine` for atribuído a uma `DefaultMessageRoutine1` ou `DefaultMessageRoutine` dependendo do valor de `mode`. No caminho de arquitetura, isso resultará em `routine` que está sendo inicializado sempre à frente na ramificação indireta. No entanto, dependendo do código produzido pelo compilador, um repositório especulativa bypass pode ocorrer que permite que a ramificação indireta por meio `routine` a ser executado de forma especulativa à frente da atribuição a `routine`. Se isso ocorrer, um invasor pode ser capaz de executar de forma especulativa de um endereço arbitrário, supondo que o invasor pode influenciar ou controlar o valor não inicializado do `routine`.

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

## <a name="mitigation-options"></a>Opções de atenuação

Vulnerabilidades de canal lateral de execução especulativa podem ser minimizadas, tornando as alterações ao código-fonte. Essas alterações podem envolver a redução de instâncias específicas de uma vulnerabilidade, como com a adição de um *barreira de especulação*, ou fazendo alterações no design de um aplicativo para tornar informações confidenciais inacessível para especulativo execução.

### <a name="speculation-barrier-via-manual-instrumentation"></a>Barreira de especulação por meio da instrumentação manual

Um *barreira de especulação* podem ser inseridos manualmente por um desenvolvedor para impedir a execução especulativa continuação ao longo de um caminho não arquitetura. Por exemplo, um desenvolvedor pode inserir uma barreira de especulação antes de um padrão de codificação perigoso no corpo de um bloco condicional, no início do bloco (após a ramificação condicional) ou antes da primeira carga é uma preocupação. Isso impedirá que um misprediction ramificação condicional da execução do código de perigoso em um caminho não arquitetura serializando a execução. A sequência de barreira de especulação difere pela arquitetura de hardware, conforme descrito pela tabela a seguir:

|Arquitetura|Barreira de especulação intrínseca para CVE 2017-5753|Barreira de especulação intrínseca para CVE-2018-3639|
|----------------|----------------|----------------|
|x86/x64|_mm_lfence()|_mm_lfence()|
|ARM|não disponível atualmente|__dsb(0)|
|ARM64|não disponível atualmente|__dsb(0)|

Por exemplo, o padrão de código a seguir pode ser abrandado utilizando o `_mm_lfence` intrínseco, conforme mostrado abaixo.

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

### <a name="speculation-barrier-via-compiler-time-instrumentation"></a>Barreira de especulação por meio da instrumentação de tempo do compilador

O compilador do Visual C++ no Visual Studio 2017 (começando com a versão 15.5.5) inclui suporte para o `/Qspectre` switch que automaticamente insere uma barreira de especulação para um conjunto limitado de padrões de codificação potencialmente vulnerável relacionados para CVE 2017-5753. A documentação para o [/Qspectre](https://docs.microsoft.com/cpp/build/reference/qspectre) sinalizador fornece mais informações sobre o seu uso e efeitos. É importante observar que esse sinalizador não abrange todos os padrões de codificação potencialmente vulneráveis e como tal, os desenvolvedores não devem confiar nele como uma mitigação abrangente para esta classe de vulnerabilidades.

### <a name="masking-array-indices"></a>Índices da matriz de mascaramento

Em casos onde um especulativa fora dos limites de carga podem ocorrer, o índice de matriz pode ser fortemente limitado no caminho não arquitetônicas e de arquitetura, adicionando a lógica para associado explicitamente o índice de matriz. Por exemplo, se uma matriz pode ser alocada para um tamanho que está alinhado a uma potência de dois, em seguida, uma máscara simple pode ser introduzida. Isso é ilustrado no exemplo a seguir em que ele é presumido que `buffer_size` está alinhado a uma potência de dois. Isso garante que `untrusted_index` é sempre menor que `buffer_size`, mesmo se ocorre um misprediction ramificação condicional e `untrusted_index` foi transmitido com um valor maior que ou igual a `buffer_size`.

Deve-se observar que o mascaramento de índice executado aqui pode estar sujeitos a bypass de repositório especulativa dependendo do código gerado pelo compilador.

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

### <a name="removing-sensitive-information-from-memory"></a>Remover informações confidenciais da memória

Outra técnica que pode ser usada para atenuar as vulnerabilidades de canal lateral de execução especulativa é remover informações confidenciais da memória. Os desenvolvedores de software podem buscar oportunidades para refatorar seu aplicativo, de modo que informações confidenciais não estão acessíveis durante a execução especulativa. Isso pode ser feito pela refatoração o design de um aplicativo para isolar as informações confidenciais em processos separados. Por exemplo, um aplicativo de navegador da web pode tentar isolar os dados associados a cada origem da web em processos separados, evitando que um processo que está sendo capaz de acessar os dados entre origens por meio de execução especulativa.

## <a name="see-also"></a>Consulte também

[Orientações para atenuar as vulnerabilidades de canal lateral de execução especulativa](https://portal.msrc.microsoft.com/security-guidance/advisory/ADV180002)<br/>
[Atenuar as vulnerabilidades de execução especulativa lado canal hardware](https://blogs.technet.microsoft.com/srd/2018/03/15/mitigating-speculative-execution-side-channel-hardware-vulnerabilities/)
